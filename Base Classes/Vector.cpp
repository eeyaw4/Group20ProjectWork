#include <iostream>
#include "Vector.h"



Vector::Vector()
{
	value1 = 0.0;
	value2 = 0.0;
	value3 = 0.0;
}


Vector::~Vector()
{
}

Vector::Vector(float x, float y, float z) {
	value1 = x;
	value2 = y;
	value3 = z;
	
}

float Vector::getvalue_x() const {
	return value1;
}

float Vector::getvalue_y() const {
	return value2;
}

float Vector::getvalue_z() const {
	return value3;
}

