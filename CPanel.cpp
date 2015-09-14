/*
 * CPanel.cpp
 *
 * COMP330 Assignment 3 - 2014
 *
 * Template by Matt Cabanag
 */

#include "CPanel.h"

CPanel::CPanel()
{
	//todo:Fill this up with stuff you need
	SceneObject();
	rise = height/4;
}

void CPanel::Update()
{
	//todo:Fill this up with stuff you need
	/*
	if (nearby == true)
	{
		if (rise <= height/4)
		{
			if (speed.y != 0)
			{
				rise += speed.y;
			}
			else
			{
				rise += 0.5;
			}
		}
	}
	else if (rise >= 0)
	{
		if (speed.y != 0)
		{
			rise -= speed.y;
		}
		else
		{
			rise -= 0.5;
		}
	}
	*/
}

void CPanel::DrawModel()
{
	//todo:Fill this up with stuff you need
	glPushMatrix();
		glTranslatef(height/4, rise + 0.5, height/6);
		glScalef(height/2, 1, height/3);
		glutSolidCube(1);
	glPopMatrix();
}



