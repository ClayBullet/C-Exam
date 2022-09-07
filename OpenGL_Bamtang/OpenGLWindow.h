#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#pragma once
class OpenGLWindow
{
private:
	/// <summary>
	/// Vertex Array Object
	/// </summary>
	GLuint VAO;
	/// <summary>
	/// Vertex buffer
	/// </summary>
	GLuint VBO;

	/// <summary>
	/// Index buffer
	/// </summary>
	GLuint EBO;

	GLuint shaderProgram;
public:

	GLFWwindow* currentWindow;

	OpenGLWindow();

	void InitWindow();

	void TickWindow();

	void DestroyWindow();

	void DisplayWindow();

	bool windowIsOpen();

	bool windowIsNull();

	//Vertex Shader Source Code
		const char* vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\0";
	//Fragment Shader source code
	const char* fragmentShaderSource = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
		"}\n\0";

};

