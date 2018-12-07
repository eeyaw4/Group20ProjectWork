#pragma once

#include <string>

using namespace std;

class Material
{
public:
	int id;
    int density;
    string colour;
    string name;

	Material();
	~Material();
    
	int getMaterialID();
	int getMaterialDensity();
	string getMaterialColour();
	string getMaterialName();
};
