/*
 * SpaceCrate.h
 *
 * This is an example of how to inherit from the superclass
 * and customise its attributes. In this case, we're
 * customising the 3D model that gets drawn.
 *
 * COMP330 Assignment 3 - 2014
 *
 * Template by Matt Cabanag
 *
 */

#include "SceneObject.h"

#ifndef SPACECRATE_H_
#define SPACECRATE_H_
class SpaceCrate: public SceneObject
{
	public:
		SpaceCrate();

		float subCubeSize;
		float subCubeSep;

	private:
		virtual void DrawModel();
};




#endif /* SPACECRATE_H_ */
