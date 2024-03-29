#pragma once
#include "ShapesDrawer.h"



void ShapesDrawer::setupIndices(unsigned int* indices, int indices_sizeof)
{
    glBindVertexArray(VAO);
    if (EBO < 0) {
        glGenBuffers(GL_ELEMENT_ARRAY_BUFFER, &EBO);
    }
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices_sizeof, indices, GL_STATIC_DRAW);
}


void ShapesDrawer::drawShape(int shapeIdx) //TODO: rename
{
    glUseProgram(shaderProgramId);
    processCachedUniforms();
    glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, (void*)(3 * shapeIdx * sizeof(unsigned int)));
}

void ShapesDrawer::drawAllShapes() {
    glUseProgram(shaderProgramId);
    processCachedUniforms();
    glBindVertexArray(VAO); 
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glDrawElements(GL_TRIANGLES, trianglesNumber * 3, GL_UNSIGNED_INT, 0);
}