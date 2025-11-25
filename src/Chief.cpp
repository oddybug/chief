#include "Chief.h"

#include "extern.cpp"
GUI* gui;
Renderer* renderer;

Chief::Chief() {
  gui = new GUI();
  renderer = new Renderer();
  main_loop();
}

Chief::~Chief(){
  delete gui;
  delete renderer;
}

void Chief::main_loop() {
  while (!gui->are_windows_closed()) {
    renderer->clear_buffer();
    gui->swap_buffer();
  }
}
