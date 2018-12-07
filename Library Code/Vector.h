#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;


#ifndef Vector_H
#define Vector_H



class Vector
{
public:
	Vector();
	Vector(float x, float y, float z);
	~Vector();


	void add( Vector v );
	void print();
	
	Vector operator+(Vector v);
	Vector operator-(Vector v);
	float operator*(Vector v);
	Vector operator/(Vector v);

private:

	float x;
	float y;
	float z;

};

#endif // !Vector_H
