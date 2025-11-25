#include <iostream>

#include "GUI.h"

GUI::GUI() : window_name("vehicle dynamics simulator by oddy") {

  window_w = DEFAULT_WINDOW_W;
  window_h = DEFAULT_WINDOW_H;

  _init_SDL();
}

GUI::~GUI() {
  SDL_DestroyWindow(_main_window);
  SDL_GL_DestroyContext(gl_context);
  SDL_Quit();
}

bool GUI::are_windows_closed() {

  SDL_Event event;

  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_EVENT_QUIT) {
      return true;
    }
  }

  return false;
}

void GUI::swap_buffer() { SDL_GL_SwapWindow(_main_window); }

int GUI::_init_SDL() {

  SDL_Init(SDL_INIT_VIDEO);

  _main_window =
      SDL_CreateWindow(window_name, window_w, window_h, SDL_WINDOW_OPENGL);

  if (_main_window == NULL) {
    // In the case that the window could not be made...
    SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n",
                 SDL_GetError());
    return 1;
  }

  if (NULL == (gl_context = SDL_GL_CreateContext(_main_window)))
    std::cout << "Failed to create OpenGL context \n";
  else
    SDL_GL_MakeCurrent(_main_window, gl_context);

  return 0;
}
