#pragma once
#include "Vertex.h"
#include "Material.h"
#include <cmath>
#include <vector>
#include <string>

using namespace std;

#ifndef Cell_H
#define Cell_H

class Cell
{
public:
	int id;
	string shape;
	int material;
	Material materialClass;
	vector<vector<float>> vertices;
	vector<int> verticesID;
    vector<float> centreOfGravity;
    float volume;
    float weight;

	Cell();
	~Cell();

	// These functions simply return the values saved to the Cell class
	int getCellID();
    string getCellShape();
	int getCellMaterial();
	Material getCellMaterialClass();
	vector<vector<float>> getCellVertices();
	vector<int> getCellVerticesID();
    vector<float> getCentreOfGravity();
    vector<float> calcCentreOfGravity(int count);

    // Calculates the volume of
    float getVolume();
    float calcTetrahedronVolume();
    float calcHexahedronVolume();
    float calcPyramidVolume();

    // Calculates Weight from Volume x Density
    float getWeight();

    // Calculates Weight from Volume x Density
};

#endif
