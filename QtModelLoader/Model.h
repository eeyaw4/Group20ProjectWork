#pragma once

#include "Material.h"
#include "Vertex.h"
#include "Cell.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#ifndef Model_H
#define Model_H

class Model
{
private:
        string str;

        void readMaterial(string str);
        void readVertices(string str);
        void readCell(string str);

public:
        vector<Material> mVector;
        vector<Vertex> vVector;
        vector<Cell> cVector;

        int materialID;
        int materialDensity;
        string materialColour;
        string materialName;

        int vertexID;
        vector<float> vertexXYZ;

        int cellID;
        string cellShape;
        int cellMaterial;
        vector<vector<float>> cellVector;
        vector<float> cellCOG;
        float cellVolume;
        float cellWeight;
        int countNum;

        Model();
        ~Model();

        void readFile(string fileName);
        void writeToFile(string str);

        vector<float> calcModelCenter();

        void displayMaterial();
        void displayVertices();
        void displayCell();

        void getMaterialData(int id);
        void getVertexData(int id);
        void getCellData(int id);
};

#endif
