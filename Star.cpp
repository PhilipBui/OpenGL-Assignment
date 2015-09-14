/*
 * Star.cpp
 *
 * This is an example of how to inherit from the superclass
 * and customise its attributes. In this case, we're
 * customising the 3D model that gets drawn.
 *
 * COMP330 Assignment 3 - 2014
 *
 * Template by Matt Cabanag
 */

#include "Star.h"

void drawStar();

Star::Star()
{
	SceneObject();
}

void Star::DrawModel()
{
	drawStar();
}

//the star model
void drawStar()
{	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);

	glBegin(GL_POLYGON);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0.05, 0);
		glVertex3f(0.075 ,0,0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3f(0, 0, 0);
		glVertex3f(0.1, 0.1, 0);
		glVertex3f(0.1, 0, 0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, 0.09);
		glVertex3f(0.05, 0, 0);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3f(0, 0, 0);
		glVertex3f(0.09, 0, 0.09);
		glVertex3f(0, 0.05, 0);
	glEnd();

	glEnable(GL_LIGHTING);// Enable lighting calculations
	glEnable(GL_LIGHT0);// Turn on light #0.
}
