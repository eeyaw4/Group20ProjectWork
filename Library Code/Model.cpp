#include "Model.h"

// Model class constructor
Model::Model()
{
}

// Model class deconstructor
Model::~Model()
{
}

// Displays all of the data for every material that has been stored in the mVector Material vector
void Model::displayMaterial()
{
	for (int i = 0; i < mVector.size(); i++)
	{
		int id = mVector[i].getMaterialID();
		int d = mVector[i].getMaterialDensity();
		string c = mVector[i].getMaterialColour();
		string n = mVector[i].getMaterialName();

		cout << "ID: " << id << ", Density: " << d << ", Colour: " << c << ", Name: " << n << endl;
	}
}

// Displays all of the data for every vertex that has been stored in the vVector Vertex vector
void Model::displayVertices()
{
	for (int i = 0; i < vVector.size(); i++)
	{
		int id = vVector[i].getVertexID();
		vector<float> data = vVector[i].getVertexVector();
		float x = data[0];
		float y = data[1];
		float z = data[2];

		cout << "ID: " << id << ", X: " << x << ", Y: " << y << ", Z: " << z << endl;
	}
}

// Displays all of the data for every cell that has been stored in the cVector Cell vector
void Model::displayCell()
{
	for (int i = 0; i < cVector.size(); i++)
	{
		int id = cVector[i].getCellID();
		string s = cVector[i].getCellShape();
		int m = cVector[i].getCellMaterial();
		vector<int> vID = cVector[i].getCellVerticesID();
		vector<float> g = cVector[i].getCentreOfGravity();
        cout << "Centre of Gravity vector: "  << g[0] << ", " << g[1] << ", " << g[2] << ", ";

        cout << "ID: " << id << ", Shape: " << s << ", Material: " << m << ", COG: " << g[0] << ", " << g[1] << ", " << g[2] << ", Vertices: ";

		for (int j : vID)
		{
			cout << j << " ";
		}
		cout << endl;
		cout << endl;
	}
}

// Sets the material variables to data from the selected mVector Material depending on the id passed to the function
void Model::getMaterialData(int id)
{
	materialID = mVector[id].getMaterialID();
	materialDensity = mVector[id].getMaterialDensity();
	materialColour = mVector[id].getMaterialColour();
	materialName = mVector[id].getMaterialName();
}

// Sets the vertex variables to data from the selected vVector Vertex depending on the id passed to the function
void Model::getVertexData(int id)
{
	vertexID = vVector[id].getVertexID();
	vertexXYZ = vVector[id].getVertexVector();
}

// Sets the cell variables to data from the selected cVector Cell depending on the id passed to the function
void Model::getCellData(int id)
{
	cellID = cVector[id].getCellID();
	cellShape = cVector[id].getCellShape();
	cellMaterial = cVector[id].getCellMaterial();
	cellVector = cVector[id].getCellVertices();
	cellCOG = cVector[id].getCentreOfGravity();
}

// Calculates the center of the model using all of the vertices
vector<float> Model::calcModelCenter()
{
	Vertex data;
	data.xyz = { 0.0,0.0,0.0 };
	for (int i = 0; i < vVector.size(); i++)
	{
		data.xyz = data.operator+(vVector[i].getVertexVector());
	}

	vector<float> center = data.divideByNum((float)vVector.size());

	return center;
}

// Writes all of the data from the mVector, vVector and cVector vectors to a file passed to the function
void Model::writeToFile(string str)
{
	ofstream file;
	file.open(str);
	if (!file)
	{
		cerr << "Unable to find create file";
		exit(1);
	}

	file << "# Materials" << endl;
	for (int i = 0; i < mVector.size(); i++)
	{
		int id = mVector[i].getMaterialID();
		int d = mVector[i].getMaterialDensity();
		string c = mVector[i].getMaterialColour();
		string n = mVector[i].getMaterialName();

		file << "m " << id << " " << d << " " << c << " " << n << endl;
	}
	file << "" << endl;

	file << "# Vectors" << endl;
	for (int i = 0; i < vVector.size(); i++)
	{
		vector<float> data = vVector[i].getVertexVector();
		float x = data[0];
		float y = data[1];
		float z = data[2];

		file << "v " << i << " " << x << " " << y << " " << z << endl;
	}
	file << "" << endl;

	file << "# Cells" << endl;
	for (int i = 0; i < cVector.size(); i++)
	{
		int id = cVector[i].getCellID();
		string s = cVector[i].getCellShape();
		int m = cVector[i].getCellMaterial();
		vector<int> vID = cVector[i].getCellVerticesID();
		vector<float> g = cVector[i].getCentreOfGravity();


		file << "c " << id << " " << s << " " << m << " ";

		for (int j : vID)
		{
				file << j << " ";
		}
		file << endl;

	}
	file << "" << endl;

	file.close();
}

// Reads all of the data from a file passed to the function and stores the data into the mVector, vVector and cVector vectors
void Model::readFile(string fileName)
{
	ifstream dataFile;
	dataFile.open(fileName);
	if (!dataFile)
	{
		cerr << "Unable to find MOD file";
		exit(1);
	}
	while (getline(dataFile, str))
	{
		switch (str[0])
		{
		case 'm':
			readMaterial(str);
			break;
		case 'v':
			readVertices(str);
			break;
		case 'c':
			readCell(str);
			break;
		}
	}
	dataFile.close();

}

// Reads all data from the a line passed to the function into a Material class which is stored in the mVector vector
void Model::readMaterial(string str)
{
	int id, density;
	string type, colour, name;
	istringstream iss(str);
	Material m;
	if (iss >> type >> id >> density >> colour >> name)
	{
		m.id = id;
		m.density = density;
		m.colour = colour;
		m.name = name;

		mVector.push_back(m);
	}
	else
	{
		cout << "Error Reading Material" << endl;
	}
}

// Reads all data from the a line passed to the function into a Vertex class which is stored in the vVector vector
void Model::readVertices(string str)
{
	string type;
	int id;
	float x, y, z;
	istringstream iss(str);
	Vertex v;
	if (iss >> type >> id >> x >> y >> z)
	{
		v.id = id;
		v.xyz.push_back(x);
		v.xyz.push_back(y);
		v.xyz.push_back(z);

		vVector.push_back(v);
	}
	else
	{
		cout << "Error Reading Vertices" << endl;
	}
}

// Reads all data from the a line passed to the function into a Cell class which is stored in the cVector vector
void Model::readCell(string str)
{
	int id, point, material;
	string type, shape;
	istringstream iss(str);
	Cell c;
	int vID;
	if (iss >> type >> id >> shape >> material)
	{
		c.id = id;
		c.shape = shape;
		c.material = material;
		c.materialClass = mVector[material];

		while (iss >> point)
		{
			c.vertices.push_back(vVector[point].getVertexVector());
			c.verticesID.push_back(point);
		}
		c.verticesID.push_back(vID);

		cVector.push_back(c);
	}
	else
	{
		cout << "Error Reading Cells" << endl;
	}
}
