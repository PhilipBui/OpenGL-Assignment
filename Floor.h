/*
 * Floor.h
 *
 * This is the floor class. It needs to know
 * its corners in order to cover a rectangular space.
 *
 * COMP330 Assignment 3 - 2014
 *
 * Template by Matt Cabanag
 */

#include "SceneObject.h"

#ifndef FLOOR_H_
#define FLOOR_H_
class Floor : public SceneObject
{
	public:
		Floor();

		Vector2 topLeft;
		Vector2 topRight;
		Vector2 bottomLeft;
		Vector2 bottomRight;

	protected:
		virtual void DrawModel();

};

#endif /* FLOOR_H_ */
