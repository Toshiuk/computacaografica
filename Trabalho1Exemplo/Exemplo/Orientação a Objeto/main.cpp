#pragma once
#include "Object.h"
#include "Quadrado.h"
#include "Scene.h"
#include "Line.h"
#include "main.h"
void main(int argc, char **argv)
{
	//Object meuQueridoObjeto;
	//meuQueridoObjeto.print();
	//meuQueridoObjeto.rotate(10, 20, 30);
	//meuQueridoObjeto.print();

	//cout << endl << endl;
	
	//Quadrado meuQuadrado;
	//meuQuadrado.print();
	//meuQuadrado.rotate(1, 2, 3);
	//meuQuadrado.print();
	
	Line linhazinha(-250, 200, 250, 200);
	Line linha2(0, -300, 0 ,200);
	linhazinha.color(1, 0, 0);
	linha2.color(0, 0, 0);
	Scene ceninha(argc, argv);
	
	system("pause");

}