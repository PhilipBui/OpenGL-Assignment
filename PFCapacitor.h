/*
 * PFCapacitor.h
 *
 * COMP330 Assignment 3 - 2014
 *
 * Template by Matt Cabanag
 */

#include "SceneObject.h"

#ifndef PFCAPACITOR_H_
#define PFCAPACITOR_H_

class PFCapacitor : public SceneObject
{
	public:

		PFCapacitor();

		virtual void Update();

		float rotX, rotZ;

	private:

		virtual void DrawModel();

};



#endif /* PFCAPACITOR_H_ */
