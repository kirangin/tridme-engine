#include <shader.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <glm/gtc/type_ptr.hpp>

namespace Tridme {
  Shader::Shader(const std::string& filepath)
    : m_filepath(filepath),
      m_renderer_id(0) {
    ShaderProgramSource src = ParseShader(filepath);
    m_renderer_id = CreateShader(src.VertexShader, src.FragmentShader);
  }

  Shader::~Shader() {
    GLCall(glDeleteProgram(m_renderer_id));
  }

  void Shader::Bind() const {
    GLCall(glUseProgram(m_renderer_id));
  }

  void Shader::Unbind() {
    GLCall(glUseProgram(0));
  }

  void Shader::SetUniform3f(const char* name, float v0, float v1, float v2) {
    GLCall(glUniform3f(glGetUniformLocation(m_renderer_id, name), v0, v1, v2));
  }

  void Shader::SetUniform3fv(const std::string &name, const glm::vec3 &val) {
    GLCall(glUniform3fv(GetUniformLocation(name), 1, glm::value_ptr(val)));
  }

  void Shader::SetUniform4f(const std::string &name, float v0, float v1, float v2, float v3) {
    GLCall(glUniform4f(GetUniformLocation(name), v0, v1, v2, v3));
  }

  void Shader::SetUniform1i(const std::string &name, int value) {
    GLCall(glUniform1i(GetUniformLocation(name), value));
  }

  void Shader::SetUniform1f(const std::string &name, float value) {
    GLCall(glUniform1f(GetUniformLocation(name), value));
  }

  void Shader::SetUniformMat4f(const std::string &name, const glm::mat4 &matrix) { 
    GLCall(glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &matrix[0][0]));
  }

  void Shader::SetUniformMat4fv(const std::string &name, const glm::mat4 &matrix) { 
    GLCall(glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, glm::value_ptr(matrix)));
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

    GLCall(glAttachShader(shaderProgram, vs));
    GLCall(glAttachShader(shaderProgram, fs));
    GLCall(glLinkProgram(shaderProgram));
    GLCall(glValidateProgram(shaderProgram));

    GLCall(glDeleteShader(vs));
    GLCall(glDeleteShader(fs));

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

    GLCall(glShaderSource(shader, 1, &src, nullptr));
    GLCall(glCompileShader(shader));

    int result;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE) {
      int len;
      GLCall(glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len));
      char* msg = (char*) alloca(len * sizeof(char));
      GLCall(glGetShaderInfoLog(shader, len, &len, msg));
      
      std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << std::endl; 
      std::cout << msg << std::endl;

      GLCall(glDeleteShader(shader));
      return 0;
    }

    return shader;
  }
}