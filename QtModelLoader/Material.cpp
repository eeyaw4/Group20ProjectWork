#include "Material.h"

#include <string>

// Material class constructor
Material::Material()
{

}

// Material class deconstructor
Material::~Material()
{

}

// Returns the id saved to the Material class
int Material::getMaterialID()
{
    return id;
}

// Returns the density saved to the Material class
int Material::getMaterialDensity()
{
    return density;
}

// Returns the colour saved to the Material class
string Material::getMaterialColour()
{
    return colour;
}

vector<float> Material::getRGB()
{
    vector<float> RGB;
    int rI,gI,bI;

    stringstream(colour.substr(0,2)) >> hex >> rI;
    stringstream(colour.substr(2,2)) >> hex >> gI;
    stringstream(colour.substr(4,2)) >> hex >> bI;

    RGB.push_back(rI/255.0);
    RGB.push_back(gI/255.0);
    RGB.push_back(bI/255.0);

    return RGB;
}

// Returns the name saved to the Material class
string Material::getMaterialName()
{
    return name;
}

