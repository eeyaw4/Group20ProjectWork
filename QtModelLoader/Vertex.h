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
	int id;

	void print();
	vector<float> getVertexVector();
	int getVertexID();
	
	vector<float> operator+(vector<float> v);
	vector<float> operator-(vector<float> v);
	float operator*(vector<float> v);
	vector<float> operator/(vector<float> v);

	vector<float> timesByNum(float n);
	vector<float> divideByNum(float n);
};

#endif
