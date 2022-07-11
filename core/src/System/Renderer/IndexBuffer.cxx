#include <System/Renderer/IndexBuffer.h>
#include <System/Renderer/Renderer.h>

namespace Tridme {
  IndexBuffer::IndexBuffer() {
    GLCall(glGenBuffers(1, &m_renderer_id));
  }

  IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count)
  :m_count(count) {

    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_renderer_id));
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), data, GL_STATIC_DRAW));
  }

  IndexBuffer::~IndexBuffer() {
    GLCall(glDeleteBuffers(1, &m_renderer_id));
  }

  void IndexBuffer::CreateFromVector(std::vector<unsigned int> &indices) {
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_renderer_id));
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indices.size(), &indices[0], GL_STATIC_DRAW));
  }

  void IndexBuffer::Create(const unsigned int* data, unsigned int count) {
    m_count = count;

    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_renderer_id));
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), data, GL_STATIC_DRAW));
  }

  void IndexBuffer::Bind() const {
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_renderer_id));
  }

  void IndexBuffer::Unbind() const {
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
  }
}