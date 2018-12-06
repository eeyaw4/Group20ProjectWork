#pragma once

#include "Material.h"
#include "Vector.h"
#include "Cell.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Model
{
private:
	vector<Material> mVector;
	vector<Vector> vVector;
	vector<Cell> cVector;


	int mCount = 0, vCount = 0, cCount = 0;
	string str;

	void readFile();

	void readMaterial(string str);
	void readVerticies(string str);
	void readCell(string str);

public:
	Model();
	~Model();
};

