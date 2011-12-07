#include "stdafx.h"

#include "Window.h"
#include "graphics/Graphics.h"

std::vector<IRender*> Graphics::things;
glm::mat4 Graphics::proj;
glm::mat4 Graphics::ortho;

void Graphics::Init() {
    glewInit(); 
    glClearDepth(1.0);
    glClearColor(0.5f, 0.7f, 0.9f, 1.0f);
    glEnable(GL_DEPTH_TEST);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CW);
    glCullFace(GL_BACK);

    SetProjection();
}

void Graphics::Shutdown() {
    things.clear();
}

void Graphics::SetProjection() {
    double aspect = Window::AspectRatio();
    proj = glm::perspective(80.0f, (float)aspect, 0.05f, 250.0f);
    ortho = glm::ortho(-aspect, aspect, -1.0, 1.0, 0.01, -0.01);
}

void Graphics::Render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    for (int i = 0; i < things.size(); i++) {
        things[i]->Render();
    }
}