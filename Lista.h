#pragma once
#pragma once
#include<iostream>
template <class TIPO>
class Lista {
public:
	class Elemento {
	private:
		Elemento* pProx;
		TIPO* p;
	public:
		Elemento() {
			pProx = NULL;
			p = NULL;
		}
		~Elemento() {}
		void setProx(Elemento* p) { pProx = p; }
		Elemento* getProx() const{ return pProx; }
		void setItem(TIPO* p) { this->p = p; }
		TIPO* getItem() const { return p; }
	};
private:
	Elemento* pPrim;
	Elemento* pAtual;
	//int tam;
public:
	Lista();
	~Lista();
	Elemento* getPrim() { return pPrim; };
	void push(TIPO* p);
	void pop(TIPO* p);
	//int getTam() {return  tam;};
};

template <class TIPO>
Lista<TIPO>::Lista() {
	pPrim = nullptr;
	pAtual = nullptr;
	//tam = 0;
}

template <class TIPO>
Lista<TIPO>::~Lista() {
	Elemento* i = pPrim, * aux;

	while (i != nullptr) {
		aux = i->getProx();
		delete i;
		i = aux;
	}
}

template <class TIPO>
void Lista<TIPO>::push(TIPO* p) {
	//std::cout << "ELEMENTO INSERIDO" << std::endl;
	if (p != nullptr) {
		Elemento* aux = new Elemento();
		aux->setItem(p);

		if (pPrim == nullptr && pAtual == nullptr) {
			pPrim = aux;
			pAtual = aux;
		}
		else {
			pAtual->setProx(aux);
			pAtual = aux;
		}
		//tam++;

	}
}

template <class TIPO>
void Lista<TIPO>::pop(TIPO* p) {
	Elemento* aux = pPrim, * ant = nullptr;

	while (aux->getItem() != p) {
		ant = aux;
		aux = aux->getProx();
	}

	if (aux == pPrim) {
		pPrim = aux->getProx();
	}
	else if (aux == pAtual) {
		ant->setProx(nullptr);
		pAtual = ant;
	}
	else {
		ant->setProx(aux->getProx());
	}
	delete aux->getItem();
	delete aux;
	//tam--;
}
