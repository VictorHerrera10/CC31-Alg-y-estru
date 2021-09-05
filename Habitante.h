#pragma once
#include"ClasePadre.h"
template <class Tipo> 
class Habitante :public ClasePadre {

public:
	Habitante(Tipo x, Tipo y, Tipo ancho, Tipo alto) :ClasePadre(x, y, ancho, alto) {
		dx = dy = 1;
		idY = idX = 0;
	}
	~Habitante() {}
	void dibujar(Graphics^ g, Bitmap^ bmp) {
		float anchoImg = bmp->Width / 4;
		float altoImg = bmp->Height / 4;
		Rectangle rectOrigen = Rectangle(idX * anchoImg, idY * altoImg, anchoImg, altoImg);
		Rectangle rectDestino = Rectangle(x, y, ancho, alto);
		g->DrawImage(bmp, rectDestino, rectOrigen, GraphicsUnit::Pixel);
	}
	void mover(Graphics^ g) {

		if (x + dx < 0 || x + dx + ancho > g->VisibleClipBounds.Width) {
			dx *= -1;
		}
		if (y + dy<0 || y + dy + alto>g->VisibleClipBounds.Height) {
			dy *= -1;
		}
		x += dx;
		y += dy;
		if (dx > 0) {
			idY = 2;
		}
		if (dx < 0) {
			idY = 1;
		}
		if (dy > 0) {
			idY = 0;
		}
		if (dy < 0) {
			idY = 3;
		}
		idX++;
		if (idX > 3)idX = 0;
	}
};
