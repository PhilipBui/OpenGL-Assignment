/*
 * Floor.cpp
 *
 * This is the floor class. It needs to know
 * its corners in order to cover a rectangular space.
 *
 * COMP330 Assignment 3 - 2014
 *
 * Template by Matt Cabanag
 */

#include "Floor.h"

Floor::Floor()
{
	height = 0;
	topLeft = Vector2(0,0);
	topRight = Vector2(1,0);
	bottomLeft = Vector2(0,1);
	bottomRight = Vector2(1,1);
	SceneObject();

}

void Floor::DrawModel()
{
	glBegin(GL_QUADS);
		// Bottom left corner
		//glTexCoord2f(0,0);
		glVertex3f(bottomLeft.x, height, bottomLeft.y);
		// Top left corner
		//glTexCoord2f(0, topRight.y - bottomLeft.y);
		glVertex3f(topLeft.x ,height, topLeft.y);
		// Top right corner
		//glTexCoord2f(topRight.x - bottomLeft.x, topRight.y - bottomLeft.y);
		glVertex3f(topRight.x, height, topRight.y);
		// Bottom right corner
		//glTexCoord2f(topRight.x - bottomLeft.x, 0);
		glVertex3f(bottomRight.x, height, bottomRight.y);
	glEnd();
}


