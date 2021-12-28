#include "Snake.h"
#include <thread>
#include <chrono>
#include <GLFW/glfw3.h>

void Snake::proceed()
{
	//std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	auto it = tail.begin();
	for (size_t i = 0; i != tail.size() - 1; ++i)
	{
		auto next = it;
		std::advance(next, 1);
		*it++ = *next;
	}
	*it = head;

	head += directionOffset;
}

void Snake::setOffset(glm::vec3 nextDirection)
{
	directionOffset = nextDirection;
}

const glm::vec3 Snake::getOffset()const
{
	return directionOffset;
}
