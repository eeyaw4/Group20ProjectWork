#include "Cell.h"

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

// returns the ID of the vertex
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
    float x = Total[0] / (float)count;
    float y = Total[1] / (float)count;
    float z = Total[2] / (float)count;
    xyz.push_back(x);
    xyz.push_back(y);
    xyz.push_back(z);
    return xyz;
}

// Calculates the volume of the model by what shape it has
float Cell::getVolume() {
    if (shape == "t") {
        volume = calcTetrahedronVolume();
    } else if (shape == "p") {
        volume = calcPyramidVolume();
    } else if (shape == "h") {
        volume = calcHexahedronVolume();
    }
    return volume;
}

// Calculates volume of a tetrahedron
float Cell::calcTetrahedronVolume() {
/* To calculate the volume of a tetrahedron:
 * V = 1/6 * |((A - D) * (B - D)) . (C - D)|
 */
    /*
     * (x4-x1)[(y2-y1)(z3-z1) - (z2-z1)(y3-y1)] +
     * (y4-y1)[(z2-z1)(x3-x1) - (x2-x1)(z3-z1)] +
     * (z4-z1)[(x2-x1)(y3-y1) - (y2-y1)(x3-x1)]
     * _______________________________________
     *                   6
     */
    Vertex A, B, C, D;
    // Variable to store base area
    float total;
    float volume;
    A.xyz = vertices[0];
    B.xyz = vertices[1];
    C.xyz = vertices[2];
    D.xyz = vertices[3];

    total = {
            (D.xyz[0]-A.xyz[0])* ( (B.xyz[1]-A.xyz[1])*(C.xyz[2]-A.xyz[2]) - (B.xyz[2]-A.xyz[2])*(C.xyz[1]-A.xyz[1]) ) +
            (D.xyz[1]-A.xyz[1])* ( (B.xyz[2]-A.xyz[2])*(C.xyz[0]-A.xyz[0]) - (B.xyz[0]-A.xyz[0])*(C.xyz[2]-A.xyz[2]) ) +
            (D.xyz[2]-A.xyz[2])* ( (B.xyz[0]-A.xyz[0])*(C.xyz[1]-A.xyz[1]) - (B.xyz[1]-A.xyz[1])*(C.xyz[0]-A.xyz[0]) )
    };
    volume = fabs(total / (float)6);



    return volume;
}

// Calculates volume of a hexahedron using pyramids
float Cell::calcHexahedronVolume()
{
    /* Calculate hexahedron volume from 3 pyramids about the same apex
     * Hexahedron 0,1,2,3,4,5,6,7 Apex 7
     * Pyramid 1: 0,1,2,3,7
     * Pyramid 2: 0,1,4,5,7
     * Pyramid 3: 1,2,5,6,7
     * Add volumes together
     */
    Cell P;
    float volume = 0;
    for (int i = 0; i < 4; i++)
    {
    P.vertices.push_back(vertices[i]);
    }
    P.vertices.push_back(vertices[7]);
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

// Calculates volume of 5 vertex
float Cell::calcPyramidVolume()
{
    /* To calculate the volume of a pyramid:
     * Volume of 2 tetrahedrons of either side of the apex
     * Pyramid 0, 1, 2, 3, 4, apex at 4
     * Tetrahedron 1: 0, 1, 3, 4
     * Tetrahedron 2: 1, 2, 3, 4
     * Add volumes together
    */
    float volume = 0;
    Cell T;
    T.vertices.push_back(vertices[0]);
    T.vertices.push_back(vertices[1]);
    T.vertices.push_back(vertices[3]);
    T.vertices.push_back(vertices[4]);

    volume += T.calcTetrahedronVolume();
    T.vertices[0] = vertices[1];
    T.vertices[1] = vertices[2];
    volume += T.calcTetrahedronVolume();

    return volume;
}

// Uses volume to calculate the weight of the model
float Cell::getWeight()
{
    /*  Weight = Density x Volume */
    float density = (float)materialClass.getMaterialDensity();
    float volume = this->getVolume();
    float weight = volume * density;

    return weight;
}
