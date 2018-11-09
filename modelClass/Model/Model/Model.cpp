#include "Model.h"

Model::Model()
{
	ifstream dataFile;
	dataFile.open("ExampleModel1.MOD");
	if (!dataFile) 
	{
		cerr << "Unable to find MOD file";
		exit(1);
	}

	string str;
	string type, id, x, y, z;
	while (getline(dataFile, str))
	{
		switch (str[0])
		{
		case 'm':			
			break;

		case 'v':
			cout << str << endl;
			break;

		case 'c':
			cout << str << endl;
			break;
		}
	}
	
	dataFile.close();
}

Model::~Model()
{
	delete [] mArray;
	delete [] vArray;
	delete [] cArray;
}
