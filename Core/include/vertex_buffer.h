#ifndef _VERTEX_BUFFER_H
#define _VERTEX_BUFFER_H

#include <mesh.h>
#include <error.h>

class VertexBuffer {
  private:
    unsigned int m_renderer_id;

  public:
  	VertexBuffer();
    VertexBuffer(const void* data, unsigned int size);
    ~VertexBuffer();

    void CreateFromVector(std::vector<vertex> &vertices);
    void Create(const void* data, unsigned int size);
    void Bind() const;
    void Unbind() const;
};

#endif 