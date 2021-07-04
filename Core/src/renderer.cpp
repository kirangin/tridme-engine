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

	m_vb.CreateFromVector(vertices, vertices.size() * sizeof(float));
	m_ib.CreateFromVector(indices, indices.size() * sizeof(float));

	VertexBufferLayout m_layout;
	m_layout.Push(GL_FLOAT, 3);
	m_layout.Push(GL_FLOAT, 3);

	m_va.AddBuffer(m_vb, m_layout);

	m_va.Unbind();
	m_vb.Unbind();
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

	/* View */
	glm::mat4 view = camera->getViewMatrix();
	m_shader->SetUniformMat4fv("view", view);

	/* Projection */
	glm::mat4 projection = camera->getProjectionMatrix();
	m_shader->SetUniformMat4fv("projection", projection);

	m_va.Bind();
	m_ib.Bind();
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);

	m_va.Unbind();
	m_ib.Unbind();
	m_shader->Unbind();
}

void Renderer::Draw(const VertexArray &va, const IndexBuffer &ib, const Shader& shader) const {
  shader.Bind();
  va.Bind();
  ib.Bind();
  glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr);
}