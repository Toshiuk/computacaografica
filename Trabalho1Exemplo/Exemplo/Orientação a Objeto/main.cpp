#include "Object.h"
#include "Quadrado.h"
void main()
{
	Object meuQueridoObjeto;
	//meuQueridoObjeto.print();
	meuQueridoObjeto.rotate(10, 20, 30);
	//meuQueridoObjeto.print();

	cout << endl << endl;

	Quadrado meuQuadrado;
	meuQuadrado.print();
	meuQuadrado.rotate(1, 2, 3);
	meuQuadrado.print();
	system("pause");

}