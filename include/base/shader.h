#include "glad/gl.h"
#include <string>

namespace TKStudio {

GLuint compileShader(GLenum shaderType, const std::string& pathToShader);
}
