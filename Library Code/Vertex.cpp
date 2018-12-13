#include "Vertex.h"


Vertex::~Vertex()
{
}


Vertex::Vertex()
{
}

vector<float> Vertex::getVector()
{
	return xyz;
}

// Vector addition
vector<float> Vertex::operator+(vector<float> v)
{
	vector<float> result;
	float x = xyz[0];
	float y = xyz[1];
	float z = xyz[2];

	result[0] = x + v[0];
	result[1] = y + v[1];
	result[2] = z + v[2];

	return result;
}

// Vector subtraction
vector<float> Vertex::operator-(vector<float> v)
{
	vector<float> result;
	float x = xyz[0];
	float y = xyz[1];
	float z = xyz[2];

	result[0] = x - v[0];
	result[1] = y - v[1];
	result[2] = z - v[2];
	
	return result;
}

// Dot product
float Vertex::operator*(vector<float> v)
{
	vector<float> result;
	float final;
	float x = xyz[0];
	float y = xyz[1];
	float z = xyz[2];

	result[0] = x * v[0];
	result[1] = y * v[1];
	result[2] = z * v[2];
	
	final = (float)(result[0] + result[1] + result[2]);
	return final;
}

// Cross Product
vector<float> Vertex::operator/(vector<float> v)
{
	vector<float> result;
	float x = xyz[0];
	float y = xyz[1];
	float z = xyz[2];

	result[0] = y * v[2] - z * v[1];
	result[1] = z* v[0] - x * v[2];
	result[2] = x * v[1] - y * v[0];

	return result;
}

void Vertex::print() {
	cout << "[" << xyz[0] << "," << xyz[1] << "," << xyz[2] << "]" << endl;
}
