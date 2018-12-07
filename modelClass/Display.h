#pragma once

#include <iostream>
#include <vector>

//GLEW
#define GLEW_STATIC
#include <GL/glew.h>

//GLFW
#include <GLFW/glfw3.h>

const GLint WIDTH = 800, HEIGHT = 600;
const GLfloat halfScreenWidth = WIDTH / 2;
const GLfloat halfScreenHeight = HEIGHT / 2;

using namespace std;

class Display
{
public:
	GLFWwindow *window;

	Display();
	~Display();
	
	void openWindow();
	void cubeTemplate(GLfloat centerPosX,GLfloat centerPosY, GLfloat centerPosZ, GLfloat edgeLength,double type);
};

