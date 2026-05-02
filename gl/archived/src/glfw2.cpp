
#include "GLEW/glew.h"
#include "GLFW/glfw3.h"
#include <cmath>
#include <iostream>
// using namespace std;
void prep()
{
    // glEnable(GL_LINE_SMOOTH);
    // glColor3f(5,5,5);
    GLenum err = glewInit();
    float vertices[8] = {
        0.1f,0.1f,
        -0.1f,0.1f,
        -0.1f,-0.1f,
        0.1f,-0.1f
    };

    unsigned int index[] = {
        0,1,2,
        1,2,3
    };

    unsigned int indexBuffer = 0;
    glGenBuffers(1, &indexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, indexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(unsigned int) * 6, index , GL_STATIC_DRAW);

}

void drawClock()
{
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
}

int main(void)
{
    GLFWwindow *window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
        std::cout << "Something effed up";
    }

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1000, 1000, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    prep();

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        drawClock();
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}