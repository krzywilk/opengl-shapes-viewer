#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <iostream>
#include <glad/glad.h>
#include "src/PredefinedWindows/HelloWindow.h"
#include <vector>
#include "src/utils/simples.cpp"
#include "src/ShapeDrawers/BasicShapesDrawers/TrianglesDrawer.h"
#include "src/ShapeDrawers/BasicShapesDrawers/ShapesDrawer.h"
#include "src/Textures/Loaders/TexturesDirLoader.h"
#include "src/ShapeDrawers/Textures/TexturedShapeDrawer.h"
#include<array> 
#include "src/ShapeDrawers/Textures/TransformableTextureShapeShader.h"
#include "src/ShapeDrawers/BasicShapesDrawers/TransformableShapeShader.h"


namespace
{
    void init_GLFW(int glfw_version_major = 4, int glfw_version_minor = 4) {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, glfw_version_major);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, glfw_version_minor);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    }
}

static int main3d() {
    init_GLFW();
    CameraViewProcessor camera = CameraViewProcessor(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    HelloWindow basicWindowTest = HelloWindow(&camera, "Separate impl", 800, 600, rgb(0.3f, 0.1f, 0.1f));
    TexturesDirLoader simpleTextureLoader("static_files/textures/", GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    simpleTextureLoader.loadTextures();
    string texture2load[] = { "container.jpg", "awesomeface.png" };
    unsigned int textureIds[2];
    unsigned int current_idx = 0;
    for (string name : texture2load) {
        textureIds[current_idx] = simpleTextureLoader.getTextureId(&name);
        current_idx++;
    }
    rgb black(0.0f, 0.0f, 0.0f);
    rgb white(1.0f, 1.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    float vertices[] = {
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 1.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 0.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f, 0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f, 1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f, 1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f, 1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f, 0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f, 0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f, 1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f, 1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f, 0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f, 0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f, 1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f, 1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f, 1.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f, 0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f, 0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f, 0.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f, 1.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f, 0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f, 1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f, 1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f, 1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f, 0.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f, 0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f, 1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f, 1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f, 1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f, 0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f, 0.0f, 1.0f
    };

    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO = -1;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    //glGenBuffers(1, &EBO);


    unsigned int lightCubeVAO;
    glGenVertexArrays(1, &lightCubeVAO);


    TransformableShapeShader lightSourceDrawer("src/ShadersSourceCode/constant_color_shaders/transformation_vertex_shader.vs", "src/ShadersSourceCode/constant_color_shaders/fragment_shader.fs", VAO, VBO, EBO);
    glm::vec3 lightPos(1.2f, 1.0f, 2.0f);
    glm::vec4 lightColor(1.0f, 1.0f, 1.0f, 1.0f);
    lightSourceDrawer.setVec4("color", lightColor, true);


    TransformableShapeShader texturerRectangleDrawer("src/ShadersSourceCode/light_shaders/light_vertex_shader.vs", "src/ShadersSourceCode/light_shaders/light_fragment_shader.fs", lightCubeVAO, VBO, EBO);
    texturerRectangleDrawer.setVec3("objectColor", glm::vec3(1.0f, 0.5f, 0.31f), true);
    texturerRectangleDrawer.setVec3("lightColor", lightColor, true);
    texturerRectangleDrawer.setVec3("lightPos", lightPos, true);

    
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::mat4(1.0f);
    model = glm::translate(model, lightPos);
    model = glm::scale(model, glm::vec3(0.2f)); // a smaller cube
    lightSourceDrawer.setModelTransformation(&model);
    texturerRectangleDrawer.transferTriangles(vertices, sizeof(vertices), 3, 8);
    texturerRectangleDrawer.setVertexAttribPointer(0, 3, 0);
    texturerRectangleDrawer.setVertexAttribPointer(1, 3, 3);
    //texturerRectangleDrawer.setVertexAttribPointer(2, 2, 6);

    lightSourceDrawer.setCurrentAttribElemSize(texturerRectangleDrawer.getCurrentAttribElemSize());
    lightSourceDrawer.setTrianglesNumber(texturerRectangleDrawer.getTrianglesNumber());

    lightSourceDrawer.setVertexAttribPointer(0, 3, 0);

    

    vector<TransformableShapeShader*> triangleDrawers;
    triangleDrawers.push_back(&texturerRectangleDrawer);
    triangleDrawers.push_back(&lightSourceDrawer);

    basicWindowTest.cameraRenderLoop(triangleDrawers);
    glfwTerminate();
    return 0;
}
int main() {
    return main3d();
}


