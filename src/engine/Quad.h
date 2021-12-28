#pragma once

class Quad
{
public:

	const float* getCoordinates() const;

	const unsigned int getCoordinatesSize() const;

	const unsigned int* getIndices() const;

	const unsigned int getIndicesSize() const;

private:

	const float vertices[12] =
	{
		-0.10f, 0.10f, 0.0f,
		-0.10f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 0.10f, 0.0f
	};

	const unsigned int indices[6] =
	{ 
		0, 1, 3, 
		1, 2, 3  
	};

};