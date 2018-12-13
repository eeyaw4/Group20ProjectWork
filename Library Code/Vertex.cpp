#include "Vertex.h"

// Vertex class constructor
Vertex::~Vertex()
{
}

// Vertex class deconstructor
Vertex::Vertex()
{
}

// Returns the VertexVector xyz saved to the vertex class
vector<float> Vertex::getVertexVector()
{
	return xyz;
}

// Returns the VertexID saved to the vertex class
int Vertex::getVertexID()
{
	return id;
}

// Adds a vector to the current vector stored in the Vertex class
vector<float> Vertex::operator+(vector<float> v)
{
	vector<float> result;
	float x = xyz[0];
	float y = xyz[1];
	float z = xyz[2];

	result.push_back(x + v[0]);
	result.push_back(y + v[1]);
	result.push_back(z + v[2]);

	return result;
}

// Subtracts a vector to the current vector stored in the Vertex class
vector<float> Vertex::operator-(vector<float> v)
{
	vector<float> result;
	float x = xyz[0];
	float y = xyz[1];
	float z = xyz[2];

	result.push_back(x - v[0]);
	result.push_back(y - v[1]);
	result.push_back(z - v[2]);
	
	return result;
}

// Calculates the scalar product
float Vertex::operator*(vector<float> v)
{
	vector<float> result;
	float final;
	float x = xyz[0];
	float y = xyz[1];
	float z = xyz[2];

	result.push_back(x * v[0]);
	result.push_back(y * v[1]);
	result.push_back(z * v[2]);
	
	final = (float)(result[0] + result[1] + result[2]);

	return final;
}

// Calculates the vector product
vector<float> Vertex::operator/(vector<float> v)
{
	vector<float> result;
	float x = xyz[0];
	float y = xyz[1];
	float z = xyz[2];

	result.push_back(y * v[2] - z * v[1]);
	result.push_back(z * v[0] - x * v[2]);
	result.push_back(x * v[1] - y * v[0]);

	return result;
}

// Multiplies the stored vector by a float
vector<float> Vertex::timesByNum(float n)
{
	vector<float> result;
	float x = xyz[0];
	float y = xyz[1];
	float z = xyz[2];

	result.push_back(x * n);
	result.push_back(y * n);
	result.push_back(z * n);

	return result;
}

// Divides the stored vector by a float
vector<float> Vertex::divideByNum(float n)
{
	vector<float> result;
	float x = xyz[0];
	float y = xyz[1];
	float z = xyz[2];

	result.push_back(x * (1 / n));
	result.push_back(y * (1 / n));
	result.push_back(z * (1 / n));

	return result;
}

// Prints out stored vector id and coordinates
void Vertex::print() {
	cout << id << "[" << xyz[0] << "," << xyz[1] << "," << xyz[2] << "]" << endl;
}
