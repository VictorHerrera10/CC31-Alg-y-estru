#pragma once
#include"ClasePadre.h"
template <class Tipo> 
class Aliado :public ClasePadre {
private:
	bool visible;
	bool atrapo;
public:
	Aliado(Tipo x, Tipo y, Tipo ancho, Tipo alto) :ClasePadre(x, y, ancho, alto) {
		dx = dy = 4;
		idY = idX = 0;
		visible = true;
		atrapo = false;
	}
	~Aliado() {}
	void dibujar(Graphics^ g, Bitmap^ bmpAliado) {
		Bitmap^ bmp;
		bmp = bmpAliado;
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
	void moverPerseguir(Graphics^ g, int X, int Y) {
		int i = rand() % 5;
		dx = dy = 5;
		if (x + dx > 0 && x + dx + ancho < g->VisibleClipBounds.Width &&
			y + dy > 0 && y + dy + alto < g->VisibleClipBounds.Height) {
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
	bool getVisible() { return visible; }
	void setVisible(Tipo v) { visible = v; }
	void setAtrapo(Tipo v) { atrapo = v; }
	bool getAtrapo() { return atrapo; }
};
