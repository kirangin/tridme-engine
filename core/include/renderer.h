#ifndef _RENDERER_H_
#define _RENDERER_H_

#include <core.h>
#include <vertex_array.h>
#include <index_buffer.h>
#include <camera.h>
#include <shader.h>
#include <vertex_buffer_layout.h>
#include <error.h>

namespace Tridme {
	class Renderer {
		public:
			Renderer(MESH_TYPE type, Camera* camera, bool useTexture = false, bool useUniformColor = false);
			~Renderer();

			void SetPosition(glm::vec3 _position);
			void SetColor(glm::vec3 _color);
			void SetShader(Shader* shader);
			void SetTexture(GLuint _texture);
			void SetScale(glm::vec3 _scale);

			glm::vec3 GetColor();

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
			glm::vec3 position, color, scale;

			GLuint vbo, ebo, vao, program, texture;
			Shader* m_shader;


			VertexArray  m_va;
			VertexBuffer m_vb;
			IndexBuffer  m_ib;

			bool m_useTexture, m_useUniformColor;
	};
}

#endif
