#include "Renderer.hpp"

void Renderer::prepareTriangle()
{
    float vertices[] = {
         0.5f,  0.5f, 0.0f,  // top right
         0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
        -0.5f,  0.5f, 0.0f   // top left 
    };

    unsigned int indices[] = {
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };

    #ifdef DEBUG
    printf("preparing triangles...\n");
    #endif

    glGenVertexArrays(1, &mVAO);
    
    glBindVertexArray(mVAO);

    GLuint VBO, EBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);

    #ifdef DEBUG
    printf("preparing triangles finished.\n");
    #endif
}

void Renderer::prepareShaders()
{
    Shader * shader = new Shader("src/Graphics/vertex.vsh","src/Graphics/fragment.fsh");
    shaderProgram = shader->id;
    delete shader;
}

void Renderer::draw()
{
    glUseProgram(shaderProgram);
    glBindVertexArray(mVAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}