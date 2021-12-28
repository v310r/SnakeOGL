#include "Quad.h"


const float* Quad::getCoordinates() const
{
	return vertices;
}

const unsigned int Quad::getCoordinatesSize() const		
{
	return sizeof(float) * 12;
}


const unsigned int* Quad::getIndices() const
{
	return indices;
}

const unsigned int Quad::getIndicesSize() const
{
	return sizeof(float) * 6;
}