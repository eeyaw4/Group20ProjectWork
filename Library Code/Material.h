#pragma once

#include <string>

using namespace std;

#ifdef MATERIAL_H
#define MATERIAL_H

class Material
{
<<<<<<< HEAD:Base Classes/Material.h
private:
        int id;
        int density;
        string colour;
        string name;
=======
public:
	int id, density;
	string colour, name;
>>>>>>> f3534908ad820ea3be614563a2cac3525cb50893:Library Code/Material.h

public:
	Material();
	~Material();
<<<<<<< HEAD:Base Classes/Material.h
        int getMaterialID();
=======
	int getMaterialID();
>>>>>>> f3534908ad820ea3be614563a2cac3525cb50893:Library Code/Material.h
	int getMaterialDensity();
	string getMaterialColour();
	string getMaterialName();
};

#endif
