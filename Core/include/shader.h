#ifndef _SHADER_H_
#define _SHADER_H_
#include <core.h>

struct ShaderProgramSource {
  std::string VertexShader;
  std::string FragmentShader;
};

class Shader {
  private:
    const std::string &m_filepath;
    unsigned int m_renderer_id;
    std::unordered_map<std::string, int> m_uniform_location_cache;

  public: 
    Shader(const std::string& filepath);
    ~Shader();

    void Bind() const;
    void Unbind();
    inline unsigned int GetId() { return m_renderer_id; }
    
    /* Set uniform */
    void SetUniform4f(const std::string &name, float v0, float v1, float v2, float v3);
    void SetUniform1i(const std::string &name, int value);
    void SetUniform1f(const std::string &name, float value);
    void SetUniformMat4f(const std::string &name, const glm::mat4 &matrix);
    void SetUniformMat4fv(const std::string &name, const glm::mat4 &matrix);

  private:
    ShaderProgramSource ParseShader(const std::string &filepath);
    unsigned int CompileShader(unsigned int type, const std::string &source);
    int CreateShader(const std::string &vertexShader, const std::string &fragmentShader);
    unsigned int GetUniformLocation(const std::string &name);
};

#endif 