#include "application.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "glad/gl.h"

namespace TKStudio {

Application::Application(int width, int height, const std::string& title)
{
  // Initialize GLFW
  if (!glfwInit())
    return;

  window = glfwCreateWindow(width, height, title.c_str(), 0, 0);

  if (!window) {
    glfwTerminate();
    return;
  }

  glfwMakeContextCurrent(window);

  // Initialize GLAD
  if (!gladLoadGL(glfwGetProcAddress))
    return;
}

Application::~Application() { glfwTerminate(); }

void Application::run()
{
  glfwMakeContextCurrent(window);

  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);

    glfwPollEvents();
  }
}
} // namespace TKStudio
