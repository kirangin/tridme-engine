#include <System/Renderer/VertexBuffer.h>

namespace Tridme {
	VertexBuffer::VertexBuffer() {
		GLCall(glGenBuffers(1, &m_renderer_id));
	}

	VertexBuffer::VertexBuffer(const void* data, unsigned int size) {
		GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_renderer_id));
		GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
	}

	VertexBuffer::~VertexBuffer() {
		GLCall(glDeleteBuffers(1, &m_renderer_id));
	}

	void VertexBuffer::CreateFromVector(std::vector<vertex> &vertices) {
		GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_renderer_id));
		GLCall(glBufferData(GL_ARRAY_BUFFER, sizeof(vertex) * vertices.size(), &vertices[0], GL_STATIC_DRAW));
	}

	void VertexBuffer::Create(const void* data, unsigned int size) {
		GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
	}

	void VertexBuffer::Bind() const {
		GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_renderer_id));
	}

	void VertexBuffer::Unbind() const {
		GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
	}
}