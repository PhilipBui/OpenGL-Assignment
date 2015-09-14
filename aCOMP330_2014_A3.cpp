/*
COMP330 Assignment 3 - 2014

Template by Matt Cabanag,

This is provided so you can hit the ground running.
It isn't really a thing to cage or restrict your efforts.
Feel completely free to modify anything. Or if you feel like it,
start completely from scratch!

As long as you hit the mark with what's been said in the
assignment specs, you'll be fine.

Any questions, post on the iLearn form or email me:
matt.cabanag@mq.edu.au

*/

#include <iostream>
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <fstream>
#include <time.h>
#include <vector>
#include <GL/glut.h>
#include <GL/glu.h>
#include "UtilityStructs.h"
#include "SceneObject.h"
#include "SpaceCrate.h"
#include "Chair.h"
#include "CPanel.h"
#include "Door.h"
#include "Floor.h"
#include "PFCapacitor.h"
#include "SpaceCrate.h"
#include "Star.h"
#include "Wall.h"
#include "Math.h"
#include <ctime>
using namespace std;
const double PI = 3.1459265;
const int screenWidth = 800;
const int screenHeight = 600;

//scene hierarchy root used for drawing
vector <SceneObject*> SceneRoot;

//intermediate scene data
vector <RawSceneData> MyRawData;

//the official scene filename!
#define IN_FILE "DeckPlan.txt"

//coordinates for the main camera's location
Vector3 mainCamPos;
//coordinates for what the camera is looking at
Vector3 mainCamLook;
//variables for the main camera's "up" vector
Vector3 mainCamUp;
//coordinates for the minimap camera's location
Vector3 minimapCamPos;
//coordinates for what the minimap camera is looking at
Vector3 minimapCamLook;
//variables for the minimap camera's "up" vector
Vector3 minimapCamUp;

const float moveSpeed = 1;
float rotation = 135;
const int shipWidth = 100;
const int shipLength = 200;
const int lengthByFive = shipLength / 5;
const int widthByThree = shipWidth / 3;
const int widthByFive = shipWidth / 5;
float height = 20;
bool flash = false;

void cameraInit()
{
	mainCamPos = Vector3(1, 12, 1);
	mainCamLook = Vector3(10, 12, 10);
	mainCamUp = Vector3(0, 1, 0);
	minimapCamUp = Vector3(0, 0, 1);
}
void init(void)
{
	//glEnable(GL_CULL_FACE);
	//glCullFace(GL_BACK);
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Buffer must be reset
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	GLfloat globalLight[] = {0.3, 0.3, 0.1, 1.0};
	GLfloat noLight[] = {0.0, 0.0, 0.0, 0.0}; // For light 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, globalLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, noLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, noLight);
	glEnable(GL_LIGHT0);
/*
	GLfloat corridorLightPos[] = {shipWidth/2, height-5, shipLength/2, 1.0};
	GLfloat corridorLightDir[] = {0.0, -1.0, 0.0, 1.0};
	glLightfv(GL_LIGHT1, GL_POSITION, corridorLightPos);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, corridorLightDir);
	GLfloat greenLight[] = {0.0, 1.0, 0.0, 1.0};
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 100);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 2.0);
	glLightfv(GL_LIGHT1, GL_SPECULAR, greenLight);
	glEnable(GL_LIGHT1);

	GLfloat controlRoomLightPos[] = {shipWidth/2, height/2, 1*lengthByFive, 1.0};
	GLfloat yellowLight[] = {1.0, 1.0, 0.0, 1.0};
	glLightfv(GL_LIGHT2, GL_POSITION, controlRoomLightPos);
	glLightfv(GL_LIGHT2, GL_SPECULAR, yellowLight);
	glEnable(GL_LIGHT2);

	GLfloat PFCapacitorOne[] = {widthByFive/2+5, height-2, shipLength-5, 0.0};
	GLfloat PFCapacitorTwo[] = {1*widthByFive + widthByFive/2+5, height-2, shipLength-5, 0.0};
	GLfloat PFCapacitorThree[] = {2*widthByFive + widthByFive/2+5, height-2, shipLength-5, 0.0};
	GLfloat PFCapacitorFour[] = {3*widthByFive + widthByFive/2+5, height-2, shipLength-5, 0.0};
	GLfloat PFCapacitorFive[] = {4*widthByFive + widthByFive/2+5, height-2, shipLength-5, 0.0};
	GLfloat blueLight[] = {0.0, 0.0, 0.2, 1.0};

	glLightfv(GL_LIGHT3, GL_POSITION, PFCapacitorOne);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, blueLight);
	glEnable(GL_LIGHT3);

	glLightfv(GL_LIGHT4, GL_POSITION, PFCapacitorTwo);
	glLightfv(GL_LIGHT4, GL_DIFFUSE, blueLight);
	glEnable(GL_LIGHT4);

	glLightfv(GL_LIGHT5, GL_POSITION, PFCapacitorThree);
	glLightfv(GL_LIGHT5, GL_DIFFUSE, blueLight);
	glEnable(GL_LIGHT5);

	glLightfv(GL_LIGHT6, GL_POSITION, PFCapacitorFour);
	glLightfv(GL_LIGHT6, GL_DIFFUSE, blueLight);
	glEnable(GL_LIGHT6);

	glLightfv(GL_LIGHT7, GL_POSITION, PFCapacitorFive);
	glLightfv(GL_LIGHT7, GL_DIFFUSE, blueLight);
	glEnable(GL_LIGHT7);
*/
	glEnable(GL_LIGHTING);
}

