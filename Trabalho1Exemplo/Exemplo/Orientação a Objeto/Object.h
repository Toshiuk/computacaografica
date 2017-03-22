#pragma once
#include <iostream>
using namespace std;

class Object
{
protected:
	float x;
	float y;
	float z;
	float r;
	float g;
	float b;
public:
	Object();
	~Object();
	void rotate();
	void translate();
	void scale();
	void color(int r, int g, int b);
	virtual void draw() = 0;
};

