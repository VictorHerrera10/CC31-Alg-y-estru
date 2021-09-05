#pragma once
#include"ClasePadre.h"
class Objeto : public ClasePadre {
	bool visible;
public:
	Objeto() {
		x = rand() % 700;
		y = rand() % 200;
		visible = true;
	}
	~Objeto() {}
	void Mostrar(Graphics^ g, Bitmap^ img)
	{
		ancho = img->Width;
		alto = img->Height;
		g->DrawImage(img, x, y, ancho, alto);

	}
	void setVisible(bool v) { visible = v; }
	bool getVisible() { return visible; }
	int getX() { return x; }
	int getY() { return y; }
	int getW() { return ancho; }
	int getH() { return alto; }
};