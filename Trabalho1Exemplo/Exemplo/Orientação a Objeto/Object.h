#pragma once
#include <iostream>
using namespace std;

class Object
{
protected:
	int angleX;
	int angleY;
	int angleZ;
	int posX;
	int posY;
	int posZ;
public:
	Object();
	~Object();
	void rotate(int angleX, int angleY, int angleZ);
	void translata(int angleX, int angleY, int angleZ);
	void scale(int angleX, int angleY, int angleZ);

};

