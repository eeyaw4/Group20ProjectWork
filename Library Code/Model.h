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

	void readFile();

	void readMaterial(string str);
	void readVerticies(string str);
	void readCell(string str);

public:
	vector<Material> mVector;
	vector<Vertex> vVector;
	vector<Cell> cVector;

	Model();
	~Model();

	void displayMaterial();
	void displayVerticies();
	void displayCell();
};

#endif