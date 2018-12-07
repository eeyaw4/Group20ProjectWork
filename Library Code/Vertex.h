#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef Vertex_H
#define Vertex_H

class Vertex
{
public:
	Vertex();
	~Vertex();

	vector<float> xyz;

	void print();
	vector<float> getVector();
	
	vector<float> operator+(vector<float> v);
	vector<float> operator-(vector<float> v);
	float operator*(vector<float> v);
	vector<float> operator/(vector<float> v);

};

#endif
