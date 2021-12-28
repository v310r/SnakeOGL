
#include "GameLoop.h"
#include "../engine/Renderer.h"
#include "../engine/Shader.h"

#include "Snake.h"
#include <chrono>

struct Offsets
{
	static glm::vec3 up;
	static glm::vec3 down;
	static glm::vec3 left;
	static glm::vec3 right;

};

glm::vec3 Offsets::up = glm::vec3(0.0f, 0.1f, 0.0f) ;
glm::vec3 Offsets::down = glm::vec3(0.0f, 0.1f, 0.0f);
glm::vec3 Offsets::left = glm::vec3(-0.1f, 0.0f, 0.0f);
glm::vec3 Offsets::right = glm::vec3(0.1f, 0.0f, 0.0f);

void GameLoop::processGameInput(GLFWwindow* window, Snake& s)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
	else if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS && s.getOffset() != Offsets::down)
		s.setOffset(glm::vec3(0.0f, 0.1f, 0.0f));
	else if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS && s.getOffset() != Offsets::up)
		s.setOffset(glm::vec3(0.0f, -0.1f, 0.0f));
	else if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS && s.getOffset() != Offsets::right)
		s.setOffset(glm::vec3(-0.1f, 0.0f, 0.0f));
	else if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS && s.getOffset() != Offsets::left)
		s.setOffset(glm::vec3(0.1f, 0.0f, 0.0f));
}

void GameLoop::start(GLFWwindow* window)
{
	Renderer world;
	Shader tailShader("src/shaders/snakePiece.vs", "src/shaders/tail.fs");
	Shader headShader("src/shaders/snakePiece.vs", "src/shaders/head.fs");

	Snake snake;
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	while (!glfwWindowShouldClose(window))
	{
		std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();



		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		int modelLoc = glGetUniformLocation(tailShader.getID(), "model");
		tailShader.use();
		for (const auto& piece : snake.getTail())
		{
			glm::mat4 snakeBody = glm::mat4(1.0f);
			snakeBody = glm::translate(snakeBody, piece);
			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(snakeBody));
			world.draw();
		}
		modelLoc = glGetUniformLocation(headShader.getID(), "model");
		glm::mat4 snakeBody = glm::mat4(1.0f);
		snakeBody = glm::translate(snakeBody, snake.getHead());
		headShader.use();
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(snakeBody));
		world.draw();

		if (std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() >= std::chrono::milliseconds(100).count())
		{
			begin = std::chrono::steady_clock::now();
			processGameInput(window, snake);
			snake.proceed();

		}

		//renderer.draw();

		glfwSwapBuffers(window);
		glfwPollEvents();

	}
}