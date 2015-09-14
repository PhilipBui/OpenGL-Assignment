/*
 * CPanel.h
 *
 * COMP330 Assignment 3 - 2014
 *
 * Template by Matt Cabanag
 */

#include "SceneObject.h"

#ifndef CPANEL_H_
#define CPANEL_H_

class CPanel : public SceneObject
{
	public:

		CPanel();

		float rise;
		virtual void Update();

	private:

		virtual void DrawModel();

};



#endif /* CPANEL_H_ */
