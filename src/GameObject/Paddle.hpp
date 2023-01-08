#pragma once
#include "GameObject.hpp"

class Paddle : public GameObject
{
public:
    Paddle() {}
    Paddle(glm::vec2 position, glm::vec2 scale)
    {
        mPosition = position;
        mScale = scale;
        mMovementSpeed = 1.0f;
    }

    float mMovementSpeed;
};