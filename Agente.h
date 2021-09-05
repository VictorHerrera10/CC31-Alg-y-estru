#pragma once
#include"ClasePadre.h"
template <class Tipo>
class Agente :public ClasePadre {
private:
	bool visible;
public:
	Agente(Tipo x, Tipo y, Tipo ancho, Tipo alto) :ClasePadre(x, y, ancho, alto) {
		dx = dy = 4;
		idY = idX = 0;
	}
	~Agente() {}
	void dibujar(Graphics^ g, Bitmap^ bmp) {
		float anchoImg = bmp->Width / 4;
		float altoImg = bmp->Height / 4;
		Rectangle rectOrigen = Rectangle(idX * anchoImg, idY * altoImg, anchoImg, altoImg);
		Rectangle rectDestino = Rectangle(x, y, ancho, alto);
		g->DrawImage(bmp, rectDestino, rectOrigen, GraphicsUnit::Pixel);
	}
	void mover(Graphics^ g, int X, int Y) {
		int i = rand() % 5;
		if (x + dx > 0 && x + dx + ancho < g->VisibleClipBounds.Width && y + dy > 0 && y + dy + alto < g->VisibleClipBounds.Height) {
			if (i == 1 && x < X) {
				idY = 2;
				x += dx;
			}
			if (i == 2 && x > X) {
				idY = 1;
				x -= dx;
			}
			if (i == 4 && y < Y) {
				idY = 0;
				y += dy;
			}
			if (i == 4 && y > Y) {
				idY = 3;
				y -= dy;
			}
			idX++;
		}
		if (idX > 3)idX = 0;
	}

};
