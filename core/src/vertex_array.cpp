#include <vertex_array.h>
#include <vertex_buffer_layout.h>
#include <renderer.h>

namespace Tridme {
  VertexArray::VertexArray() {
    GLCall(glGenVertexArrays(1, &m_renderer_id));
  }

  VertexArray::~VertexArray() {
    GLCall(glDeleteVertexArrays(1, &m_renderer_id));
  }

  void VertexArray::AddBuffer(const VertexBuffer &vb, const VertexBufferLayout &layout) {
    Bind();
    vb.Bind();
    const auto& elements = layout.GetElements();
    
    for (unsigned int i = 0; i < elements.size(); i++) {
      const auto& element = elements[i];
      GLCall(glEnableVertexAttribArray(i));
      GLCall(glVertexAttribPointer(i, element.count, element.type, element.normalized, sizeof(vertex), (void*) element.offset));
    }
  }

  void VertexArray::Bind() const {
    GLCall(glBindVertexArray(m_renderer_id));
  }

  void VertexArray::Unbind() const {
    GLCall(glBindVertexArray(0));
  }
}