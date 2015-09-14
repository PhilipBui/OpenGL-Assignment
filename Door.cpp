/*
 * Door.cpp
 *
 *You need to get this thing to track the location
 *of the observer within the virtual world and react
 *to its proximity.
 *
 *You need to come up with a closing animation
 *and an opening animation.
 *
 * COMP330 Assignment 3 - 2014
 *
 * Template by Matt Cabanag
 */

#include "Door.h"

Door::Door()
{
	//todo:Fill this up with stuff you need
	SceneObject();
	open = 0;
	maxOpen = 6;
}

void Door::Update()
{
	//todo:Fill this up with stuff you need
	if (nearby == true)
	{
		if (open <= maxOpen)
		{
			if (speed.x != 0)
			{
				open += speed.x;
			}
			else
			{
				open += maxOpen / 10;
			}
		}
	}
	else if (open >= 0)
	{
		if (speed.x != 0)
		{
			open -= speed.x;
		}
		else
		{
			open -= maxOpen / 10;
		}
	}
}

void Door::DrawModel()
{
	//todo:Fill this up with stuff you need
	glPushMatrix();
		glTranslatef(height/4-open, height/2, 0.5);
		glScalef(height/2, height, 1);
		glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(height/4+height/4+open, height/2, 0.5);
		glScalef(height/2, height, 1);
		glutSolidCube(1);
	glPopMatrix();
}


