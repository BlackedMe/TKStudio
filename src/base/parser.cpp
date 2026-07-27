#include "base/parser.h"
#include <fstream>
#include <iostream>
#include <string>

namespace TKStudio {

std::string parseFromFile(const std::string& filePath)
{
  std::ifstream file;

  file.open(filePath);

  if (!file.is_open()) {
    std::cerr << "Failed to open file at " << filePath;
  }

  std::string parsed;
  std::string buffer;

  while (std::getline(file, buffer)) {
    parsed += (buffer + '\n');
  }

  file.close();

  return parsed;
}
} // namespace TKStudio
