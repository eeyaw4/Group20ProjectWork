#pragma once

#include <string>

using namespace std;

#ifndef Material_H
#define Material_H

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

#endif