#include <string>

class GLFWwindow;
class Config;

namespace TKStudio {

class Application {
public:
  // Load all dependencies
  Application(int width = 1920, int height = 1080,
              const std::string& title = "TKStudio");

  // Free up used memories
  ~Application();

  void run();

private:
  GLFWwindow* m_window;
};
} // namespace TKStudio
