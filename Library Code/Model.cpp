#include "Model.h"

Model::Model()
{
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

void Model::displayVertices()
{
	for (int i = 0; i < vVector.size(); i++)
	{
		vector<float> data = vVector[i].getVertexVector();
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
		vector<vector<int>> vID = cVector[i].getCellVerticesID();
		vector<float> g = cVector[i].getCentreOfGravity();

		cout << "ID: " << i << ", Shape: " << s << ", Material: " << m << ", COG: " << g[0] << ", " << g[1] << ", " << g[2] << ", Vertices: ";

		for (vector<int> j : vID)
		{
			for (int i = 0; i < j.size(); i++)
				cout << j[i] << " ";
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
	vertexXYZ = vVector[id].getVertexVector();
}

void Model::getCellData(int id)
{
	cellShape = cVector[id].getCellShape();
	cellMaterial = cVector[id].getCellMaterial();
	cellVector = cVector[id].getCellVertices();
	cellCOG = cVector[id].getCentreOfGravity();
}

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
		vector<vector<int>> vID = cVector[i].getCellVerticesID();
		vector<float> g = cVector[i].getCentreOfGravity();


		file << "c " << id << " " << s << " " << m << " ";

		for (vector<int> j : vID)
		{
			for (int i = 0; i < j.size(); i++)
				file << j[i] << " ";
		}
		file << endl;

	}
	file << "" << endl;

	file.close();
}

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

void Model::readCell(string str)
{
	int id, point, material;
	string type, shape;
	istringstream iss(str);
	Cell c;
	vector<int> vID;
	if (iss >> type >> id >> shape >> material)
	{
		c.id = id;
		c.shape = shape;
		c.material = material;

		while (iss >> point)
		{
			c.vertices.push_back(vVector[point].getVertexVector());
			vID.push_back(point);
		}
		c.verticesID.push_back(vID);

		cVector.push_back(c);
	}
	else
	{
		cout << "Error Reading Cells" << endl;
	}
}
