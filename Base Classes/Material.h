#pragma once

#include <string>

using namespace std;

class Material
{
public:
	int density;
	string colour, name;

	Material();
	~Material();
	int getMaterialDensity();
	string getMaterialColour();
	string getMaterialName();
};

