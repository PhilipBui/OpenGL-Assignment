/*
 * Star.h
 *
 * This is an example of how to inherit from the superclass
 * and customise its attributes. In this case, we're
 * customising the 3D model that gets drawn.
 *
 * COMP330 Assignment 3 - 2014
 *
 * Template by Matt Cabanag
 */

#include "SceneObject.h"

#ifndef STAR_H_
#define STAR_H_

class Star: public SceneObject
{
	public:

		Star();

	private:
		virtual void DrawModel();
};

#endif /* STAR_H_ */
