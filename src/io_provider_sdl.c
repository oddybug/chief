#include "io_provider.h"

#include <SDL3/SDL.h>

void *get_gl_proc_addr(const char *name) {
  return (void *)SDL_GL_GetProcAddress(name);
}

