#pragma once

#include <string>
#include <vector>

using namespace std;

#ifndef Cell_H
#define Cell_H

class Cell
{
public:
	string shape;
	int material;
	vector<vector<float>> vertices;

	Cell();
	~Cell();

	string getCellShape();
	int getCellMaterial();
	vector<vector<float>> getCellVertices();
};

#endif