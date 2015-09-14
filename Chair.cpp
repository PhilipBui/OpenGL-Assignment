/*
 * Chair.cpp
 *
 * COMP330 Assignment 3 - 2014
 *
 * Template by Matt Cabanag
 */


#include "Chair.h"

Chair::Chair()
{
	//todo:Fill this up with stuff you need
	SceneObject();
	rise = height/6;
}

void Chair::Update()
{
	//todo:Fill this up with stuff you need
	/*
	if (nearby == true)
	{
		if (rise <= height/6)
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

void Chair::DrawModel()
{
	//todo:Fill this up with stuff you need
	// Making chair legs
	if (rise >= 0)
	{
		glPushMatrix();
			glTranslatef(0.5, rise/2, 0.5);
			glScalef(1, rise, 1);
			glutSolidCube(1); // Leg 1
			for (int i = 0; i < 3; i++)
			{
				int x = 4; // Leg 2
				int z = 4; // Leg 2
				if (i == 1) // Leg 3
				{
					x = 0;
				}
				if (i == 2) // Leg 4
				{
					z = 0;
				}
				glPushMatrix();
					glTranslatef(x, 0, z);
					glutSolidCube(1);
				glPopMatrix();
			}
		glPopMatrix();
	}
	// Making seat of the chair
	glPushMatrix();
		glTranslatef(2.5, rise, 2.5);
		glScalef(5, 1, 5);
		glutSolidCube(1);
	glPopMatrix();
	// Making back of the chair
	glPushMatrix();
		glTranslatef(2.5, rise + rise, 0.5);
		glScalef(5, rise*2, 1);
		glutSolidCube(1);
	glPopMatrix();

	/*
	for (int i = 0; i < 4; i++)
	{
		glPushMatrix();
			glTranslatef(5, i*5, 1.5);
			glScalef(10, 1, 3);
			glutSolidCube(1);
		glPopMatrix();
	}
	glPushMatrix();
		glTranslatef(0.5, 7.5, 0.5);
		glScalef(1, 15, 1);
		glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(10.5, 7.5, 0.5);
		glScalef(1, 15, 1);
		glutSolidCube(1);
	glPopMatrix();
	*/

}
