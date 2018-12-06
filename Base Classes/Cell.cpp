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

vector<int> Cell::getCellVerticies()
{
	return verticies;
}