#include <renderer.h>

// #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
// void GLClearError() {
//   while (glGetError() != GL_NO_ERROR);
// }

// bool GLogCall(const char* fnc, const char* file, int line) {
//   while (GLenum error = glGetError()) {
//     std::cout << "[ OpenGL Error ]: " << error << " " << fnc << " " << file << " " << line;
//     return false;
//   }

//   return true;
// }
// #endif

Renderer::Renderer(MESH_TYPE type, Camera* camera) {
	this->camera = camera;

	switch (type) {
		case MESH_TRIANGLE:
			Mesh::SetTriangleData(vertices, indices);
			break;
		case MESH_QUAD:
			Mesh::SetQuadData(vertices, indices);
			break;
		case MESH_CUBE:
			Mesh::SetCubeData(vertices, indices);
			break;
		case MESH_SPHERE:
			Mesh::SetSphereData(vertices, indices);
			break;
	}

	// this->vbo.CreateFromVector(vertices, sizeof(vertex) * vertices.size());
	// VertexBufferLayout layout;
	// layout.Push(GL_FLOAT, 3);
	// layout.Push(GL_FLOAT, 3);

	// this->vao.AddBuffer(vbo, layout);

	// this->ib.CreateFromVector(indices, sizeof(unsigned int) * indices.size());
	// this->vao.Unbind();

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex) * vertices.size(), &vertices[0], GL_STATIC_DRAW);

	//Attributes
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (GLvoid*)0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)(offsetof(vertex, vertex::color)));


	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * indices.size(), &indices[0], GL_STATIC_DRAW);

	
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

Renderer::~Renderer() {

}

void Renderer::SetPosition(glm::vec3 _position) {
	position = _position;
}

void Renderer::SetColor(glm::vec3 _color) {
	color = _color;
}

void Renderer::SetShader(Shader* shader) {
	m_shader = shader;
}

void Renderer::DrawMesh() {
	glm::mat4 model = glm::mat4(1.0f);
	
	m_shader->Bind();

	/* Model */
	model = glm::translate(glm::mat4(1.0f), position);
	m_shader->SetUniformMat4fv("model", model);

	/* View */
	glm::mat4 view = camera->getViewMatrix();
	m_shader->SetUniformMat4fv("view", view);

	/* Projection */
	glm::mat4 projection = camera->getProjectionMatrix();
	m_shader->SetUniformMat4fv("projection", projection);

	// this->vao.Bind();
	// glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);

	// this->vao.Unbind();

	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
	m_shader->Unbind();
}

void Renderer::Draw(const VertexArray &va, const IndexBuffer &ib, const Shader& shader) const {
  shader.Bind();
  va.Bind();
  ib.Bind();
  glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr);
}