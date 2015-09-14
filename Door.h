/*
 * Door.h
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

#include "SceneObject.h"

#ifndef DOOR_H_
#define DOOR_H_

class Door : public SceneObject
{
	public:

		Door();

		float open;
		float maxOpen;
		virtual void Update();

	private:

		virtual void DrawModel();

};



#endif /* DOOR_H_ */
