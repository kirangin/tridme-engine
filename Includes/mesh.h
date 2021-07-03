#ifndef MESH_H
#define MESH_H

#include <core.h>

enum MESH_TYPE {
	MESH_TRIANGLE = 0,
	MESH_QUAD = 1,
	MESH_CUBE = 2, 
	MESH_SPHERE = 3
};

struct vertex {
	glm::vec3 pos;
	glm::vec3 normal;
	glm::vec3 color;
	glm::vec2 texCoords;
};


class Mesh {
	public:
		static void SetTriangleData(std::vector<vertex>& vertices, std::vector<unsigned int> &indices);
		static void SetQuadData(std::vector<vertex>& vertices, std::vector<unsigned int> &indices);
		static void SetCubeData(std::vector<vertex>& vertices, std::vector<unsigned int> &indices);
		static void SetSphereData(std::vector<vertex>& vertices, std::vector<unsigned int> &indices);
};

#endif