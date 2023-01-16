#pragma once
#include "GameObject.hpp"

class Ball : public GameObject
{
public:
    using GameObject::GameObject;
    
    GLfloat moveSpeed;
    void move(float x, float y);
};