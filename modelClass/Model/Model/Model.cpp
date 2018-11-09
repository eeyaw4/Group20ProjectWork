#include "Model.h"

Model::Model()
{
	count();

	mArray = new Material[mCount];
	vArray = new Vector[vCount];
	cArray = new Cell[cCount];

	readFile();

	
	for (int i = 0; i < 2;i++)
	{
		int d = mArray[i].getMaterialDensity();
		string c = mArray[i].getMaterialColour();
		string n = mArray[i].getMaterialName();

		cout << "ID: "<< i <<", Density: " << d << ", Colour: " << c << ", Name: " << n << endl;
	}

	for (int i = 0; i < 12; i++)
	{
		float x = vArray[i].getVectorX();
		float y = vArray[i].getVectorY();
		float z = vArray[i].getVectorZ();

		cout << "ID: " << i << ", X: " << x << ", Y: " << y << ", Z: " << z << endl;
	}
}

Model::~Model()
{
	delete [] mArray;
	delete [] vArray;
	delete [] cArray;
}

void Model::count(void)
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
			mCount++;
			break;

		case 'v':
			vCount++;
			break;

		case 'c':
			cCount++;
			break;
		}
	}
	dataFile.close();
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
			readVector(str);
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
	while (iss >> type >> id >> density >> colour >> name)
	{
		int num = stoi(id);
		mArray[num].density = stoi(density);
		mArray[num].colour = colour;
		mArray[num].name = name;
	}
}

void Model::readVector(string str)
{
	string type, id, x, y, z;
	istringstream iss(str);
	while (iss >> type >> id >> x >> y >> z)
	{
		int num = stoi(id);
		vArray[num].x = stof(x);
		vArray[num].y = stof(y);
		vArray[num].z = stof(z);
	}
}

void Model::readCell(string str)
{
}
