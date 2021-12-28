#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Snake;

namespace GameLoop
{
	void processGameInput(GLFWwindow* window, Snake& s);

	void start(GLFWwindow* window);
}