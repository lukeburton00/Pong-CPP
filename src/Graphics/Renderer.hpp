#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
#include <stdio.h>
#include "Shader.hpp"
#include "SDL2/SDL.h"


class Renderer
{
public:
    void prepareTriangle();
    void prepareShaders();
    void draw(float dt, float x, float y);
    void transform(float x, float y);

private:
    GLuint mVAO;
    std::shared_ptr<Shader> shader;
};