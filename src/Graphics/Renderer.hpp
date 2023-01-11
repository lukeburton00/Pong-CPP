#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
#include <stdio.h>
#include "Shader.hpp"


class Renderer
{
public:
    void prepareTriangle();
    void prepareShaders();
    void draw();

private:
    GLuint mVAO;
    GLuint shaderProgram;
};