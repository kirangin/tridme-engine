#include <texture.h>
#include <stbi/stb_image.h>

Texture::Texture(const std::string &path)
  : m_filepath(path),
    m_local_buffer(nullptr),
    m_width(0),
    m_height(0),
    m_bpp(0) {
  /* Load image */
  stbi_set_flip_vertically_on_load(1);
  m_local_buffer = stbi_load(path.c_str(), &m_width, &m_height, &m_bpp, 4);

  GLCall(glGenTextures(1, &m_renderer_id));
  GLCall(glBindTexture(GL_TEXTURE_2D, m_renderer_id));

  GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
  GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
  GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
  GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));

  GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_local_buffer));
  
  glGenerateMipmap(GL_TEXTURE_2D);

  GLCall(glBindTexture(GL_TEXTURE_2D, 0));

  if (m_local_buffer)
    stbi_image_free(m_local_buffer);
}

Texture::~Texture() {
  GLCall(glDeleteTextures(1, &m_renderer_id));
}

void Texture::Bind(unsigned int slot) const {
  GLCall(glActiveTexture(GL_TEXTURE0 + slot));
  GLCall(glBindTexture(GL_TEXTURE_2D, m_renderer_id));
}

void Texture::Unbind() const {
  GLCall(glBindTexture(GL_TEXTURE_2D, 0));
}