//sets up the minimap view
void setupMinimapView()
{
	//todo: Set up the minimap view
	minimapCamPos = Vector3(mainCamPos.x, 20, mainCamPos.z);
	minimapCamLook = mainCamPos;
	glViewport(0, 0, 100, 100);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(170, screenWidth / screenHeight, 15, 20);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(minimapCamPos.x, minimapCamPos.y, minimapCamPos.z,
			minimapCamLook.x, minimapCamLook.y, minimapCamLook.z,
			minimapCamUp.x, minimapCamUp.y, minimapCamUp.z);
}

//sets up the first person view
void setupFirstPersonView()
{
	//todo: Set up the first person view
	glViewport(10, 10, 800, 600);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50, screenWidth / screenHeight, 0.5, 300);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	/*gluLookAt(mainCamPos.x, mainCamPos.y, mainCamPos.z,
			mainCamLook.x, mainCamLook.y, mainCamLook.z,
			mainCamUp.x, mainCamUp.y, mainCamUp.z); */
	init();
	glRotatef(rotation, 0, 1, 0);
	glTranslatef(-mainCamPos.x, -mainCamPos.y, -mainCamPos.z);
}

//THE SCENE DRAWER!
void drawScene()
{
	//todo: Draw the scene using the hierarchy.
	for(unsigned int i = 0; i < SceneRoot.size(); i++)
	{
		SceneRoot.at(i) -> Display();
	}
}

//THE ANIMATOR!!
void animateScene()
{
	//todo: Animate the scene using the hierarchy.
	for(unsigned int i = 0; i < SceneRoot.size(); i++)
	{
		SceneRoot.at(i) -> Update();
		SceneRoot.at(i) -> GetCamPos(mainCamPos);
	}
	if (!flash)
	{
		flash = true;
		glEnable(GL_LIGHT3);
		glEnable(GL_LIGHT4);
		glEnable(GL_LIGHT5);
		glEnable(GL_LIGHT6);
		glEnable(GL_LIGHT7);
	}
	else
	{
		flash = false;
		glDisable(GL_LIGHT3);
		glDisable(GL_LIGHT4);
		glDisable(GL_LIGHT5);
		glDisable(GL_LIGHT6);
		glDisable(GL_LIGHT7);
	}
}

//This keeps animation times constant between different CPU's.
void animateSceneTimer(int milis)
{
	animateScene();
	glutTimerFunc(milis, animateSceneTimer, milis);
}

