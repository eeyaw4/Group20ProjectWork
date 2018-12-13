#pragma once

#include <string>
#include <vector>

using namespace std;

#ifndef Cell_H
#define Cell_H

class Cell
{
public:
	int id;
	string shape;
	int material;
	vector<vector<float>> vertices;
	vector<int> verticesID;
    vector<float> centreOfGravity;
    float volume;
    float weight;

	Cell();
	~Cell();

	int getCellID();
	string getCellShape();
	int getCellMaterial();
	vector<vector<float>> getCellVertices();
	vector<int> getCellVerticesID();
    vector<float> getCentreOfGravity();
    vector<float> calcCentreOfGravity(int count);
    float getVolume();
	float getWeight();
};

#endif