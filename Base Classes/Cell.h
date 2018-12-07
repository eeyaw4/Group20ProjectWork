#pragma once

#include <string>
#include <vector>

using namespace std;

class Cell
{
public:
	string shape;
	int material;
	vector<vector<float>> verticies;

	Cell();
	~Cell();

	string getCellShape();
	int getCellMaterial();
	vector<vector<float>> getCellVerticies();
};