//You get file reading for free in the template.
//You just need to figure out how to make sense of the
//data and turn it into a viewable scene.
void LoadSceneFile(string filename)
{
	ifstream inStream;
	inStream.open(filename.c_str());

	//Load the raw data in first.
	while(!inStream.eof())
	{
		string type,col;
		int cPairs;
		float x,y, rot;
		RawSceneData sceneLine;

		inStream >> type >> cPairs;
		cout << type << ": " << cPairs << endl;

		sceneLine.type = type;
		sceneLine.cPairs = cPairs;

		for(int i = 0; i < cPairs; i++)
		{
			inStream >> x >> y;
			cout << x << "," << y << endl;

			Vector2 newPoint = Vector2(x,y);

			sceneLine.pointList.push_back(newPoint);
		}


		inStream >> col;
		cout << col << endl;

		sceneLine.colour = col;

		inStream >> rot;
		cout << rot << endl;

		sceneLine.initRotation = rot;

		MyRawData.push_back(sceneLine);
	}
	//Then process the data so its in the scene
	for(unsigned int i = 0; i < MyRawData.size(); i++)
	{
		RawSceneData sd = MyRawData.at(i);
		//This is how we handle Chairs.
		if (sd.type == "Chair")
		{
			Chair* newChair = new Chair();
			newChair -> position = Vector3(sd.pointList.at(0).x, 0, sd.pointList.at(0).y);
			newChair -> colour = Colour4::GetColour(sd.colour);
			newChair -> rpy = Vector3(0,0,sd.initRotation);
			SceneRoot.push_back(newChair);
		}
		//This is how we handle Control Panels.
		else if (sd.type == "CPanel")
		{
			CPanel* newCPanel = new CPanel();
			newCPanel -> position = Vector3(sd.pointList.at(0).x, 0, sd.pointList.at(0).y);
			newCPanel -> colour = Colour4::GetColour(sd.colour);
			newCPanel -> rpy = Vector3(0,0,sd.initRotation);
			SceneRoot.push_back(newCPanel);
		}
		//This is how we handle Crates.
		else if(sd.type == "Crate")
		{
			SpaceCrate* newCrate = new SpaceCrate();
			newCrate -> position = Vector3(sd.pointList.at(0).x, 0, sd.pointList.at(0).y);
			newCrate -> colour = Colour4::GetColour(sd.colour);
			newCrate -> rpy = Vector3(0,0,sd.initRotation);
			SceneRoot.push_back(newCrate);
		}
		//This is how we handle Doors.
		else if (sd.type == "Door")
		{
			Door* newDoor = new Door();
			newDoor -> position = Vector3(sd.pointList.at(0).x, 0, sd.pointList.at(0).y);
			newDoor -> colour = Colour4::GetColour(sd.colour);
			newDoor -> rpy = Vector3(0,0,sd.initRotation);
			SceneRoot.push_back(newDoor);
		}
		//This is how we handle Floors.
		else if(sd.type == "Floor")
		{
			Floor* newFloor = new Floor();
			newFloor -> position = Vector3(sd.pointList.at(0).x, 0, sd.pointList.at(0).y);
			newFloor -> topRight = sd.pointList.at(0);
			newFloor -> topLeft = sd.pointList.at(1);
			newFloor -> bottomLeft = sd.pointList.at(2);
			newFloor -> bottomRight = sd.pointList.at(3);
			newFloor -> colour = Colour4::GetColour(sd.colour);
			SceneRoot.push_back(newFloor);
		}
		//This is how we handle Planetary Flux Capacitors.
		else if(sd.type == "PFCapacitor")
		{
			PFCapacitor* newPFCapacitor = new PFCapacitor();
			newPFCapacitor -> position = Vector3(sd.pointList.at(0).x, 0, sd.pointList.at(0).y);
			newPFCapacitor -> colour = Colour4::GetColour(sd.colour);
			newPFCapacitor -> rpy = Vector3(0,0,sd.initRotation);
			SceneRoot.push_back(newPFCapacitor);
		}
		//This is how we handle Walls.
		else if(sd.type == "Wall")
		{
			Wall* newWall = new Wall();
			newWall -> pointList.at(0) = Vector2(sd.pointList.at(0).x, sd.pointList.at(0).y);
			newWall -> pointList.at(1) = Vector2(sd.pointList.at(1).x, sd.pointList.at(1).y);
			for (unsigned int i = 2; i < sd.pointList.size(); i++)
			{
				newWall -> pointList.push_back(Vector2(sd.pointList.at(i).x, sd.pointList.at(i).y));
			}
			newWall -> colour = Colour4::GetColour(sd.colour);
			SceneRoot.push_back(newWall);
		}
		//todo: Do the rest of the valid objects.
		//Chair, CPanel, Door, PFCapacitor, Wall.
	}
}

