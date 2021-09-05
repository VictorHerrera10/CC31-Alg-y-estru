#pragma once
#include<iostream>
using namespace std;
using namespace System::Drawing; 
class ClasePadre {
protected:
	int x, y;
	int dx, dy;
	int idX, idY;
	int ancho, alto;
public:
	ClasePadre() {}
	ClasePadre(int x, int y, int ancho, int alto) {
		this->x = x;
		this->y = y;
		this->ancho = ancho;
		this->alto = alto;

	}
	~ClasePadre() {}
	virtual void dibujar(Graphics^ g, Bitmap^ bmp) {}
	virtual void mover() {}
	Rectangle getRectangulo() { return Rectangle(x, y, ancho, alto); }
	int getX() { return x; }
	int getY() { return y; }
	int getW() { return ancho; }
	int getH() { return alto; }

};
