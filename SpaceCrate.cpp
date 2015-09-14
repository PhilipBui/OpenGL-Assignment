/*
 * SpaceCrate.cpp
 *
 * This is an example of how to inherit from the superclass
 * and customise its attributes. In this case, we're
 * customising the 3D model that gets drawn.
 *
 * COMP330 Assignment 3 - 2014
 *
 * Template by Matt Cabanag
 */
#include "SpaceCrate.h"

SpaceCrate::SpaceCrate()
{
	subCubeSep = 0.5;
	subCubeSize = 0.35;
	SceneObject();
}

void SpaceCrate::DrawModel()
{
	//top right back sub cube
	glTranslatef(-subCubeSep+(subCubeSize/2),subCubeSep-(subCubeSize/2),subCubeSep-(subCubeSize/2));
	glutSolidCube(subCubeSize);

	//top left back sub cube
	glTranslatef(subCubeSep,0,0);
	glutSolidCube(subCubeSize);

	//bottom left back sub cube
	glTranslatef(0,-subCubeSep,0);
	glutSolidCube(subCubeSize);

	//bottom right back sub cube
	glTranslatef(-subCubeSep,0,0);
	glutSolidCube(subCubeSize);

	//bottom right front sub cube
	glTranslatef(0,0,-subCubeSep);
	glutSolidCube(subCubeSize);

	//bottom left front sub cube
	glTranslatef(subCubeSep,0,0);
	glutSolidCube(subCubeSize);

	//top left front sub cube
	glTranslatef(0.0,subCubeSep,0);
	glutSolidCube(subCubeSize);

	//top right front sub cube
	glTranslatef(-subCubeSep,0,0);
	glutSolidCube(subCubeSize);

}



