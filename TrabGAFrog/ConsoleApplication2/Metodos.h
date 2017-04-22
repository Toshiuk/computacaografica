#pragma once
#include <iostream>
#include "GL\glew.h"
#include "GL\freeglut.h"
#include <vector>
#include "Car.h"
#include "Frog.h"
#include <iostream>  
#include <windows.h>
#include <conio.h>
#include <dos.h>
#include <stdio.h>
#include <mmsystem.h>
using namespace std;

//variaveis
GLfloat win;
char texto[50];
LPCWSTR snd = L"..\\snd\\sound.WAV";
LPCWSTR dead = L"..\\snd\\dead.wav";
LPCWSTR winner = L"..\\snd\\win.wav";
int cont = 0;

//manipula vetor
vector<Car*> carros;
void addCar(Car *c) {
	carros.push_back(c);
}

//escrever na tela
void DesenhaTexto(char *string)
{
	glPushMatrix();
	// Posição no universo onde o texto será colocado          
	glRasterPos2f(-win*0.60, win - (win*0.08));
	// Exibe caracter a caracter
	while (*string)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *string++);
	glPopMatrix();
}
//fim escrever na tela

//func condições
void der() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 1.0f, 1.0f);
	strcpy(texto, "         VOCE PERDEU!");
	DesenhaTexto(texto);
	PlaySound(dead, NULL, SND_FILENAME | SND_ASYNC);
	cont = 2;
	glutSwapBuffers();
	system("pause");
}

void vic() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 1.0f, 1.0f);
	cout << "Termina jogo." << endl;
	strcpy(texto, "         VOCE VENCEU!");
	DesenhaTexto(texto);
	PlaySound(winner, NULL, SND_FILENAME | SND_ASYNC);
	cont = 1;
	glutSwapBuffers();
	system("pause");
}
//fim func condicoes

//instancia sapo
Frog cururu(50.0, -550.0, -50.0, -600.0, 15.0);
//fimsapo

//instancia carrros
Car c1(60.0, -400.0, -60.0, -450.0, 5.0);
Car c2(50.0, -300.0, -60.0, -350.0, 2.0);
Car c3(40.0, -200.0, -60.0, -250.0, 4.0);
Car c4(30.0, -100.0, -60.0, -150.0, 7.0);
Car c5(60.0, 50.0, -60.0, 0.0, 8.0);
Car c6(60.0, 150.0, -60.0, 100.0, 3.0);
Car c7(60.0, 250.0, -60.0, 200.0, 6.0);
//fimcarro

