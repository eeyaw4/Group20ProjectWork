#include <iostream>
#include "Vector.h"


Vector::~Vector()
{
}

Vector::Vector() {
}


Vector::Vector(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

void Vector :: add(Vector v) {
	this->x += v.x;
	this->y += v.y;
	this->z += v.z;
}

Vector Vector::operator+(Vector v) {
	Vector result;

	result.x = this->x + v.x;
	result.y = this->y + v.y;
	result.z = this->z + v.z;

	return result;
}

Vector Vector::operator-(Vector v) {
	Vector result;

	result.x = this->x - v.x;
	result.y = this->y - v.y;
	result.z = this->z - v.z;
	
	return result;
}

float Vector::operator*(Vector v) {
	Vector result;
	float final;

	result.x = this->x * v.x;
	result.y = this->y * v.y;
	result.z = this->z * v.z;
	
	final = (float)(result.x + result.y + result.z);

	return final;
}

Vector Vector::operator/(Vector v) {
	Vector result;
	

	result.x = this->y * v.z - z * v.y;
	result.y = this->z * v.x - x * v.z;
	result.z = this->x * v.y - y * v.x;


	return result;
}

void Vector::print() {
	cout << "[" << x << "," << y << "," << z << "]" << endl;
}
