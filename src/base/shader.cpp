#include "base/shader.h"
#include "base/parser.h"
#include "glad/gl.h"
#include <iostream>
#include <string>

namespace TKStudio {

GLuint compileShader(GLenum shaderType, const std::string& pathToShader)
{
  GLuint shader = glCreateShader(shaderType);

  std::string parsed = parseFromFile(pathToShader);
  const char* shaderSource = parsed.c_str();

  glShaderSource(shader, 1, &shaderSource, 0);
  glCompileShader(shader);

  GLint compileStatus;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &compileStatus);

  if (compileStatus == GL_FALSE) {
    GLsizei logLength = 0;
    GLchar log[1024];
    glGetShaderInfoLog(shader, 1024, &logLength, log);
    std::cerr << log << '\n';
    return 0;
  }
  return shader;
}
} // namespace TKStudio
