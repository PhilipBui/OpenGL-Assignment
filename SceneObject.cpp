/*
 * SceneObject.h
 *
 * This is the scene object superclass.
 * The basics that you need to display objects on screen.
 *
 * COMP330 Assignment 3 - 2014
 *
 * Template by Matt Cabanag
 *
 */

#include "SceneObject.h"//** You NEED this to refer back to the header file.
#include <iostream>

SceneObject::SceneObject()
{
	active = true;
	displayActive = true;
	lighting = true;
	position = Vector3();
	speed = Vector3();
	scale = Vector3(1, 1, 1);
	rpy = Vector3();//yaw pitch and roll
	rpySpeed = Vector3();//yaw pitch roll speed
	//rgb = Vector3();//red green blue.
	colour.r = 1;
	colour.g = 1;
	colour.b = 1;
	colour.a = 1;
	height = 20;
	camPos = Vector3();
	nearby = false;

}


void SceneObject::Update()
{
	//todo: Need to make hierarchical objects possible.
	//How does this need to be modified?
	//position += speed;
	//rpy += rpySpeed;
}

void SceneObject::GetCamPos(Vector3 mainCamPos)
{
	camPos = mainCamPos;
	if (camPos.x <= position.x+40 && camPos.x >= position.x-40 &&
		camPos.z <= position.z+40 && camPos.z >= position.z-40)
	{
		nearby = true;
	}
	else nearby = false;
}
void SceneObject::AddChild(SceneObject* newChild)
{
	children.push_back(newChild);
}

void SceneObject::DisplayToConsole()
{
	cout<<rpy.x<<","<<rpy.y<<","<<rpy.z<<","<<endl;
}

void SceneObject::Display()
{
	if(!lighting)
	{	glColor3f(colour.r,colour.g,colour.b);
	}
	else
	{
		glColor3f(colour.r,colour.g,colour.b);
		GLfloat sphereAmbient[4] = { colour.r,colour.g,colour.b, colour.a};
		GLfloat specular[4] = {1.0, 1.0, 1.0, 1};
		GLfloat shininess = 50;

		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, sphereAmbient);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular );
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
	}

	//todo: Need to make hierarchical objects possible.
	//How does this need to be modified?
	glPushMatrix();
		glTranslatef(position.x,position.y,position.z);
		glRotatef(rpy.z,0,1,0);//yaw
		glRotatef(rpy.y,0,0,1);//pitch
		glRotatef(rpy.x,1,0,0);//roll
		glScalef(scale.x,scale.y,scale.z);
		DrawModel();
	glPopMatrix();
}

void SceneObject::DrawModel()
{
	glutSolidCube(3);
	glutSolidSphere(2,20,20);
}
