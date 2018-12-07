#pragma once

#include <string>

using namespace std;

#ifdef MATERIAL_H
#define MATERIAL_H

class Material
{
private:
        int id;
        int density;
        string colour;
        string name;

public:
	Material();
	~Material();
        int getMaterialID();
	int getMaterialDensity();
	string getMaterialColour();
	string getMaterialName();
};

#endif
