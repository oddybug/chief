
// temp
#include "glad/glad.h"

#include "Scene.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

Scene::Scene() {
  _shader = new Shader("basic shader", "../shaders/vertex.glsl",
                   "../shaders/fragment.glsl");
}

// temporary camera

glm::vec3 cameraPosition(10.0f, 10.0f, 10.0f);
glm::vec3 cameraTarget(0.0f, 0.0f, 0.0f);
glm::vec3 cameraUp(0.0f, 1.0f, 0.0f);

glm::mat4 view = glm::lookAt(cameraPosition, cameraTarget, cameraUp);

float fov = glm::radians(45.0f);
float aspectRatio = 800.0f / 600.0f;
float nearPlane = 0.1f;
float farPlane = 100.0f;

glm::mat4 projection = glm::perspective(fov, aspectRatio, nearPlane, farPlane);

// temp light
glm::vec3 lightDirection(-0.2f, -1.0f, -0.3f);
glm::vec3 lightColor(1.0f, 1.0f, 1.0f);
glm::vec3 objectColor(1.0f, 0.5f, 0.31f);

glm::mat4 model = glm::mat4(1.0f);
//////////////////

void Scene::draw() {
  _shader->use();

  // set tmp light

  // set temp camera

  _shader->setMat4("view", view);
  _shader->setMat4("projection", projection);
  _shader->setMat4("model", model);

  _shader->setVec3("light_direction", lightDirection);
  _shader->setVec3("light_color", lightColor);
  _shader->setVec3("object_color", objectColor);

  for (Object* object : _objects) {
    std::cout << "Drawing object with VAO: " << *object->_VAO << std::endl;
    glBindVertexArray(*object->_VAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
  }
}

void Scene::add_object(Object *object) { _objects.push_back(object); }
