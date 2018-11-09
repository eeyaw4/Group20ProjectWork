#pragma once

#include "Material.h"
#include "Vector.h"
#include "Cell.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class Model
{
private:
	Material *mArray;
	Vector *vArray;
	Cell *cArray;

	int mCount = 0, vCount = 0, cCount = 0;
	string str;

	void count();
	void readFile();

	void readMaterial(string str);
	void readVector(string str);
	void readCell(string str);

public:
	Model();
	~Model();
};

