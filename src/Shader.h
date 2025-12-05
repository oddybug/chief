#ifndef SHADER_H
#define SHADER_H

#include <glm/glm.hpp>
#include <string>

class Shader {
private:
  std::string _name;

public:
  // the program ID
  unsigned ID;
  // constructor reads and builds the shader
  Shader(const char *name, const char *vertexPath, const char *fragmentPath);
  Shader(){};

  Shader &operator=(const Shader &x);

  // use/activate the shader
  void use();
  // utility uniform functions
  void setBool(const std::string &name, bool value) const;
  void setInt(const std::string &name, int value) const;
  void setFloat(const std::string &name, float value) const;
  void setVec2(const std::string &name, glm::vec2 value) const;
  void setVec3(const std::string &name, glm::vec3 value) const;
  void setMat4(const std::string &name, glm::mat4x4 &value) const;

  std::string getName() const;

  //temporary
  void draw_object();

};

#endif //! SHADER_H
