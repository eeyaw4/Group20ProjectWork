#include "Cell.h"



Cell::Cell()
{
}


Cell::~Cell()
{
}

string Cell::getCellShape()
{
	return shape;
}

int Cell::getCellMaterial()
{
	return material;
}

vector<vector<float>> Cell::getCellVertices()
{
	return vertices;
}