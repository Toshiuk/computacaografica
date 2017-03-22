#include "Circle.h"

Circle::Circle()
{
}


Circle::~Circle()
{
}

void Circle::draw(){
	float raio = 1;
	int lados = 10;
	float passo = (1.0 / (lados / 3));
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 360; i += (360 / lados))
	{
		glVertex2d(raio * cos(i*(3.14 / 180)), raio * sin(i*(3.14 / 180)));
	}
	glEnd();
}