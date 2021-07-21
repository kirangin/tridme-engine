#ifndef _VERTEX_BUFFER_LAYOUT_H_
#define _VERTEX_BUFFER_LAYOUT_H_
#include <vector>
#include <renderer.h>

struct VertexBufferElement {
  unsigned int type;
  unsigned int count;
  unsigned char normalized;
  int offset;

  static unsigned int GetSizeOfType(unsigned int type) {
    switch (type) {
      case GL_FLOAT:          return 4;
      case GL_UNSIGNED_INT:   return 4;
      case GL_UNSIGNED_BYTE:  return 1;
    }

    return 0;
  }
};

class VertexBufferLayout {
  private:
    std::vector<VertexBufferElement> m_elements;
    unsigned int m_stride;

  public:
    VertexBufferLayout()
    :m_stride(0) {

    }

    void Push(GLuint attribType, unsigned int count, int offset) {
      m_elements.push_back({attribType, count, GL_FALSE, offset});
      m_stride += count * VertexBufferElement::GetSizeOfType(GL_FLOAT);
    }
   
    inline const std::vector<VertexBufferElement> GetElements() const { return m_elements; }
    inline unsigned int GetStride() const { return m_stride; } 
};

// template<typename T> 
// void Push() {
//   static_assert(false);
// };

// template<>
// void Push<float>(unsigned int count) {
//   m_elements.push_back((GL_FLOAT, count, GL_FALSE));
//   m_stride += VertexBufferElement::GetSizeOfType(GL_FLOAT);
// };

// template<>
// void Push<unsigned int>(unsigned int count) {
//   m_elements.push_back((GL_UNSIGNED_INT, count, GL_FALSE));
//   m_stride += VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT);
// };

// template<>
// void Push<unsigned char>(unsigned int count) {
//   m_elements.push_back((GL_UNSIGNED_BYTE, count, GL_TRUE));
//   m_stride += VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE);
// };


#endif