void LoadDefaultScene()
{
	//todo: Come up with your own default scene.
	SceneRoot.push_back(new Floor); // Floor
	SceneRoot.at(SceneRoot.size()-1) -> scale = Vector3(shipWidth, 1, shipLength);
	SceneRoot.at(SceneRoot.size()-1) -> colour = Colour4(0.12, 0.09, 0.08, 1);
	SceneRoot.push_back(new Floor); // Rooftop
	//height = SceneRoot.at(SceneRoot.size()-1) -> height;
	SceneRoot.at(SceneRoot.size()-1) -> position = Vector3(0, height, 0);
	SceneRoot.at(SceneRoot.size()-1) -> scale = Vector3(shipWidth, 1, shipLength);
	SceneRoot.at(SceneRoot.size()-1) -> colour = Colour4(0.22, 0.35, 0.42, 1);

	Wall* innerWall = new Wall(); // Wall
	innerWall -> pointList.at(0) = Vector2(0, 0);
	innerWall -> pointList.at(1) = Vector2(0, shipLength);
	innerWall -> pointList.push_back(Vector2(shipWidth, shipLength));
	innerWall -> pointList.push_back(Vector2(shipWidth, 0));
	innerWall -> pointList.push_back(Vector2(0, 0));
	SceneRoot.push_back(innerWall);
	SceneRoot.at(SceneRoot.size()-1) -> colour = Colour4(0.21, 0.25, 0.31, 1);

	Wall* corridorWallL = new Wall(); // Corridor Wall
	corridorWallL -> pointList.at(0) = Vector2(1*widthByThree + widthByThree/2+1, 1*lengthByFive + lengthByFive/2);
	corridorWallL -> pointList.at(1) = Vector2(0, 1*lengthByFive + lengthByFive/2);
	corridorWallL -> pointList.push_back(Vector2(0, 3*lengthByFive + lengthByFive/2));
	corridorWallL -> pointList.push_back(Vector2(1*widthByThree + widthByThree/2+1, 3*lengthByFive + lengthByFive/2));
	corridorWallL -> pointList.push_back(Vector2(1*widthByThree + widthByThree/2+1, 1*lengthByFive + lengthByFive/2));
	SceneRoot.push_back(corridorWallL);
	SceneRoot.at(SceneRoot.size()-1) -> colour = Colour4(0.4, 0.55, 0.6, 1);

	Wall* corridorWallR = new Wall(); // Corridor Wall
	corridorWallR -> pointList.at(0) = Vector2(2*widthByThree-3, 1*lengthByFive + lengthByFive/2); // Corner
	corridorWallR -> pointList.at(1) = Vector2(shipWidth, 1*lengthByFive + lengthByFive/2);
	corridorWallR -> pointList.push_back(Vector2(shipWidth, 3*lengthByFive + lengthByFive/2)); // Corner
	corridorWallR -> pointList.push_back(Vector2(2*widthByThree-3, 3*lengthByFive + lengthByFive/2));
	corridorWallR -> pointList.push_back(Vector2(2*widthByThree-3, 1*lengthByFive + lengthByFive/2)); // Corner
	SceneRoot.push_back(corridorWallR);
	SceneRoot.at(SceneRoot.size()-1) -> colour = Colour4(0.4, 0.55, 0.6, 1);

	SceneRoot.push_back(new Door); // Door to Control Room
	SceneRoot.at(SceneRoot.size()-1) -> position = Vector3(1*widthByThree + widthByThree/2, 0, 1*lengthByFive + lengthByFive/2);
	SceneRoot.at(SceneRoot.size()-1) -> colour = Colour4(0.2, 0.25, 0.3, 1);
	SceneRoot.push_back(new Door); // Door to Engine Room
	SceneRoot.at(SceneRoot.size()-1) -> position = Vector3(1*widthByThree + widthByThree/2, 0, 3*lengthByFive + lengthByFive/2);
	SceneRoot.at(SceneRoot.size()-1) -> colour = Colour4(0.2, 0.25, 0.3, 1);

	for (unsigned int i = 0; i < 3; i++) // Front three Control Panel and Chairs
	{
		SceneRoot.push_back(new CPanel);
		SceneRoot.at(SceneRoot.size()-1) -> position = Vector3(i*widthByThree + widthByThree/2 + 10, 0, 7.5);
		SceneRoot.at(SceneRoot.size()-1) -> rpy = Vector3(0, 0, 180);
		SceneRoot.at(SceneRoot.size()-1) -> colour = Colour4(0.05, 0.57, 1, 1);
		SceneRoot.push_back(new Chair);
		SceneRoot.at(SceneRoot.size()-1) -> position = Vector3(i*widthByThree + widthByThree/2 + 7.5, 0, 12.5);
		SceneRoot.at(SceneRoot.size()-1) -> rpy = Vector3(0, 0, 180);
		SceneRoot.at(SceneRoot.size()-1) -> colour = Colour4(0.0, 0.0, 0.0, 1);
	}

	SceneRoot.push_back(new CPanel); // Control Panel left of Captain
	SceneRoot.at(SceneRoot.size()-1) -> position = Vector3(7.5, 0, lengthByFive);
	SceneRoot.at(SceneRoot.size()-1) -> rpy = Vector3(0, 0, 270);
	SceneRoot.at(SceneRoot.size()-1) -> colour = Colour4(0.05, 0.57, 1, 1);
	SceneRoot.push_back(new Chair);
	SceneRoot.at(SceneRoot.size()-1) -> position = Vector3(12.5, 0, lengthByFive+2.5);
	SceneRoot.at(SceneRoot.size()-1) -> rpy = Vector3(0, 0, 270);
	SceneRoot.at(SceneRoot.size()-1) -> colour = Colour4(0.4, 0.0, 0.0, 1);

	SceneRoot.push_back(new CPanel); // Captain's Control Panel
	SceneRoot.at(SceneRoot.size()-1) -> position = Vector3(1*widthByThree + widthByThree/2 + 10, 0, lengthByFive);
	SceneRoot.at(SceneRoot.size()-1) -> scale = Vector3(1.5, 1.5, 1.5);
	SceneRoot.at(SceneRoot.size()-1) -> rpy = Vector3(0, 0, 180);
	SceneRoot.at(SceneRoot.size()-1) -> colour = Colour4(1, 0.55, 0.05, 1);
	SceneRoot.push_back(new Chair); // Captain's Chair
	SceneRoot.at(SceneRoot.size()-1) -> position = Vector3(1*widthByThree + widthByThree/2 + 7.5, 0, lengthByFive+5);
	SceneRoot.at(SceneRoot.size()-1) -> scale = Vector3(1.5, 1.5, 1.5);
	SceneRoot.at(SceneRoot.size()-1) -> rpy = Vector3(0, 0, 180);
	SceneRoot.at(SceneRoot.size()-1) -> colour = Colour4(0.94, 0.87, 0.37, 1);

	SceneRoot.push_back(new CPanel); // Control Panel right of Captain
	SceneRoot.at(SceneRoot.size()-1) -> position = Vector3(shipWidth-7.5, 0, lengthByFive);
	SceneRoot.at(SceneRoot.size()-1) -> rpy = Vector3(0, 0, 90);
	SceneRoot.at(SceneRoot.size()-1) -> colour = Colour4(0.05, 0.57, 1, 1);
	SceneRoot.push_back(new Chair);
	SceneRoot.at(SceneRoot.size()-1) -> position = Vector3(shipWidth-12.5, 0, lengthByFive-2.5);
	SceneRoot.at(SceneRoot.size()-1) -> rpy = Vector3(0, 0, 90);
	SceneRoot.at(SceneRoot.size()-1) -> colour = Colour4(0.0, 0.0, 0.4, 1);

	for (unsigned int i = 0; i < 5; i++) // Engine Room
	{
		SceneRoot.push_back(new CPanel); // Control Panels for Engine i
		SceneRoot.at(SceneRoot.size()-1) -> position = Vector3(i*widthByFive + widthByFive/2, 0, shipLength-20);
		SceneRoot.at(SceneRoot.size()-1) -> colour = Colour4(0.2, 0.2, 0.2, 1);
		SceneRoot.push_back(new Chair); // Chair for Control Panel for Engine i
		SceneRoot.at(SceneRoot.size()-1) -> position = Vector3(i*widthByFive + widthByFive/2 + 2.5, 0, shipLength-25);
		SceneRoot.at(SceneRoot.size()-1) -> colour = Colour4(0.0, 0.0, 0.0, 1);
		SceneRoot.push_back(new PFCapacitor); // Engine i
		SceneRoot.at(SceneRoot.size()-1) -> position = Vector3(i*widthByFive + widthByFive/2, 0, shipLength-5);
		SceneRoot.at(SceneRoot.size()-1) -> rpy = Vector3(0, 0, 45*i); // Rotate 2nd and 4th engine at 45 degrees.
		SceneRoot.at(SceneRoot.size()-1) -> colour = Colour4(0.27, 0.94, 1, 0.5);
		if (i > 0 && i < 4) // 2nd, 3rd and 4th engine on hyperdrive.
		{
			SceneRoot.at(SceneRoot.size()-1) -> rpySpeed = Vector3(45, 0, 45);
		}
	}
}

