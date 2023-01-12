#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Shader.hpp"

class GameObject
{
public:
    glm::vec3 mPosition;
    glm::vec3 mScale;
    glm::vec4 mColor;
    
    GameObject(){}
    GameObject(glm::vec3 position, glm::vec3 scale);

    void draw();


private:
    std::shared_ptr<Shader> mShader;
    GLuint mVAO;

};