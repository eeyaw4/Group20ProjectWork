#include "Cell.h"
#include <cmath>
#include <vector>

// Cell class constructor
Cell::Cell() {
}

// Cell class deconstructor
Cell::~Cell() {
}

// Returns the id saved to the Cell class
int Cell::getCellID() {
	return id;
}

// Returns the shape saved to the Cell class
string Cell::getCellShape() {
    return shape;
}

// Returns the material saved to the Cell class
int Cell::getCellMaterial() {
    return material;
}

// Returns the material class saved to the Cell class
Material Cell::getCellMaterialClass() {
	return materialClass;
}

// Returns the vertices' coordinates as a 2d array saved to the Cell class
vector<vector<float>> Cell::getCellVertices() {
    return vertices;
}

vector<int> Cell::getCellVerticesID() {
	return verticesID;
}

// Takes an average of each vertex coordinate and outputs the centre of the model
vector<float> Cell::getCentreOfGravity() {
    int count = 0;
    if (shape == "t") {
        count = 4;
    } else if (shape == "p") {
        count = 5;
    } else if (shape == "h") {
        count = 6;
    }
    centreOfGravity = calcCentreOfGravity(count);
    return centreOfGravity;
}

// Calculates the centre of gravity using the number of vertices on the model
vector<float> Cell::calcCentreOfGravity(int count) {
    float Total[3] = {0};
    vector<float> xyz;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < count; j++)
        {
            Total[i] = Total[i] + vertices[j][i];
        }

    }
    float x = Total[0] / count;
    float y = Total[1] / count;
    float z = Total[2] / count;
    xyz.push_back(x);
    xyz.push_back(y);
    xyz.push_back(z);
    return xyz;
}

// Calculates the volume of the model
float Cell::getVolume() {

    return volume;
}

// Uses volume to calculate the weight of the model
float Cell::getWeight() {

    return weight;
}
