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
/*
    struct colour = "0xRRGGBB"{
        colour.r = hexValue << 16;  // RR byte
        colour.g = hexValue << 8;   // GG byte
        colour.b = hexValue;        // BB byte
    }
*/
    return colour;
}

// Returns the name saved to the Material class
string Material::getMaterialName()
{
    return name;
}