//desenha
void draw() {
	//add car no carros
	addCar(&c1);
	addCar(&c2);
	addCar(&c3);
	addCar(&c4);
	addCar(&c5);
	addCar(&c6);
	addCar(&c7);
	//fim add car no carros

	//desenhandooo
	glClear(GL_COLOR_BUFFER_BIT);

	//desenha limite
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	glVertex2d(-599.0 / 600, 300.0 / 600);
	glVertex2d(599.0 / 600, 300.0 / 600);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	glVertex2d(-599.0 / 600, -480.0 / 600);
	glVertex2d(599.0 / 600, -480.0 / 600);
	glEnd();

	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_LINES);
	glVertex2d(-599.0 / 600, 0.0 / 600);
	glVertex2d(599.0 / 600, 0.0 / 600);
	glEnd();

	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_LINES);
	glVertex2d(-599.0 / 600, -150.0 / 600);
	glVertex2d(599.0 / 600, -150.0 / 600);
	glEnd();
	//desenha limite


	//sapo cururu desenho 
	glColor3f(cururu.r, cururu.g, cururu.b);
	//braço esquerdo
	glBegin(GL_POLYGON);
	glVertex2d((cururu.vx1 + 2.0) / 600, cururu.vy / 600); //A
	glVertex2d((cururu.vx1 + 2.0) / 600, (cururu.vy1 + 27.0) / 600);//B1
	glVertex2d((cururu.vx1 + 24.0) / 600, (cururu.vy1 + 27.0) / 600);//A1
	glVertex2d((cururu.vx1 + 18.0) / 600, cururu.vy / 600); //B
	glEnd();
	//braço direito
	glBegin(GL_POLYGON);
	glVertex2d((cururu.vx - 18.0) / 600, cururu.vy / 600);//I
	glVertex2d((cururu.vx - 24.0) / 600, (cururu.vy1 + 27.0) / 600);//L
	glVertex2d((cururu.vx - 2.0) / 600, (cururu.vy1 + 27.0) / 600);//K
	glVertex2d((cururu.vx - 2.0) / 600, cururu.vy / 600);//J
	glEnd();
	//corpo
	glBegin(GL_POLYGON);
	glVertex2d((cururu.vx1 + 18.0) / 600, (cururu.vy - 15.0) / 600);//C
	glVertex2d((cururu.vx1 + 18.0) / 600, (cururu.vy1 + 10.0) / 600);//V
	glVertex2d((cururu.vx - 18.0) / 600, (cururu.vy1 + 10.0) / 600);//Q
	glVertex2d((cururu.vx - 18.0) / 600, (cururu.vy - 15.0) / 600);//H
	glEnd();

	//perna esquerda
	glBegin(GL_POLYGON);
	glVertex2d((cururu.vx1 + 2.0) / 600, (cururu.vy1 + 17.0) / 600);//Y
	glVertex2d((cururu.vx1 + 2.0) / 600, cururu.vy1 / 600);//W
	glVertex2d((cururu.vx1 + 18.0) / 600, cururu.vy1 / 600);//X
	glVertex2d((cururu.vx1 + 24.0) / 600, (cururu.vy1 + 17.0) / 600);//Z
	glEnd();
	//perna direita
	glBegin(GL_POLYGON);
	glVertex2d((cururu.vx - 24.0) / 600, (cururu.vy1 + 17.0) / 600);//M
	glVertex2d((cururu.vx - 18.0) / 600, cururu.vy1 / 600);//P
	glVertex2d((cururu.vx - 2.0) / 600, cururu.vy1 / 600);//O
	glVertex2d((cururu.vx - 2.0) / 600, (cururu.vy1 + 17.0) / 600);//N
	glEnd();
	//cabeça
	glBegin(GL_POLYGON);
	glVertex2d((cururu.vx1 + 42.0) / 600, (cururu.vy - 5.0) / 600);//E
	glVertex2d((cururu.vx1 + 42.0) / 600, (cururu.vy - 15.0) / 600);//D
	glVertex2d((cururu.vx - 42.0) / 600, (cururu.vy - 15.0) / 600);//G
	glVertex2d((cururu.vx - 42.0) / 600, (cururu.vy - 5.0) / 600);//F
	glEnd();
	//cauda
	glBegin(GL_POLYGON);
	glVertex2d((cururu.vx1 + 44.0) / 600, (cururu.vy1 + 10.0) / 600);//U
	glVertex2d((cururu.vx1 + 44.0) / 600, (cururu.vy1 + 3.0) / 600);//T
	glVertex2d((cururu.vx - 44.0) / 600, (cururu.vy1 + 3.0) / 600);//S
	glVertex2d((cururu.vx - 44.0) / 600, (cururu.vy1 + 10.0) / 600);//R
	glEnd();
	//fim sapo

	//carros
	for (int i = 0; i < carros.size(); i++) {
		//desenha carro
		glColor3f(carros[i]->r, carros[i]->g, carros[i]->b);
		//corpo
		glBegin(GL_POLYGON);
		glVertex2d(carros[i]->vx / 600, carros[i]->vy / 600);
		glVertex2d(carros[i]->vx / 600, carros[i]->vy1 / 600);
		glVertex2d(carros[i]->vx1 / 600, carros[i]->vy1 / 600);
		glVertex2d(carros[i]->vx1 / 600, carros[i]->vy / 600);

		glEnd();

		//movimenta carros 
		carros[i]->vx += carros[i]->vel;
		carros[i]->vy += 0.0;
		carros[i]->vx1 += carros[i]->vel;
		carros[i]->vy1 += 0.0;
		//fimmovimenta carros

		//tratamento de colisão com parede
		if (carros[i]->vx > 600.0 || carros[i]->vx1 < -600.0) {
			carros[i]->vel = carros[i]->vel*-1;
			//cout << "ai ";
			break;
		}
		////fim colisão parede
	}
	//fim carros
	glColor3f(1.0f, 1.0f, 1.0f);
	DesenhaTexto(texto);
	glutSwapBuffers();
	glFlush();
	glutPostRedisplay();
}

