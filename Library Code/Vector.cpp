#include "Vector.h"


Vector::~Vector()
{
}


Vector::Vector()
{
}

vector<float> Vector::getVector()
{
	return xyz;
}

vector<float> Vector::operator+(vector<float> v)
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

vector<float> Vector::operator-(vector<float> v)
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

float Vector::operator*(vector<float> v)
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

vector<float> Vector::operator/(vector<float> v)
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

void Vector::print() {
	cout << "[" << xyz[0] << "," << xyz[1] << "," << xyz[2] << "]" << endl;
}
