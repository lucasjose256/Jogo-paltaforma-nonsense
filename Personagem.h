#pragma once
#include "Entidade.h"
class Fase;
class Personagem : public Entidade {
protected:
	int vida;
	
	Fase* fase;
public:
	Personagem(int vida = 0);
	~Personagem();
	void setFase(Fase* fase);
	Fase* getFase();
	void setVida(int vida);
	int getVida();
	void setTipo() {};
	
};

