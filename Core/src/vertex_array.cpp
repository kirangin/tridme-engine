#include <vertex_array.h>
#include <vertex_buffer_layout.h>
#include <renderer.h>

VertexArray::VertexArray() {
  glGenVertexArrays(1, &m_renderer_id);
}

VertexArray::~VertexArray() {
  glDeleteVertexArrays(1, &m_renderer_id);
}

void VertexArray::AddBuffer(const VertexBuffer &vb, const VertexBufferLayout &layout) {
  Bind();
  vb.Bind();
  const auto& elements = layout.GetElements();
  
  unsigned int offset = 0;
  for (unsigned int i = 0; i < elements.size(); i++) {
    const auto& element = elements[i];
    glEnableVertexAttribArray(i);
    glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStride(), (const void*) offset);
    offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
  }
}

void VertexArray::Bind() const {
  glBindVertexArray(m_renderer_id);
}

void VertexArray::Unbind() const {
  glBindVertexArray(0);
}