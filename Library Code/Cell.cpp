#include "Cell.h"


Cell::Cell() {
}

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

// Returns the vertices' coordinates as a 2d array saved to the Cell class
vector<vector<float>> Cell::getCellVertices() {
    return vertices;
}

vector<vector<int>> Cell::getCellVerticesID() {
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
        count = 8;
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
    float volume;
    A.xyz = vertices[0];
    B.xyz = vertices[1];
    C.xyz = vertices[2];
    D.xyz = vertices[3];

    BA.xyz = B.operator-(A.xyz);
    CA.xyz = C.operator-(A.xyz);
    DA.xyz = D.operator-(A.xyz);

    DC.push_back(CA.xyz[0] * DA.xyz[0]);
    DC.push_back(CA.xyz[1] * DA.xyz[1]);
    DC.push_back(CA.xyz[2] * DA.xyz[2]);

    volume = (float)1/(float)6 * BA.operator*(DC);

    return volume;
}


float Cell::calcHexahedronVolume() {
    /* Calculate hexahedron volume from 3 pyramids about the same apex
     * Hexahedron 0,1,2,3,4,5,6,7 Apex 7
     * Pyramid 1: 0,1,2,3,7
     * Pyramid 2: 0,1,4,5,7
     * Pyramid 3: 1,2,5,6,7
     * Add volumes together
     */
    Vertex A, B, C, D, E, F, G, H;
    Cell P;
    float volume = 0;
    for (int i = 0; i < 8; i++)
    {
    P.vertices.push_back(vertices[i]);
    }
    volume += P.calcPyramidVolume();
    P.vertices[2] = vertices[4];
    P.vertices[3] = vertices[5];
    volume += P.calcPyramidVolume();
    P.vertices[0] = vertices[1];
    P.vertices[1] = vertices[2];
    P.vertices[2] = vertices[5];
    P.vertices[3] = vertices[6];
    volume += P.calcPyramidVolume();

    return volume;
}

float Cell::calcPyramidVolume()
{
    /* To calculate the volume of a pyramid:
 * V = 1/3 * |(B - A) . ((C - A) * (D - A))|
 * Dot product of a multiplication of vectors.
 */
    Vertex A, B, C, D, E;
    Vertex BA, CA, DA, CDA;
    vector<float> DC;
    float volume;
    A.xyz = vertices[0];
    B.xyz = vertices[1];
    C.xyz = vertices[3];
    D.xyz = vertices[4];

    BA.xyz = B.operator-(A.xyz);
    CA.xyz = C.operator-(A.xyz);
    DA.xyz = D.operator-(A.xyz);

    DC.push_back(CA.xyz[0] * DA.xyz[0]);
    DC.push_back(CA.xyz[1] * DA.xyz[1]);
    DC.push_back(CA.xyz[2] * DA.xyz[2]);

    volume = (float)1/(float)3 * BA.operator*(DC);

    return volume;
}

// Uses volume to calculate the weight of the model
float Cell::getWeight()
{
    float density = materialClass.getMaterialDensity();
    float volume = this->getVolume();
    float weight = volume * density;


    return weight;
}
