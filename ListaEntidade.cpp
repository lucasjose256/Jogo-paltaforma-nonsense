#include "ListaEntidades.h"
#include<iostream>

ListaEntes::ListaEntes() {
	//std::cout << "Lista Entes Criada" << std::endl;
	tam = 0;
}

ListaEntes::~ListaEntes() {
}

void ListaEntes::push(Entidade* p) {
	lista.push(p);
	tam++;
}

void ListaEntes::pop(Entidade* p) {
	lista.pop(p);
	tam--;
}



Lista<Entidade>::Elemento* ListaEntes::getPrim() {
	return lista.getPrim();
}
