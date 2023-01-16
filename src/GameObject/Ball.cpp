#include "Ball.hpp"

void Ball::move(float x, float y)
{
    mPosition.x += x * mMovementSpeed;
    mPosition.y += y * mMovementSpeed;
}