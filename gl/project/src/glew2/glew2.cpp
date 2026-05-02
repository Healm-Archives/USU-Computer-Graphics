// vid3
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include <string>

#include "util.h"

int main(void)
{
	GLFWwindow* window;

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

	GLenum err = glewInit();
	float vertices[] = {
		-1, 1,
		-1, 0.8f,
		0.8f, 0.8f, 
		0.8f, 1,
		1, 1,
		1, -1,
		0.8f, -1,
		0.8f, -0.8f,
		-1, -0.8f,
		-1, -1

	};

	unsigned int index[] = {
		0, 1, 2, 
		0, 2, 3,
		3, 6, 5,
		3, 5, 4,
		8, 6, 7,
		8, 9, 6
	};

	unsigned int vertexBuffer = 0;
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	// glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 8, vertices, GL_STATIC_DRAW);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 20, vertices, GL_STATIC_DRAW);
	// std::cout << vertexBuffer;

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);


	unsigned int indexBuffer = 0;
	glGenBuffers(1, &indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	// glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(float) * 6, index, GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(float) * 18, index, GL_STATIC_DRAW);
	// std::cout << indexBuffer;

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(unsigned int) * 2, 0);

	// string vertexString = readFile("vertex.vert");
	// string fragmentString = readFile("fragment.frag");
	string vertexString = readFile("src/glew2/vertex.vert");
	string fragmentString = readFile("src/glew2/fragment.frag");


	// glCreateShader
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

		glUseProgram(program);
		// glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
		glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_INT, nullptr);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
