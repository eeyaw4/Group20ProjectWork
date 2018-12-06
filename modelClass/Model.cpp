#include "Model.h"

Model::Model()
{
	readFile();

	
	for (int i = 0; i < mVector.size();i++)
	{
		int d = mVector[i].getMaterialDensity();
		string c = mVector[i].getMaterialColour();
		string n = mVector[i].getMaterialName();

		cout << "ID: "<< i <<", Density: " << d << ", Colour: " << c << ", Name: " << n << endl;
	}

	for (int i = 0; i < vVector.size(); i++)
	{
		float x = vVector[i].getVectorX();
		float y = vVector[i].getVectorY();
		float z = vVector[i].getVectorZ();

		cout << "ID: " << i << ", X: " << x << ", Y: " << y << ", Z: " << z << endl;
	}

	for (int i = 0; i < cVector.size(); i++)
	{
		string s  = cVector[i].getCellShape();
		int m = cVector[i].getCellMaterial();
		vector<int> v = cVector[i].getCellVerticies();

		cout << "ID: " << i << ", Shape: " << s << ", Material: " << m << ", Verticies: ";

		for (int j : v)
		{
			cout << j << ", ";
		}
		cout << endl;
		
	}
}

Model::~Model()
{
}

void Model::readFile(void)
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
	string type, id, density, colour, name;
	istringstream iss(str);
	Material m;
	if (iss >> type >> id >> density >> colour >> name)
	{
		m.density = stoi(density);
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
	string type, id, x, y, z;
	istringstream iss(str);
	Vector v;
	if (iss >> type >> id >> x >> y >> z)
	{
		v.x = stof(x);
		v.y = stof(y);
		v.z = stof(z);

		vVector.push_back(v);
	}
	else
	{
		cout << "Error Reading Verticies" << endl;
	}
}

void Model::readCell(string str)
{
	string type, id, shape;
	istringstream iss(str);
	Cell c;
	int point, material;
	if (iss >> type >> id >> shape >> material)
	{
		c.shape = shape;
		c.material = material;

		while (iss >> point)
		{
			c.verticies.push_back(point);
		}

		cVector.push_back(c);
	}
	else
	{
		cout << "Error Reading Cells" << endl;
	}
}
