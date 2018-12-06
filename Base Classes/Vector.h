#pragma once
#include <iostream>
#include <string>

using namespace std;


#ifndef Vector_H
#define Vector_H



class Vector
{
public:
	Vector();
	Vector(float, float, float);
	~Vector();

	float getvalue_x() const;
	float getvalue_y() const;
	float getvalue_z() const;
	float getvalue_a() const;
	float getvalue_b() const;
	float getvalue_c() const;

private:
	float value1;
	float value2;
	float value3;
};

#endif // !Vector_H
