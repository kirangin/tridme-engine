#ifndef MESH_RENDERER_H
#define MESH_RENDERER_H
#include <vector>
#include <Nodes/Camera.h>
#include <System/Renderer/Renderer.h>
#include <System/Renderer/Texture.h>
#include <System/Renderer/Shader.h>
#include <System/Renderer/Mesh.h>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Tridme {
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
	};
}

#endif