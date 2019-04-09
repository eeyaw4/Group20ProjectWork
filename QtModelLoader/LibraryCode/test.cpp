#include "Model.h"

bool testFail = false;

int main()
{
	Model testModel;
	testModel.readFile("../ExampleModel1.MOD");
	
	vector<float> testVector;

	testVector.push_back(1.);
	testVector.push_back(1.);
	testVector.push_back(1.);

	testModel.getMaterialData(0);
	testModel.getVertexData(6);
	testModel.getCellData(1);
	
	if (testModel.materialID != 0)
	{
		testFail = true;
	}
	else if (testModel.materialDensity != 8960)
	{
		testFail = true;
	}
	else if (testModel.materialColour != "b87333")
	{
		testFail = true;
	}
	else if (testModel.materialName != "copper")
	{
		testFail = true;
	}	
	else if (testModel.vertexID != 6 )
	{
		testFail = true;
	}
	else if (testModel.vertexXYZ != testVector)
	{
		testFail = true;
	}	
	else if (testModel.cellID != 1)
	{
		testFail = true;
	}
	else if (testModel.cellShape != "t")
	{
		testFail = true;
	}
	else if (testModel.cellMaterial != 1)
	{
		testFail = true;
	}	
	
	if (testFail == false)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}