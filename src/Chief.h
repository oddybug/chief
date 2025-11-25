#ifndef CHIEF_H
#define CHIEF_H


class Chief {
public:
  Chief();
  Chief(Chief &&) = default;
  Chief(const Chief &) = default;
  Chief &operator=(Chief &&) = default;
  Chief &operator=(const Chief &) = default;
  ~Chief();

private:
  void main_loop();
};

#endif // !CHIEF_H
