#include "Model.h"

Model::Model()
{
	readFile();
}

Model::~Model()
{
}

void Model::displayMaterial()
{
	for (int i = 0; i < mVector.size(); i++)
	{
		int d = mVector[i].getMaterialDensity();
		string c = mVector[i].getMaterialColour();
		string n = mVector[i].getMaterialName();

		cout << "ID: " << i << ", Density: " << d << ", Colour: " << c << ", Name: " << n << endl;
	}
}

void Model::displayVerticies()
{
	for (int i = 0; i < vVector.size(); i++)
	{
		vector<float> data = vVector[i].getVector();
		float x = data[0];
		float y = data[1];
		float z = data[2];

		cout << "ID: " << i << ", X: " << x << ", Y: " << y << ", Z: " << z << endl;
	}
}

void Model::displayCell()
{
	for (int i = 0; i < cVector.size(); i++)
	{
		string s = cVector[i].getCellShape();
		int m = cVector[i].getCellMaterial();
		vector<vector<float>> v = cVector[i].getCellVertices();

		cout << "ID: " << i << ", Shape: " << s << ", Material: " << m << ", Verticies: ";

		for (vector<float> j : v)
		{
			cout << "Vector: ";
			cout << j[0] << ", ";
			cout << j[1] << ", ";
			cout << j[2] << ", ";
		}
		cout << endl;

	}
}

void Model::getMaterialData(int id)
{
	materialDensity = mVector[id].getMaterialDensity();
	materialColour = mVector[id].getMaterialColour();
	materialName = mVector[id].getMaterialName();
}

void Model::getVertexData(int id)
{
	vertexXYZ = vVector[id].getVector();
}

void Model::getCellData(int id)
{
	cellShape = cVector[id].getCellShape();
	cellMaterial = cVector[id].getCellMaterial();
	cellVector = cVector[id].getCellVertices();
}

void Model::readFile()
{
	ifstream dataFile;
	dataFile.open("ExampleModel1.MOD");
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
			readVerticies(str);
			break;
		case 'c':
			readCell(str);
			break;
		}
	}
	dataFile.close();

}

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

void Model::readVerticies(string str)
{
	string type;
	int id;
	float x, y, z;
	istringstream iss(str);
	Vertex v;
	if (iss >> type >> id >> x >> y >> z)
	{
		v.xyz.push_back(x);
		v.xyz.push_back(y);
		v.xyz.push_back(z);

		vVector.push_back(v);
	}
	else
	{
		cout << "Error Reading Verticies" << endl;
	}
}

void Model::readCell(string str)
{
	int id, point, material;
	string type, shape;
	istringstream iss(str);
	Cell c;
	if (iss >> type >> id >> shape >> material)
	{
		c.shape = shape;
		c.material = material;

		while (iss >> point)
		{
			c.vertices.push_back(vVector[point].getVector());
		}

		cVector.push_back(c);
	}
	else
	{
		cout << "Error Reading Cells" << endl;
	}
}
