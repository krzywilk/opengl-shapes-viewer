#pragma once
#include "../ShaderDrawer.h"
class ColoredTrianglesDrawer :
    public ShaderDrawer
{

public:
    ColoredTrianglesDrawer(const char* vertexShaderPath, const char* fragmentShaderPath, unsigned int& VAO, unsigned int& VBO):
        ShaderDrawer(vertexShaderPath, fragmentShaderPath, VAO, VBO)
    {};
    int getTrianglesNumber() const {
        return trianglesNumber;
    };
    virtual void transferTriangles(float vertices[], int vertices_sizeof, int singleVerticleElemsNum, int singleVerticleDataElemsNum);
    virtual void drawShape(int shapeIdx);
    virtual void drawAllTriangles() {
        ColoredTrianglesDrawer::drawAllShapes();
    }
    virtual void drawAllShapes();
    void setColor(rgb shapeColor) {
        rgb shapeFillColor(shapeColor.r, shapeColor.g, shapeColor.b);
    }
};