void drawfim() {
	glClear(GL_COLOR_BUFFER_BIT);
	strcpy(texto, "         VOCE VENCEU!");
	glColor3f(1.0f, 1.0f, 1.0f);
	DesenhaTexto(texto);
	glFlush();
	glutSwapBuffers();
}

//colisão entre objetos
void colid()
{
	//começo
	for (int i = 0; i < carros.size(); i++) {
		if (cururu.vx1 >= carros[i]->vx1 && cururu.vx1 <= carros[i]->vx) {
			if (cururu.vy >= carros[i]->vy1 && cururu.vy <= carros[i]->vy) {
				cout << "ops me acidentei 1 :c" << endl;
				//cont = 1;
				cururu.r = 1;
				cururu.g = 0;
				cururu.b = 0;
				der();
				break;
			}
		}
		else {
			if (cururu.vx >= carros[i]->vx1 && cururu.vx <= carros[i]->vx) {
				if (cururu.vy >= carros[i]->vy1 && cururu.vy <= carros[i]->vy) {
					cout << "ops me acidentei 2 :c" << endl;
					//cont = 1;
					cururu.r = 1;
					cururu.g = 0;
					cururu.b = 0;
					der();
					break;
				}
			}
			else {
				if (cururu.vx1 >= carros[i]->vx1 && cururu.vx1 <= carros[i]->vx) {
					if (cururu.vy1 >= carros[i]->vy1 && cururu.vy1 <= carros[i]->vy) {
						cout << "ops me acidentei 3 :c" << endl;
						//cont = 1;
						cururu.r = 1;
						cururu.g = 0;
						cururu.b = 0;
						der();
						break;
					}
				}
				else {
					if (cururu.vx >= carros[i]->vx1 && cururu.vx <= carros[i]->vx) {
						if (cururu.vy1 >= carros[i]->vy1 && cururu.vy1 <= carros[i]->vy) {
							cout << "ops me acidentei 4 :c" << endl;
							//cont = 1;
							cururu.r = 1;
							cururu.g = 0;
							cururu.b = 0;
							der();
							break;
						}
					}
				}
			}
		}
	}

	//fim
	glutPostRedisplay();
}
//colisão entre objetos

//init
void initVar(void)
{
	glClearColor(0.190, 0.190, 0.190, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	win = 0.8;
	strcpy(texto, "FROG: Consegue atravessar?");

}

//teclado
void keyboard(unsigned char c, int x, int y)
{
	switch (c)
	{
	case 'a':
		//Beep(750, 150);
		if (cururu.vx1 > -600.0)
		{
			cururu.vx -= cururu.vel;
			cururu.vx1 -= cururu.vel;
		}
		break;
	case 'd':
		//Beep(750, 150);
		if (cururu.vx < 600.0)
		{
			cururu.vx += cururu.vel;
			cururu.vx1 += cururu.vel;
		}
		break;
	case 'w':
		//Beep(750, 150);
		if (cururu.vy < 600.0)
		{
			cururu.vy += cururu.vel;
			cururu.vy1 += cururu.vel;
		}
		break;
	case 's':
		//Beep(750, 150);
		if (cururu.vy1 > -600.0)
		{
			cururu.vy -= cururu.vel;
			cururu.vy1 -= cururu.vel;
		}
		break;
	}
	if (cururu.vy1 > 300.0 && cururu.vy > 300.0) {
		vic();
	}
}

