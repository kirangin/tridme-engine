#include <vertex_buffer.h>

VertexBuffer::VertexBuffer() {
	glGenBuffers(1, &m_renderer_id);
}

VertexBuffer::VertexBuffer(const void* data, unsigned int size) {
	glGenBuffers(1, &m_renderer_id);
	glBindBuffer(GL_ARRAY_BUFFER, m_renderer_id);
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer() {
	glDeleteBuffers(1, &m_renderer_id);
}

void VertexBuffer::CreateFromVector(std::vector<vertex> &vertices) {
	glGenBuffers(1, &m_renderer_id);
	glBindBuffer(GL_ARRAY_BUFFER, m_renderer_id);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex) * vertices.size(), &vertices[0], GL_STATIC_DRAW);
}

void VertexBuffer::Create(const void* data, unsigned int size) {
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

void VertexBuffer::Bind() const {
	glBindBuffer(GL_ARRAY_BUFFER, m_renderer_id);
}

void VertexBuffer::Unbind() const {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}