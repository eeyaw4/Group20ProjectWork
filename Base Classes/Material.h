#pragma once

#include <string>

using namespace std;

class Material
{
public:
	int id, density;
	string colour, name;

	Material();
	~Material();
	int getMaterialID();
	int getMaterialDensity();
	string getMaterialColour();
	string getMaterialName();
};

