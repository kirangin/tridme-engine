#ifndef _INDEX_BUFFER_H
#define _INDEX_BUFFER_H
#include "mesh.h"

class IndexBuffer {
  private:
    unsigned int m_renderer_id;
    unsigned int m_count;

  public:
  	IndexBuffer();
    IndexBuffer(const unsigned int* data, unsigned int count);
    ~IndexBuffer();


    void CreateFromVector(std::vector<unsigned int> &indices);
    void Create(const unsigned int* data, unsigned int count);
    void Bind() const;
    void Unbind() const;

    inline unsigned int GetCount() const { return m_count; }
};

#endif 