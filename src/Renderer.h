#ifndef RENDERER_H
#define RENDERER_H

class Renderer {
  public:
  Renderer();
  Renderer(Renderer &&) = default;
  Renderer(const Renderer &) = default;
  Renderer &operator=(Renderer &&) = default;
  Renderer &operator=(const Renderer &) = default;
  ~Renderer() = default;

  void clear_buffer();

private:
};

#endif
