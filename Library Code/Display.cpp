#include "Display.h"

void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);

GLfloat rotationX = 0.0f;
GLfloat rotationY = 0.0f;

Display::Display()
{
	glfwInit();

	window = glfwCreateWindow(WIDTH, HEIGHT, "Shape Display", NULL, NULL);

	glfwSetKeyCallback(window, keyCallback);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);

	int screenWidth, screenHeight;
	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

	if (!window)
	{
		glfwTerminate();
		return;
	}

	glfwMakeContextCurrent(window);

	glViewport(0.0f, 0.0f, WIDTH, HEIGHT); // specifies the part of the window to which OpenGL will draw (in pixels), convert from normalised to pixels
	glMatrixMode(GL_PROJECTION); // projection matrix defines the properties of the camera that views the objects in the world coordinate frame. Here you typically set the zoom factor, aspect ratio and the near and far clipping planes
	glLoadIdentity(); // replace the current matrix with the identity matrix and starts us a fresh because matrix transforms such as glOrpho and glRotate cumulate, basically puts us at (0, 0, 0)
	glOrtho(0, WIDTH, 0, HEIGHT, 0, 1000); // essentially set coordinate system
	glMatrixMode(GL_MODELVIEW); // (default matrix mode) modelview matrix defines how your objects are transformed (meaning translation, rotation and scaling) in your world
	glLoadIdentity(); // same as above comment
}


Display::~Display()
{
}

void Display::drawCube(vector<vector<int>> data)
{
	double type;
	int size, c1, c2, c3;

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glPushMatrix();
		glTranslatef(halfScreenWidth, halfScreenHeight, -500);
		glRotatef(rotationX - 15, 1, 0, 0);
		glRotatef(rotationY, 0, 1, 0);
		glTranslatef(-halfScreenWidth, -halfScreenHeight, 500);

		for (vector<int> i : data)
		{
			if (i[0] == 0)
			{
				type = GL_FILL;
			}
			else if (i[0] == 1)
			{
				type = GL_LINE;
			}

			size = i[1];
			c1 = i[2];
			c2 = i[3];
			c3 = i[4];

			cubeTemplate(halfScreenWidth, halfScreenHeight, -500, size, type, c1, c2, c3);
		}

		rotationY -= 1;

		glPopMatrix();


		// Swap front and back buffers
		glfwSwapBuffers(window);

		// Poll for and process events
		glfwPollEvents();

	}

	glfwTerminate();
}

void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
	//std::cout << key << std::endl;

	const GLfloat rotationSpeed = 5;

	// actions are GLFW_PRESS, GLFW_RELEASE or GLFW_REPEAT
	if (action == GLFW_PRESS || action == GLFW_REPEAT)
	{
		switch (key)
		{
		case GLFW_KEY_UP:
			rotationX -= rotationSpeed;
			break;
		case GLFW_KEY_DOWN:
			rotationX += rotationSpeed;
			break;
		case GLFW_KEY_RIGHT:
			rotationY += rotationSpeed;
			break;
		case GLFW_KEY_LEFT:
			rotationY -= rotationSpeed;
			break;
		}
	}
}

void Display::cubeTemplate(GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ, GLfloat edgeLength,double type, int c1, int c2, int c3)
{
	GLfloat halfSideLength = edgeLength * 0.5f;

	GLfloat vertices[] = 
	{
		//Front Face
		centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, //Top left
		centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, //Top Right
		centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, //Bottom Left
		centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, //Bottom Right

		//Back Face
		centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, //Top left
		centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, //Top Right
		centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, //Bottom Left
		centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, //Bottom Right

		//Left Face
		centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, //Top left
		centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, //Top Right
		centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, //Bottom Left
		centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, //Bottom Right

		//Right Face
		centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, //Top left
		centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, //Top Right
		centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, //Bottom Left
		centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, //Bottom Right

		//Top Face
		centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, //Top left
		centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, //Top Right
		centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, //Bottom Left
		centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, //Bottom Right

		//Bottom Face
		centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, //Top left
		centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, //Top Right
		centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, //Bottom Left
		centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength  //Bottom Right
	};

	glPolygonMode(GL_FRONT_AND_BACK, type);
	glColor3f(c1,c2,c3);

	glEnableClientState(GL_VERTEX_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glDrawArrays(GL_QUADS, 0, 24);


	glDisableClientState(GL_VERTEX_ARRAY);
}
