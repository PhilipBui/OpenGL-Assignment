/*
 * Wall.h
 *
 * This thing makes a wall based on a series of points.
 *
 * COMP330 Assignment 3 - 2014
 *
 * Template by Matt Cabanag
 */
#include "SceneObject.h"

#ifndef WALL_H_
#define WALL_H_

class Wall : public SceneObject
{
	public:

		Wall();

		vector <Vector2> pointList;

	protected:
		virtual void DrawModel();

};



#endif /* WALL_H_ */
