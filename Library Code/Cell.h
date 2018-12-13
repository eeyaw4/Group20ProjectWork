#pragma once
#include <cmath>
#include <vector>
#include <Vertex.h>
#include <Material.h>
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
	vector<vector<int>> verticesID;
    vector<float> centreOfGravity;
    float volume;
    float weight;

	Cell();
	~Cell();

	// These functions simply return the values saved to the Cell class
	int getCellID();
    string getCellShape();
	int getCellMaterial();
	vector<vector<float>> getCellVertices();
    vector<vector<int>> getCellVerticesID();


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

    // Calculates Weight from Volume x Density
};

#endif