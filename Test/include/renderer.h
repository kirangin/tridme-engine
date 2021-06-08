#ifndef _RENDERER_H_
#define _RENDERER_H_
#include <engine.h>

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
};

#endif
