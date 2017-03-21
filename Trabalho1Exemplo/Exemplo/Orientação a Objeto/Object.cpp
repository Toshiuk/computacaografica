#include "Object.h"
#include "Scene.h"

Object::Object() : posX(0), posY(0), posZ(0), angleX(0), angleY(0), angleZ(0)
{
}


Object::~Object()
{
}


void Object::rotate(int angleX, int angleY, int angleZ)
{
	this->angleX += angleX;
	this->angleY += angleY;
	this->angleZ += angleZ;
}

void Object::translata(int angleX, int angleY, int angleZ)
{
	this->angleX += angleX;
	this->angleY += angleY;
	this->angleZ += angleZ;
}

void Object::scale(int angleX, int angleY, int angleZ)
{
	this->angleX += angleX;
	this->angleY += angleY;
	this->angleZ += angleZ;
}