void display(void)
{	//clear the screen!
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	//first update the "logical model"; animate the world in other words
	//animateScene();

	//now draw the first person viewport
	setupFirstPersonView();
	drawScene();
	//draw the main viewport
	setupMinimapView();
	drawScene();
	//OpenGL house cleaning
	glFlush();//put everything on the pipeline
	glutPostRedisplay();//post the ready scenes.
	glutSwapBuffers();//swap the buffers
}

//Keyboard handler
void keyboard( unsigned char key, int x, int y )
{
	//todo: Fill this up with stuff you need.

	switch ( key )
	{	//move the view around with WASD

		case 'w':
		{
			mainCamPos.x += moveSpeed * sin(rotation / 180 * PI);
			//mainCamLook.x += moveSpeed * sin(rotation / (180 * PI));
			mainCamPos.z -= moveSpeed * cos(rotation / 180 * PI);
			//mainCamLook.z -= moveSpeed * cos(rotation / (180 * PI));
		}break;

		case 'a':
		{
			mainCamPos.x -= moveSpeed * cos(rotation / 180 * PI);
			//mainCamLook.x -= moveSpeed * cos(rotation / (180 * PI));
			mainCamPos.z -= moveSpeed * sin(rotation / 180 * PI);
			//mainCamLook.z -= moveSpeed * sin(rotation / (180 * PI));
		}break;

		case 's':
		{
			mainCamPos.x -= moveSpeed * sin(rotation / 180 * PI);
			//mainCamLook.x -= moveSpeed * sin(rotation / (180 * PI));
			mainCamPos.z += moveSpeed * cos(rotation / 180 * PI);
			//mainCamLook.z += moveSpeed * cos(rotation / (180 * PI));
		}break;

		case 'd':
		{
			mainCamPos.x += moveSpeed * cos(rotation / 180 * PI);
			//mainCamLook.x += moveSpeed * cos(rotation / (180 * PI));
			mainCamPos.z += moveSpeed * sin(rotation / 180 * PI);
			//mainCamLook.z += moveSpeed * sin(rotation / (180 * PI));
		}break;
		//rotate the ship with Q and E
		case 'q':
		{
			rotation -=2;
			if (rotation < 0)
			{
				rotation += 360;
			}
		}break;
		case 'e':
		{
			rotation +=2;
			if (rotation > 360)
			{
				rotation -= 360;
			}
		}break;

		//reset everything!
		case 'r':
		{
			cameraInit();
		}break;

		case 'l':
		{
			SceneRoot.clear();
			LoadSceneFile(IN_FILE);
		}break;

		//this is the escape key
		case 27:
		{	exit(1);
		}break;
		case 'z':
		{
			mainCamPos.y += moveSpeed;
		}break;
		case 'x':
		{
			mainCamPos.y -= moveSpeed;
		}break;
	}
}

//Special key handler
void specialKey( int key, int x, int y )
{
	//todo: Fill this up with stuff you need.
}

int main(int argc, char** argv)
{
	cameraInit();
	LoadDefaultScene();

	glutInit(&argc, argv);

	//setup double buffering
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	//set up the window
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow ("Spaceship trtr");

	//assign the callback functions
	glutDisplayFunc(display);
	//glutIdleFunc(animateScene);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKey);

	animateSceneTimer(50);

	//GOOOOWWW!!
	glutMainLoop();
	return 0;
}
