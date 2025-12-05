#ifndef SCENE_H
#define SCENE_H

#include "Object.h"
#include <vector>

#include <Shader.h>

class Scene {
public:
  Scene();
  Scene(Scene &&) = default;
  Scene(const Scene &) = default;
  Scene &operator=(Scene &&) = default;
  Scene &operator=(const Scene &) = default;
  ~Scene() = default;

  void add_object(Object *object);

  void draw();

  Shader* _shader;
private:

  std::vector<Object*> _objects;
};

#endif // !SCENE_H
