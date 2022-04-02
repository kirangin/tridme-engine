#include <renderer.h>

namespace Tridme {
	Renderer::Renderer(MESH_TYPE type, Camera* camera, bool useTexture, bool useUniformColor) {
		this->camera = camera;
		this->scale  = glm::vec3(1.0f);

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

		m_va.Bind();
		m_vb.CreateFromVector(vertices);
		m_ib.CreateFromVector(indices);

		VertexBufferLayout m_layout;

		m_layout.Push(GL_FLOAT, 3, 0);
		m_layout.Push(GL_FLOAT, 3, (offsetof(vertex, vertex::normal)));

		if (useTexture) {
			m_layout.Push(GL_FLOAT, 2, (offsetof(vertex, vertex::texCoords)));

			m_useTexture = true;
		}

		m_va.AddBuffer(m_vb, m_layout);
		
		m_vb.Unbind();
		m_va.Unbind();
	}

	Renderer::~Renderer() {

	}

	void Renderer::SetPosition(glm::vec3 _position) {
		position = _position;
	}

	void Renderer::SetColor(glm::vec3 _color) {
		color = _color;

		m_useUniformColor = true;
	}

	void Renderer::SetShader(Shader* shader) {
		m_shader = shader;
	}

	void Renderer::SetTexture(GLuint _texture) {
		texture = _texture;
	}

	void Renderer::DrawMesh() {
		m_shader->Bind();

		m_shader->SetUniform3f("lightColor", 1.0f, 1.0f, 1.0f);

		/* Model */
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::scale(glm::translate(glm::mat4(1.0f), position), this->scale);
		m_shader->SetUniformMat4fv("model", model);

		/* View and Projection */
		glm::mat4 vp = camera->getProjectionMatrix() * camera->getViewMatrix();
		m_shader->SetUniformMat4fv("vp", vp);

		if (m_useTexture)
			glBindTexture(GL_TEXTURE_2D, texture);

		if (m_useUniformColor) {
			m_shader->SetUniform3f("outColor", this->color.x, this->color.y, this->color.z);
		}

		m_va.Bind();
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

	glm::vec3 Renderer::GetColor() {
		return this->color;
	}

	void Renderer::SetScale(glm::vec3 _scale) {
		this->scale = _scale;
	}
}