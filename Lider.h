#pragma once
#include "ClasePadre.h"
using namespace System::Windows::Forms;
enum direccion { arriba, abajo, izquierda, derecha, ninguno };
template <class Tipo> 
class Lider :public ClasePadre{
private:
	direccion dir;
public:
	Lider(Tipo ancho, Tipo alto) {
		this->ancho = ancho;
		this->alto = alto;
		dx = dy = 4;
		idY = idX = 0;
	}
	Lider(Tipo x, Tipo y, Tipo ancho, Tipo alto) :ClasePadre(x, y, ancho, alto) {
		dx = dy = 4;
	
		idY = idX = 0;
	}
	~Lider() {}
	void dibujar(Graphics^ g, Bitmap^ bmp) {
		float anchoImg = bmp->Width / 4;
		float altoImg = bmp->Height / 4;
		Rectangle rectOrigen = Rectangle(idX * anchoImg, idY * altoImg, anchoImg, altoImg);
		Rectangle rectDestino = Rectangle(x, y, ancho, alto);
		g->DrawImage(bmp, rectDestino, rectOrigen, GraphicsUnit::Pixel);
	}
	void obtenertecla(Keys e) {
		switch (e)
		{
		case Keys::Up:dir = arriba; break;
		case Keys::Down:dir = abajo; break;
		case Keys::Right:dir = derecha; break;
		case Keys::Left:dir = izquierda; break;
		default:
			dir = ninguno;
			break;
		}
	}
	void mover(Graphics^ g) {
		switch (dir)
		{
		case arriba:
			if (y + dy > 0) {
				y = y - dy;
				idY = 3;
				idX++;
				if (idX > 3) {
					idX = 0;
				}
			}
			break;
		case abajo:
			if (y + dy + alto < g->VisibleClipBounds.Height) {
				y = y + dy;
				idY = 0;
				idX++;
				if (idX > 3) {
					idX = 0;
				}
			}
			break;
		case derecha:
			if (x + dx + ancho < g->VisibleClipBounds.Width) {
				x = x + dx;
				idY = 2;
				idX++;
				if (idX > 3) {
					idX = 0;
				}
			}
			break;
		case izquierda:
			if (x + dx > 0) {
				x = x - dx;
				idY = 1;
				idX++;
				if (idX > 3) {
					idX = 0;
				}
			}
			break;
		case ninguno:
			x += 0;
			y += 0;
			break;
		default:
			break;
		}
	}
	int getX() { return x; }
	int getY() { return y; }
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }

};
	