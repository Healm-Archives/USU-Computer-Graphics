
// // #include "GLFW/glfw3.h"
// // #include <iostream>
// // using namespace std;

// // int main()
// // {
// //     cout<<"A nondescript C++ program using the GLFW library, coded and built using VSCode"<<endl;
// //     cout<<"Initializing Graphics Library FramWork (GLFW)"<<endl;
    
// //     if(!glfwInit())
// //     {
// //         return -1;
// //     }

// //     auto gameWindow = glfwCreateWindow(640, 480, "GLFW Test App", NULL, NULL);
// //     if(!gameWindow)
// //     {
// //         glfwTerminate();
// //         return -1;
// //     }

// //     glfwMakeContextCurrent(gameWindow);

// //     // Application (Game) loop
// //     while(!glfwWindowShouldClose(gameWindow))
// //     {
// //         glClear(GL_COLOR_BUFFER_BIT);
// //         glfwSwapBuffers(gameWindow);
// //         glfwPollEvents();
// //     }

// //     glfwTerminate();    
// //     return 0;
// // }
// #include "GLFW/glfw3.h"

// int main(void)
// {
//     GLFWwindow* window;

//     /* Initialize the library */
//     if (!glfwInit())
//         return -1;

//     /* Create a windowed mode window and its OpenGL context */
//     window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
//     if (!window)
//     {
//         glfwTerminate();
//         return -1;
//     }

//     /* Make the window's context current */
//     glfwMakeContextCurrent(window);

//     /* Loop until the user closes the window */
//     while (!glfwWindowShouldClose(window))
//     {
//         /* Render here */
//         glClear(GL_COLOR_BUFFER_BIT); 
//         glBegin(GL_TRIANGLES);
//         glColor3f(0.1, 0.2, 0.3);
//         glVertex3f(-1, 0, 0);
//         glVertex3f(1, 0, 0);
//         glVertex3f(0, 1, 0);
//         glEnd();

//         /* Swap front and back buffers */
//         glfwSwapBuffers(window);

//         /* Poll for and process events */
//         glfwPollEvents();
//     }

//     glfwTerminate();
//     return 0;
// }

#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
using namespace std;
void drawH() {
    double height,width, heightI, widthI,  space, spaceI;
    height = 0.5;
    width = 0.4;  
    space = 0.2; 
    heightI = height * -1;
    widthI = width * -1;
    spaceI = space * -1;

    glBegin(GL_POLYGON);
    glColor3f(0.8, 0, 0);
    // nonagon
    double i, phi = acos(-1);
    for (i = 0; i<=360 ;i+0){
        glVertex2f(sin(phi * i / 180) * 0.5, cos(phi * i / 180) * 0.5);
        i +=1;
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.7, 0.1);
    // left
    glVertex2f(widthI, height);
    glVertex2f(widthI, heightI);
    glVertex2f(spaceI, heightI);
    glVertex2f(spaceI, height);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.7, 0.3);
    // mid
    glVertex2f(space, space/2);
    glVertex2f(space, spaceI/2);
    glVertex2f(spaceI, spaceI/2);
    glVertex2f(spaceI, space/2 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.9, 0.4);
    // right
    glVertex2f(width, height);
    glVertex2f(width, heightI);
    glVertex2f(space, heightI);
    glVertex2f(space, height);
    glEnd();

    glDrawArrays(NULL,0,360);
    // glColor3f(1,0,0);
    
    // glEnd;
}

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(900, 900, "Hello World", NULL, NULL);
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

        // Panggil fungsi untuk menggambar huruf "H"
        drawH();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}