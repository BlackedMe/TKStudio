#include "glad/gl.h"
#include <string>

namespace TKStudio {

GLuint compileProgram(const std::string& pathToVShader,
                      const std::string& pathToFShader);
}
