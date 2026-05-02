#include "GLFW/glfw3.h"
#include <cmath>
using namespace std;
void drawClock()
{
    glEnable(GL_LINE_SMOOTH);
    // glClear(GL_COLOR_BUFFER_BIT);

    // glBegin(GL_TRIANGLES);
    // glColor3f(0.1, 0.2, 0.3);
    // glVertex3f(-1, 0, 0);
    // glVertex3f(1, 0, 0);
    // glVertex3f(0, 1, 0);
    // glEnd();

    glColor3f(0.8, 0, 0);
    glLineWidth(10);
    // glBegin(GL_LINE_LOOP);
    glBegin(GL_LINES);
    // glBegin(GL_POLYGON);
    
    
    // nonagon
    double i;
    long double phi = acos(-1);
    // double phi = acos(-1);
    // for (i = 0; i<=360 ;i+0){
    //     // glVertex2f(sin(phi * i / 180) * 0.5, cos(phi * i / 180) * 0.5);
    //     glVertex2f(sin(phi * i / 180) * 0.02, cos(phi * i / 180) * 0.02);
    //     i +=1;
    // }
    for (i = 0; i<=90 ;i+0){
        glVertex2f(sin(phi * i / 180) * 0.5, cos(phi * i / 180) * 0.5);
        // glVertex2f(sin(phi * i / 180) * 0.2, cos(phi * i / 180) * 0.2);
        i +=0.2;
    }
    i = 90;
    // glVertex2f(sin(phi * i / 180) * 0.4, cos(phi * i / 180) * 0.4);
    // i = 0;
    // glColor3f(1,1,1);

    // for (i = i; i>=0 ;i-0){
    //     // glVertex2f(sin(phi * i / 180) * 0.5, cos(phi * i / 180) * 0.5);
    //     glVertex2f(sin(phi * i / 180) * 0.45, cos(phi * i / 180) * 0.45);
    //     i -=0.5;
    // }
    
    i=0;
    // glVertex2f(sin(phi * i / 180) * 0.5, cos(phi * i / 180) * 0.5);
    // glVertex2f(0,0);
    glEnd();
    
    // glLineWidth(10);
    // glColor3f(0.8, 0, 0);
    // double x, y, z;
    // for (x = 0; x < 1; x + 0)
    // {
    //     glBegin(GL_LINES);
    //     glVertex2f(0.1 + x, 0.1);
    //     glVertex2f(0.1 + x, -0.1);
    //     x += 0.1;
    // }
    // glEnd();

    // glBegin(GL_POLYGON);

    //     glVertex2f(-0.1, 0.2);
    //     glVertex2f(-0.1, 0);
    //     glVertex2f(0.1, 0);
    //     glVertex2f(0.1, 0.2);

    //     glColor3f(0,0,0);
    //     glVertex2f(0.2, 0.2);
    //     glVertex2f(0.2, -0.2);
    //     glVertex2f(-0.2, -0.2);
    //     glVertex2f(-0.2, 0.2);
    // glEnd();
}

int main(void)
{
    GLFWwindow *window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1000, 1000, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

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