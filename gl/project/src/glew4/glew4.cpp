// vid3 --> vid 4
// rencanan utk glew5 
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include <string>
#include "util.h"

float color1[] = { 1.0f, 0.0f, 0.0f, 1.0f };
float color2[] = { 0.0f, 1.0f, 0.0f, 1.0f };

float velocitySecondPointer = -6;
float velocityMinutePointer = -1;
float velocityHourPointer = -0.00417f;

float currentSecondPointer = 270.0f;
float currentMinutePointer = 270.0f;
float currentHourPointer = 270.0f;

float currentTime = 0.0f;
float lastTime = 0.0f;
float deltaTime = 0.0f;

float speedUp = 100.0f;

unsigned int program;
GLint color1Loc, color2Loc;
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) 
{
	if (key == GLFW_KEY_E && action == GLFW_PRESS) 
	{
		std::cout << "E is pressed\n";
	}
	else if (key == GLFW_KEY_C && action == GLFW_PRESS)
	{
		for (int i = 0; i < 4; i++) 
		{
			color1[i] = (rand() * 1.0f) / RAND_MAX;
			color2[i] = (rand() * 1.0f) / RAND_MAX;
		}
		std::cout << color1[0] << " " << color1[1] << " " << color1[2] << " " << color1[3] << "\n";
		std::cout << color2[0] << " " << color2[1] << " " << color2[2] << " " << color2[3] << "\n";

		glProgramUniform4f(program, color1Loc, color1[0], color1[1], color1[2], color1[3]);
		glProgramUniform4f(program, color2Loc, color2[0], color2[1], color2[2], color2[3]);
	}
};

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

	glfwSetKeyCallback(window, keyCallback);

	GLenum err = glewInit();

	float vertices[] = {
		1.0f, 1.0f,
		-1.0f, -1.0f,
		1.0f, -1.0f,
		-1.0f, 1.0f
	};

	unsigned int index[] = {
		0, 1, 2, 
		0, 1, 3
	};

	unsigned int vertexBuffer = 0;
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 8, vertices, GL_STATIC_DRAW);
	// std::cout << vertexBuffer;

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);


	unsigned int indexBuffer = 0;
	glGenBuffers(1, &indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(float) * 6, index, GL_STATIC_DRAW);
	// std::cout << indexBuffer;

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(unsigned int) * 2, 0);

	// string vertexString = readFile("vertex.vert");
	// string fragmentString = readFile("fragment.frag");
	string vertexString = readFile("src/glew4/vertex.vert");
	string fragmentString = readFile("src/glew4/fragment.frag");


	// glCreateShader
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	const char* vertexChar = vertexString.c_str();
	const char* fragmentChar = fragmentString.c_str();

	glShaderSource(vertexShader, 1, &vertexChar, NULL);
	glShaderSource(fragmentShader, 1, &fragmentChar, NULL);

	glCompileShader(vertexShader);
	glCompileShader(fragmentShader);

	program = glCreateProgram();
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);

	glLinkProgram(program);


	GLint scaleLoc = glGetUniformLocation(program, "scale"); // harus persis sama dengan variabel yg diakses di file luar
	//glUseProgram(program);
	//glUniform1f(scaleLoc, 0.5f);
	//use that or this
	glProgramUniform1f(program, scaleLoc, 0.5f);

	/**/ 
	color1Loc = glGetUniformLocation(program, "color1");
	glProgramUniform4f(program, color1Loc, color1[0], color1[1], color1[2], color1[3]);

	color2Loc = glGetUniformLocation(program, "color2");
	glProgramUniform4f(program, color2Loc, color2[0], color2[1], color2[2], color2[3]);

	
	GLint currentSecondPointerLoc = glGetUniformLocation(program, "currentSecondPointer");
	GLint currentMinutePointerLoc = glGetUniformLocation(program, "currentMinutePointer");
	GLint currentHourPointerLoc = glGetUniformLocation(program, "currentHourPointer");

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		currentTime = glfwGetTime();
		deltaTime = (currentTime - lastTime) * speedUp;
		lastTime = currentTime; 

		currentSecondPointer = currentSecondPointer + (deltaTime * velocitySecondPointer);
		currentMinutePointer = currentMinutePointer + (deltaTime * velocityMinutePointer);
		currentHourPointer = currentHourPointer + (deltaTime * velocityHourPointer);
		
		glUniform1f(currentSecondPointerLoc, currentSecondPointer / 180.0f);
		glUniform1f(currentMinutePointerLoc, currentMinutePointer / 180.0f);
		glUniform1f(currentHourPointerLoc, currentHourPointer / 180.0f);
		
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(program);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
