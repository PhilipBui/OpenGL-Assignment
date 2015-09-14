/*
 * Wall.cpp
 *
 *  Created on: 24/04/2014
 *      Author: AVataRR
 */
#include "Wall.h"

Wall::Wall()
{
	pointList.push_back(Vector2(0, 0));
	pointList.push_back(Vector2(1, 0));
	SceneObject();
}

void Wall::DrawModel()
{
	//todo: How do you draw walls?
	for (unsigned int i = 0; i < pointList.size()-1; i++)
	{
		glBegin(GL_QUADS);
			// Bottom left corner
			//glTexCoord2f(0,0);
			glVertex3f(pointList[i].x, 0, pointList[i].y);
			// Top left corner
			//glTexCoord2f(0,height);
			glVertex3f(pointList[i].x, height, pointList[i].y);
			// Top right corner
			//glTexCoord2f(height,height);
			glVertex3f(pointList[i+1].x, height, pointList[i+1].y);
			// Bottom right corner
			//glTexCoord2f(height,0);
			glVertex3f(pointList[i+1].x, 0, pointList[i+1].y);
		glEnd();
	}
}
