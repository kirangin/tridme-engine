#ifndef MESH_RENDERER_H
#define MESH_RENDERER_H
#include <renderer.h>
#include <camera.h>
#include <texture.h>
#include <shader.h>
#include <vector>
#include <mesh.h>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/glc/matrix_transform.hpp>


class MeshRenderer {
	public:
		MeshRenderer(MESH_TYPE type, Camera* _camera);
		~MeshRenderer();

		void SetPosition(glm::vec3 _postion);
		void SetScale(glm::vec3 _scale);
		void SetProgram(Shader* shader);
		void SetTexture(Texture* texture);

	private:
		Camera* camera;
		std::vector
};


#endif