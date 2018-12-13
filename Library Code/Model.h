#pragma once

#include "Material.h"
#include "Vertex.h"
#include "Cell.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#ifndef Model_H
#define Model_H

class Model
{
private:
	string str;

	vector<Material> mVector;
	vector<Vertex> vVector;
	vector<Cell> cVector;

	void readMaterial(string str);
	void readVertices(string str);
	void readCell(string str);

public:
	int materialDensity;
	string materialColour;
	string materialName;

	vector<float> vertexXYZ;

	string cellShape;
	int cellMaterial;
	vector<vector<float>> cellVector;
	vector<float> cellCOG;

	Model();
	~Model();

	void readFile(string fileName);
	void writeToFile(string str);

	vector<float> calcModelCenter();

	void displayMaterial();
	void displayVertices();
	void displayCell();

	void getMaterialData(int id);
	void getVertexData(int id);
	void getCellData(int id);
};

#endif