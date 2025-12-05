#ifndef OBJECT_H
#define OBJECT_H

//temporary
#include <Shader.h>

class Object {
public:
  Object() = default;
  Object(Object &&) = default;
  Object(const Object &) = default;
  Object &operator=(Object &&) = default;
  Object &operator=(const Object &) = default;
  ~Object() = default;

  //temporary
  static Object generate_cube(Shader s);

  // temporary
  unsigned int *_VAO;
  unsigned int  *posVBO, *normVBO;
private:
};

// Primitives

#endif // !Object
