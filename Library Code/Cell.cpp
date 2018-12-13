#include "Cell.h"
#include <cmath>
#include <vector>
#include <Vertex.h>


Cell::Cell() {
}

Cell::~Cell() {
}

// Returns the shape saved to the Cell class
string Cell::getCellShape() {
    return shape;
}

// Returns the material saved to the Cell class
int Cell::getCellMaterial() {
    return material;
}

// Returns the vertices' coordinates as a 2d array saved to the Cell class
vector<vector<float>> Cell::getCellVertices() {
    return vertices;
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
    if (shape == "t") {
        volume = Cell::calcTetrahedronVolume();
    } else if (shape == "p") {
        volume = calcPyramidVolume();
    } else if (shape == "h") {
        volume = calcHexahedronVolume();
    }
    return volume;
}

float Cell::calcTetrahedronVolume() {
/* To calculate the volume of a tetrahedron:
 * V = 1/6 * |(B - A) . ((C - A) * (D - A))|
 * Dot product of a multiplication of vectors.
 */
    Vertex A, B, C, D;
    Vertex BA, CA, DA, CDA;
    vector<float> DC;
    float x, volume;
    A.xyz = vertices[0];
    B.xyz = vertices[1];
    C.xyz = vertices[2];
    D.xyz = vertices[3];

    BA.xyz = B.operator-(A.xyz);
    CA.xyz = C.operator-(A.xyz);
    DA.xyz = D.operator-(A.xyz);

    DC[0] = CA.xyz[0] * DA.xyz[0];
    DC[1] = CA.xyz[1] * DA.xyz[1];
    DC[2] = CA.xyz[2] * DA.xyz[2];

    volume = (float)1/(float)6 * BA.operator*(DC);

    return volume;
}


float Cell::calcHexahedronVolume()
{
    Vertex A, B, C, D, E, F;
}

float Cell::calcPyramidVolume()
{

}

// Uses volume to calculate the weight of the model
float Cell::getWeight()
{
    float volume = this->getVolume();


    return weight;
}
