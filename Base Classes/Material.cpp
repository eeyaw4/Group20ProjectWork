#include "Material.h"



Material::Material()
{
}


Material::~Material()
{
}

int Material::getMaterialID()
{
	return id;
}

int Material::getMaterialDensity()
{
	return density;
}

string Material::getMaterialColour()
{
	return colour;
}

string Material::getMaterialName()
{
	return name;
}

