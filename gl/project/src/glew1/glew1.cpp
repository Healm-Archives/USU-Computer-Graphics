// vid2 
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include <string>

#include "util.h"

int main(void)
{
	GLFWwindow* window;
	
	/* Initialize the library */
	if (!glfwInit()) {
		return -1;
	}

	/* Create a windowed mode window and its OpenGL context */
	// window = glfwCreateWindow(1000, 1000, "Hello World", NULL, NULL);
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);	
	if (!window)
	{
		glfwTerminate();
		return -1;
	}
		
	// /* Make the window's context current */
	glfwMakeContextCurrent(window);
		
	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	if (err != GLEW_OK) {
		return -1;
	}
	glGetError();

	float vertices[6] = {
		0.5f, 0.5f,
		-0.5f, -0.5f,
		0.5f, -0.5f
	};

	unsigned int vertexBuffer = 0;
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6, vertices, GL_STATIC_DRAW);
	// std::cout << vertexBuffer;

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

	// string vertexString = readFile("vertex.vert");
	// string fragmentString = readFile("fragment.frag");
	string vertexString = readFile("src/glew1/vertex.vert");
	string fragmentString = readFile("src/glew1/fragment.frag");
	// cout << vertexString.size() << endl;
	
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	const char* vertexChar = vertexString.c_str();
	const char* fragmentChar = fragmentString.c_str();

	glShaderSource(vertexShader, 1, &vertexChar, NULL);
	glShaderSource(fragmentShader, 1, &fragmentChar, NULL);

	glCompileShader(vertexShader);
	glCompileShader(fragmentShader);

	unsigned int program = glCreateProgram();
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);
	glLinkProgram(program);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);
		
		
		// glBegin(GL_TRIANGLES);
		// glColor3f(0.1, 0.2, 0.3);
		// glVertex3f(-1, 0, 0);
		// glVertex3f(1, 0, 0);
		// glVertex3f(0, 1, 0);
		// glEnd();

		glUseProgram(program);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
