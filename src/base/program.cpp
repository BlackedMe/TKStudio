#include "base/program.h"
#include "base/shader.h"
#include "glad/gl.h"
#include <iostream>
#include <string>

namespace TKStudio {

GLuint compileProgram(const std::string& pathToVShader,
                      const std::string& pathToFShader)
{
  GLuint program = glCreateProgram();

  GLuint vShader = compileShader(GL_VERTEX_SHADER, pathToVShader);
  GLuint fShader = compileShader(GL_FRAGMENT_SHADER, pathToFShader);

  glAttachShader(program, vShader);
  glAttachShader(program, fShader);
  glLinkProgram(program);

  GLint linkStatus;
  glGetProgramiv(program, GL_LINK_STATUS, &linkStatus);

  if (linkStatus == GL_FALSE) {
    GLsizei logLength = 0;
    GLchar log[1024];
    glGetProgramInfoLog(program, 1024, &logLength, log);
    std::cerr << log << '\n';
    return 0;
  }

  return program;
}
} // namespace TKStudio
