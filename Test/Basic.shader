#type vertex
#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 outColor;

void main() {
  gl_Position = projection * view * model * vec4(aPos, 1.0);
  outColor = aColor;
}

#type fragment
#version 330 core
in vec3 outColor;
out vec4 FragCol;

void main() {
  FragCol = vec4(outColor, 1.0);
}