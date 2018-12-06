#pragma once

#include <iostream>

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
	void drawCube(GLfloat centerPosX,GLfloat centerPosY, GLfloat centerPosZ, GLfloat edgeLength);
};

