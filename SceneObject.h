/*
 * SceneObject.h
 *
 * This is the scene object superclass.
 * The basics that you need to display objects on screen.
 *
 * COMP330 Assignment 3 - 2014
 *
 * Template by Matt Cabanag
 */

#include "UtilityStructs.h"
#include <iostream>
#include <GL/glut.h>
#include <vector>//This is essentially a C++ ArrayList. It isn't a Vector in
				//a strictly mathematical sense, but can be used as one.
				//In our case, we're using it as an ArrayList.
using namespace std;


#ifndef SCENEOBJECT_H_
#define SCENEOBJECT_H_

class SceneObject
{
	public:
		//default constructor
		SceneObject();

		SceneObject(Vector3 pos, Vector3 speed, Vector3 scale,
				Vector3 ypr, Vector3 yprSpeed, Vector3 rgb);


		void AddChild(SceneObject*);

		//the function to update the object's attributes.
		virtual void Update();

		//get camera coordinates
		virtual void GetCamPos(Vector3);

		//display the damn thing
		virtual void Display();

		//display stuff to console
		virtual void DisplayToConsole();

		Vector3 position;
		Vector3 speed;
		Vector3 scale;
		Vector3 rpy;//yaw pitch and roll
		Vector3 rpySpeed;//yaw pitch roll speed
		Colour4 colour;//red green blue.
		bool lighting;
		bool displayActive;
		bool active;
		int height;
		Vector3 camPos;
		bool nearby;
	protected:
		vector <SceneObject*> children;

		virtual void DrawModel();

};


#endif /* SCENEOBJECT_H_ */
