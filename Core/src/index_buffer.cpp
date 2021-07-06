#include <index_buffer.h>
#include <renderer.h>

IndexBuffer::IndexBuffer() {

}

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count)
:m_count(count) {
  glGenBuffers(1, &m_renderer_id);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_renderer_id);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), data, GL_STATIC_DRAW);

}

IndexBuffer::~IndexBuffer() {
  glDeleteBuffers(1, &m_renderer_id);
}

void IndexBuffer::CreateFromVector(std::vector<unsigned int> &indices) {
	glGenBuffers(1, &m_renderer_id);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_renderer_id);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indices.size(), &indices[0], GL_STATIC_DRAW);
}

void IndexBuffer::Create(const unsigned int* data, unsigned int count) {
	m_count = count;

	glGenBuffers(1, &m_renderer_id);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_renderer_id);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), data, GL_STATIC_DRAW);
}

void IndexBuffer::Bind() const {
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_renderer_id);
}

void IndexBuffer::Unbind() const {
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}