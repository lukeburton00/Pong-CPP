#include "Renderer.hpp"

void Renderer::prepareTriangle()
{
    float vertices[] = {
         0.1f,  0.1f, 0.0f,  // top right
         0.1f, -0.1f, 0.0f,  // bottom right
        -0.1f, -0.1f, 0.0f,  // bottom left
        -0.1f,  0.1f, 0.0f   // top left 
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
    shader = std::make_shared<Shader>("src/Graphics/vertex.vert","src/Graphics/fragment.frag");
}

void Renderer::transform(float x, float y)
{
    glm::mat4 transform = glm::mat4(1.0f);
    transform = glm::translate(transform, glm::vec3(x, y, 0.0f));

    glm::vec4 color(1.0f, 1.0f,1.0f,1.0f);

    shader->setMat4("transform", transform);
    shader->setVec4("inColor", color);
}

void Renderer::draw(float dt, float x, float y)
{
    shader->use();
    transform(x,y);
    glBindVertexArray(mVAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}