#ifndef CHIEF_H
#define CHIEF_H

#include "Scene.h"
#include "Object.h"
class Chief {
public:
  Chief();

  Chief(const Chief &);
  Chief &operator=(Chief &&);
  Chief &operator=(const Chief &);
  ~Chief();

private:
  void main_loop();
  Scene _scene;
};

#endif // !CHIEF_H
