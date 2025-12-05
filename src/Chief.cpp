#include "Chief.h"

#include "extern.cpp"
#include <iostream>

Renderer *renderer;
GUI *gui;

Chief::Chief() {
    std::cout << "hola" << std::endl;

  _scene = Scene();

  _scene.add_object(new Object(Object::generate_cube(*_scene._shader)));
  std::cout << "DEBUG" << std::endl;

  std::cout << "DEBUG" << std::endl;
  main_loop();
}

Chief::~Chief() {
  delete gui;
  delete renderer;
}

void Chief::main_loop() {
  while (!gui->are_windows_closed()) {
    renderer->clear_buffer();
    _scene.draw();
    gui->swap_buffer();
  }
}
