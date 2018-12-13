#include "Vertex.h"


Vertex::~Vertex()
{
}


Vertex::Vertex()
{
}

vector<float> Vertex::getVertexVector()
{
	return xyz;
}

int Vertex::getVertexID()
{
	return id;
}

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

void Vertex::print() {
	cout << id << "[" << xyz[0] << "," << xyz[1] << "," << xyz[2] << "]" << endl;
}
