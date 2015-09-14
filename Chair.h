/*
 * Chair.h
 *
 * COMP330 Assignment 3 - 2014
 *
 * Template by Matt Cabanag
 */

#include "SceneObject.h"

#ifndef CHAIR_H_
#define CHAIR_H_

class Chair : public SceneObject
{
	public:

		Chair();
		float rise;
		virtual void Update();

	private:

		virtual void DrawModel();

};



#endif /* CHAIR_H_ */
