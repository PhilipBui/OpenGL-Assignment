/*
 * PFCapacitor.cpp
 *
 * COMP330 Assignment 3 - 2014
 *
 * Template by Matt Cabanag
 */

#include "PFCapacitor.h"

PFCapacitor::PFCapacitor()
{
	//todo:Fill this up with stuff you need
	rotX = 0;
	rotZ = 0;
}

void PFCapacitor::Update()
{
	//todo:Fill this up with stuff you need
	if (rpySpeed.x != 0 || rpySpeed.z != 0)
	{
		rotX += rpySpeed.x;
		rotZ += rpySpeed.z;
	}
	else
	{
		rotX += 3;
		rotZ += 7;
	}
	if (rotX >= 360) rotX -= 360;
	if (rotZ >= 360) rotZ -= 360;
}

void PFCapacitor::DrawModel()
{
	//todo:Fill this up with stuff you need
	glPushMatrix();
		glTranslatef(height/4, height/20, height/4);
		glScalef(height/2, height/10, height/2);
		glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(height/4, height-height/20, height/4);
		glScalef(height/2, height/10, height/2);
		glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(height/6, height/2, height/6);
		glScalef(height/3, height/3, height/3);
		glRotatef(rotX, 1, 0, 0);
		glRotatef(rotZ, 0, 0, 1);
		glutSolidCube(1);
		glPushMatrix();
			glRotatef(45, 1, 0, 1);
			glutSolidCube(1);
		glPopMatrix();
	glPopMatrix();

}


