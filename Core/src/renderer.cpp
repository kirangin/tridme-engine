#include <renderer.h>

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

	m_vb.CreateFromVector(vertices);
	m_va.Bind();
	m_ib.CreateFromVector(indices);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)0);
  glEnableVertexAttribArray(0);
  
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), 
                       (void*)(offsetof(vertex, vertex::color)));
  glEnableVertexAttribArray(1);  
  
	m_va.Unbind();
	m_ib.Unbind();
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

	/* View and Projection */
	glm::mat4 view = camera->getViewMatrix();
	glm::mat4 projection = camera->getProjectionMatrix();
	
	m_shader->SetUniformMat4fv("view", view);
	m_shader->SetUniformMat4fv("projection", projection);

	m_va.Bind();
	m_ib.Bind();
	GLCall(glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0));

	m_va.Unbind();
	m_ib.Unbind();
	m_shader->Unbind();
}

void Renderer::Draw(const VertexArray &va, const IndexBuffer &ib, const Shader& shader) const {
  shader.Bind();
  va.Bind();
  ib.Bind();
  GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
}