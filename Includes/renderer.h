#ifndef _RENDERER_H_
#define _RENDERER_H_

#include <core.h>
#include <vertex_array.h>
#include <index_buffer.h>
#include <camera.h>
#include <shader.h>
#include <vertex_buffer_layout.h>
#include <error.h>

// #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
//   #define ASSERT(x) if (!(x)) __debugbreak();
//   #define GLCall(x) GLClearError();\
//     x;\
//     ASSERT(GLogCall(&x, __FILE__, __LINE__))

//   void GLClearError();
//   bool GLogCall(const char* fnc, const char* file, int line);
// #endif

class Renderer {
  public:
  	Renderer(MESH_TYPE type, Camera* camera);
  	~Renderer();

  	void SetPosition(glm::vec3 _position);
  	void SetColor(glm::vec3 _color);
  	void SetShader(Shader* shader);

  	/*
  	 * untuk menggambar bentuk yang disediakan di engine.
  	 */
  	void DrawMesh();

  	/*
  	 * sama aja, tapi bikin vertex array sendiri.
  	 */
    void Draw(const VertexArray &va, const IndexBuffer &ib, const Shader& shader) const;

  private:
   	Camera* camera;
   	std::vector<vertex> vertices;
   	std::vector<unsigned int> indices;
   	glm::vec3 position, color;

   	GLuint vbo, ebo, vao, program;
    Shader* m_shader;


		VertexArray m_va;
		VertexBuffer m_vb;
		IndexBuffer m_ib;
};

#endif
