#include "Material.h"

#include <string>


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
/*
    struct colour = "0xRRGGBB"{
        colour.r = hexValue << 16;  // RR byte
        colour.g = hexValue << 8;   // GG byte
        colour.b = hexValue;        // BB byte
    }
*/
    return colour;
}

string Material::getMaterialName()
{
    return name;
}

