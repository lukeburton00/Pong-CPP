#include "GameObject.hpp"

GameObject::GameObject(glm::vec3 position, glm::vec3 scale)
{
    mPosition = position;
    mScale = scale;
    mColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
    
    mShader = std::make_shared<Shader>("/Users/luke/Desktop/Pong/src/Graphics/vertex.vert","/Users/luke/Desktop/Pong/src/Graphics/fragment.frag");
    float vertices[] = {
        1.0f,  1.0f, 0.0f,  // top right
        1.0f, -1.0f, 0.0f,  // bottom right
        -1.0f, -1.0f, 0.0f,  // bottom left
        -1.0f,  1.0f, 0.0f   // top left 
    };

    unsigned int indices[] = {
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };

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
}

void GameObject::draw(float worldX, float worldY)
{
    mShader->use();

    glm::mat4 model = glm::mat4(1.0f);
    
    model = glm::scale(model, mScale);
    model = glm::translate(model, glm::vec3(mPosition.x, mPosition.y, 0.0f));


    glm::mat4 view = glm::mat4(1.0f);

    glm::mat4 projection = glm::mat4(1.0f);
    projection = glm::ortho(-worldX, worldX, -worldY, worldY, -0.1f, 0.1f);

    mShader->setMat4("model", model);
    mShader->setMat4("view", view);
    mShader->setMat4("projection", projection);
    mShader->setVec4("inColor", mColor);

    glBindVertexArray(mVAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}