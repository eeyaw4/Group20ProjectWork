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
    vector<float> centreOfGravity;
    float volume;
    float weight;

	Cell();
	~Cell();

	// These functions simply return the values saved to the Cell class
	string getCellShape();
	int getCellMaterial();
	vector<vector<float>> getCellVertices();

	// These functions are used to calculate the centre of gravity for a given set of vertices
	vector<float> getCentreOfGravity();
    vector<float> calcCentreOfGravity(int count);

    // Calculates the volume of
    float getVolume();
    float calcTetrahedronVolume();
    float calcHexahedronVolume();
    float calcPyramidVolume();

    // Calculates Weight from Volume x Density
	float getWeight();
};

#endif