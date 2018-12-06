#pragma once

#include <string>
#include <vector>

using namespace std;

class Cell
{
public:
	string shape;
	int material;
	vector<int> verticies;

	Cell();
	~Cell();

	string getCellShape();
	int getCellMaterial();
	vector<int> getCellVerticies();
};