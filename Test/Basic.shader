#type vertex
#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 textureCoords;

uniform mat4 vp;
uniform mat4 model;

out vec2 tc;

void main() {
  gl_Position = vp * model * vec4(aPos, 1.0);
  tc          = textureCoords;
}

#type fragment
#version 330 core
in vec2 tc;
out vec4 FragCol;

uniform sampler2D Texture;

uniform vec3 lightColor;

void main() {
  // float ambientStrength = 0.5;
  // vec3 ambient = ambientStrength * lightColor;
  // vec3 result  = ambient * outColor;
  // FragCol = vec4(result, 1.0);

  FragCol = texture(Texture, tc);
}