#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include"Agente.h"
#include"Aliado.h"
#include"Habitante.h"
#include"Lider.h"
#include"Objeto.h"
#include"Pollo.h"
#include <vector>

template <class Tipo> 
class Controladora1 {
private:
	vector<Agente<int>*>misAgentes;
	vector<Aliado<int>*>misAliados;
	vector<Habitante<int>*>misHabitantes;
	vector<Objeto*>misObjetos;
	vector<Pollo<int>*>misPollos;
	Lider<int>* lider;
	int puntos;
	int medicina;
	bool medi;
	int x, y;


public:
	Controladora1(int aliados, int agentes, int habitantes) {
		medicina = aliados;
		string r, x1, y1;
		lider = new Lider<int>(40, 80);
		ifstream archL("Posicion.txt");
		if (archL.is_open()) {
			while (getline(archL, r)) {
				stringstream archL(r);
				getline(archL, x1, '*');
				x = stoi(x1);
				getline(archL, y1);
				y = stoi(y1);
			}
			lider->setX(x);
			lider->setY(y);
			archL.close();
		}




		for (int i = 0; i < aliados; i++) {
			misAliados.push_back(new Aliado<int>(rand() % 600, rand() % 400, 40, 80));
		}
		for (int i = 0; i < agentes; i++) {
			misAgentes.push_back(new Agente<int>(rand() % 600, rand() % 400, 40, 80));
		}
		for (int i = 0; i < habitantes; i++) {
			misHabitantes.push_back(new Habitante<int>(rand() % 600, rand() % 400, 40, 80));
		}
		for (int i = 0; i < medicina; i++) {
			misObjetos.push_back(new Objeto());
		}
		puntos = 0;
		medi = false;
	}
	~Controladora1() {}
	void LeerCords() {	//implementación de archivos planos
		



	
	}
	void agregarPollo() {
		misPollos.push_back(new Pollo<int>(rand() % 600, rand() % 400, 40, 80));
	}
	void dibujarTodo(Graphics^ g, Bitmap^ bmpMapa, Bitmap^ bmpLider, Bitmap^ bmpAgente, Bitmap^ bmpAliado, Bitmap^ bmpHabitante, Bitmap^ bmpObstaculo, Bitmap^ bmpPollo) {

		g->DrawImage(bmpMapa, 0, 0, bmpMapa->Width * 1.2, bmpMapa->Height * 0.8);
		lider->dibujar(g, bmpLider);
		for (int i = 0; i < misObjetos.size(); i++) {
			misObjetos[i]->Mostrar(g, bmpObstaculo);
		}
		for (int i = 0; i < misAgentes.size(); i++) {
			misAgentes[i]->dibujar(g, bmpAgente);
		}
		if (misAliados.size() > 0) {
			for (int i = 0; i < misAliados.size(); i++) {
				misAliados[i]->dibujar(g, bmpAliado);
			}
		}
		if (misPollos.size() > 0) {
			for (int i = 0; i < misPollos.size(); i++) {
				misPollos[i]->dibujar(g, bmpPollo);
			}
		}
		if (misHabitantes.size() > 0) {
			for (int i = 0; i < misHabitantes.size(); i++) {
				misHabitantes[i]->dibujar(g, bmpHabitante);
			}
		}
	}
	void moverTodo(Graphics^ g) {
		lider->mover(g);
		for (int i = 0; i < misAgentes.size(); i++) {
			misAgentes[i]->mover(g, misAliados[i]->getX(), misAliados[i]->getY());
		}
		for (int i = 0; i < misHabitantes.size(); i++) {

			misHabitantes[i]->mover(g);
		}
		if (misPollos.size() > 0) {
			for (int i = 0; i < misPollos.size(); i++) {
				misPollos[i]->mover(g);
			}
		}

		ofstream archE("Posicion.txt");
		archE << lider->getX() << "*" << lider->getY();
		archE.close();
	}
	void moverAliados(Graphics^ g) {
		for (int i = 0; i < misAliados.size(); i++) {
			misAliados[i]->mover(g);
		}
	}
	void Tecla(Keys e) {
		lider->obtenertecla(e);
	}
	void moverBuscar(Graphics^ g) {
		for (int i = 0; i < misAliados.size(); i++) {
			misAliados[i]->moverPerseguir(g, misObjetos[i]->getX(), misObjetos[i]->getY());
		}
	}
	bool colision(ClasePadre* ob1, ClasePadre* ob2)
	{
		Rectangle r1 = Rectangle(ob1->getX(), ob1->getY(), ob1->getW(), ob1->getH());
		Rectangle r2 = Rectangle(ob2->getX(), ob2->getY(), ob2->getW(), ob2->getH());
		return r1.IntersectsWith(r2);
	}
	void Colision() {
		for (int i = 0; i < misAliados.size(); i++)
		{
			if (colision(misAliados.at(i), misAgentes.at(i)))
			{
				misAliados.erase(misAliados.begin() + i);
				misAgentes.erase(misAgentes.begin() + i);
				puntos -= 5;
				break;
			}
		}
		if (medi == true) {
			for (int i = 0; i < misAliados.size(); i++)
			{
				if (colision(misAliados.at(i), misObjetos.at(i)))
				{
					misObjetos.erase(misObjetos.begin() + i);
					misAliados.erase(misAliados.begin() + i);
					misAgentes.erase(misAgentes.begin() + i);
					puntos += 10;
					break;
				}
			}
		}
	}
	int getPuntos() { return puntos; }
	void setMedi(bool v) { medi = v; }
	int getObs() { return misObjetos.size(); }
	int getAli() { return misAliados.size(); }
	int getAge() { return misAgentes.size(); }


};
