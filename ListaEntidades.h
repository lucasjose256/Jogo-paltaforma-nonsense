#pragma once
#include "Lista.h"
#include "Entidade.h"

class ListaEntes {
private:
	Lista<Entidade> lista;
	int tam;
public:
	ListaEntes();
	~ListaEntes();
	void push(Entidade* p);
	void pop(Entidade* p);
	Lista<Entidade>::Elemento* getPrim();
	int getTam() { return tam; };
};



