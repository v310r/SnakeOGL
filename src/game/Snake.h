#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <list>


class Snake
{
public:
	//Snake();

	//void setHead(const glm::vec3 nextAppearance);

	inline std::list<glm::vec3> getTail() { return tail; }

	inline glm::vec3 getHead() { return head; }

	void proceed();

	void setOffset(glm::vec3 nextDirection);

	const glm::vec3 getOffset()const;

private:
	std::list<glm::vec3> tail =
	{
		glm::vec3(0.1f, 0.0f, 0.0f),
		glm::vec3(0.2f, 0.0f, 0.0f),
		glm::vec3(0.3f, 0.0f, 0.0f),
		glm::vec3(0.4f, 0.0f, 0.0f)
	};
	
	glm::vec3 head = glm::vec3(0.5f, 0.0f, 0.0f);

	glm::vec3 directionOffset = glm::vec3(0.1f, 0.0f, 0.0f);
	
};