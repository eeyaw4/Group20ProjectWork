#include "main.h"

int main(void)
{
	Model testModel;

	testModel.readFile("ExampleModel1.MOD");

	testModel.displayMaterial();
	testModel.displayVertices();
	testModel.displayCell();

	testModel.writeToFile("test.txt");

	vector<float> center = testModel.calcModelCenter();
	cout << "Center Of Model:" << "X: " << center[0] << ", Y: " << center[1] << ", Z: " << center[2] << endl;

	while (1);
}