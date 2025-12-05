/**
 * @file
 * @brief This file contains all the set up, comunications and operations to
 * render things with OpenGL.
 */

#include <glad/glad.h>

#include <iomanip>
#include <iostream>

#include "Renderer.h"
#include "io_provider.h"

Renderer::Renderer() {

  std::cout << "hola\n";
  if (!gladLoadGLLoader((GLADloadproc)get_gl_proc_addr)) {
    throw(std::string("Failed to initialize GLAD"));
  } else {
    std::cout << "GLAD initialized successfully" << std::endl;
  }

  std::cout << std::setw(34) << std::left
            << "OpenGL Version: " << GLVersion.major << "." << GLVersion.minor
            << std::endl;
  std::cout << std::setw(34) << std::left << "OpenGL Shading Language Version: "
            << (char *)glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
  std::cout << std::setw(34) << std::left
            << "OpenGL Vendor:" << (char *)glGetString(GL_VENDOR) << std::endl;
  std::cout << std::setw(34) << std::left
            << "OpenGL Renderer:" << (char *)glGetString(GL_RENDERER)
            << std::endl;
}

void Renderer::clear_buffer() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  glEnable(GL_DEPTH_TEST);
  glClearColor(0.1f, 0.1f, 0.13f, 1.0f);
}

