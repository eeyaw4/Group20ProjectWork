#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;


#ifndef Vector_H
#define Vector_H

#include <iostream>
#include <vector>

using namespace std;

class Vector
{
public:
	Vector();
	~Vector();

	vector<float> xyz;

	void print();
	vector<float> getVector();
	
	vector<float> operator+(vector<float> v);
	vector<float> operator-(vector<float> v);
	float operator*(vector<float> v);
	vector<float> operator/(vector<float> v);

};

#endif // !Vector_H
