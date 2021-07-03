#include <shader.h>
#include <iostream>
#include <extern/glad/glad.h>
#include <fstream>
#include <sstream>
#include <string>
#include <extern/glm/gtc/type_ptr.hpp>

Shader::Shader(const std::string& filepath)
  : m_filepath(filepath),
    m_renderer_id(0) {
  ShaderProgramSource src = ParseShader(filepath);
  m_renderer_id = CreateShader(src.VertexShader, src.FragmentShader);
}

Shader::~Shader() {
  glDeleteProgram(m_renderer_id);
}

void Shader::Bind() const {
  glUseProgram(m_renderer_id);
}

void Shader::Unbind() {
  glUseProgram(0);
}

void Shader::SetUniform4f(const std::string &name, float v0, float v1, float v2, float v3) {
  glUniform4f(GetUniformLocation(name), v0, v1, v2, v3);
}

void Shader::SetUniform1i(const std::string &name, int value) {
  glUniform1i(GetUniformLocation(name), value);
}

void Shader::SetUniform1f(const std::string &name, float value) {
  glUniform1f(GetUniformLocation(name), value);
}

void Shader::SetUniformMat4f(const std::string &name, const glm::mat4 &matrix) { 
  glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &matrix[0][0]);
}

void Shader::SetUniformMat4fv(const std::string &name, const glm::mat4 &matrix) { 
  glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, glm::value_ptr(matrix));
}

unsigned int Shader::GetUniformLocation(const std::string &name) {
  if (m_uniform_location_cache.find(name) != m_uniform_location_cache.end())
    return m_uniform_location_cache[name];
 
  int location = glGetUniformLocation(m_renderer_id, name.c_str());
  if (location == -1) {
    std::cout << "Warning: uniform " << name << " doesn't exist!"  << std::endl;
  }
  
  m_uniform_location_cache[name];
  return location;
}

int Shader::CreateShader(const std::string &vertexShader, const std::string &fragmentShader) {
  unsigned int shaderProgram = glCreateProgram();

  unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
  unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

  glAttachShader(shaderProgram, vs);
  glAttachShader(shaderProgram, fs);
  glLinkProgram(shaderProgram);
  glValidateProgram(shaderProgram);

  glDeleteShader(vs);
  glDeleteShader(fs);

  return shaderProgram;
}

ShaderProgramSource Shader::ParseShader(const std::string &filepath) {
  std::fstream stream(filepath);
  
  enum ShaderType {
    NONE = -1, VERTEX = 0, FRAGMENT = 1
  };

  std::string line;
  std::stringstream ss[2];
  ShaderType type = ShaderType::NONE;

  while (getline(stream, line)) {
    if (line.find("#type") != std::string::npos) {
      if (line.find("vertex") != std::string::npos)
        type = ShaderType::VERTEX;
      else if (line.find("fragment") != std::string::npos)
        type = ShaderType::FRAGMENT;
    } else {
      ss[(int) type] << line << '\n';
    }
  }

  return { ss[0].str(), ss[1].str() };
}

unsigned int Shader::CompileShader(unsigned int type, const std::string &source) {
  unsigned int shader;
  shader = glCreateShader(type);
  const char* src = source.c_str();

  glShaderSource(shader, 1, &src, nullptr);
  glCompileShader(shader);

  int result;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
  if (result == GL_FALSE) {
    int len;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);
    char* msg = (char*) alloca(len * sizeof(char));
    glGetShaderInfoLog(shader, len, &len, msg);
    
    std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << std::endl; 
    std::cout << msg << std::endl;

    glDeleteShader(shader);
    return 0;
  }

  return shader;
}