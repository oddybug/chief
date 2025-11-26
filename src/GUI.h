#ifndef GUI_H
#define GUI_H

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#define DEFAULT_WINDOW_W 800
#define DEFAULT_WINDOW_H 600

class GUI {
public:
  GUI();
  GUI(GUI &&) = default;
  GUI(const GUI &) = default;
  GUI &operator=(GUI &&) = default;
  GUI &operator=(const GUI &) = default;
  ~GUI();

  const char *window_name;
  unsigned int window_w;
  unsigned int window_h;

  /**
   * @brief returns boolean depending on the number of windows openned
   *
   * @return true for all windows closed and false for negation
   */
  bool are_windows_closed();

  void swap_buffer();

  SDL_GLContext gl_context;

private:
  int _init_SDL();

  SDL_Window *_main_window;
};

#endif
