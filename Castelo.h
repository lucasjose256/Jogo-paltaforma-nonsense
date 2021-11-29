#pragma once
#include"Fase.h"
#include"Medusa.h"
#include"Zumbi.h"
#include"Spike.h"
#include"Tijolo.h"
#include"Pipe.h"
#include"Chao.h"
#include"Diabo.h"
#include"Gerenciador_de_colisoes.h"
#include<stdlib.h>
#include<ctime>
class Castelo : virtual public Fase
{
private:
	int id;
	Gerenciador_de_colisoes *G_D_C;
	Jogador *j1;
	bool chefaoVivo;
public:
	void setSprite();
	void setEntes();
	ListaEntes* getListaEntes() const { return lista; };
	void addMedusa();
	void addZumbi();
	void addSpike();
	void addTijolo();
	void addPipe();
	void addChao();
	void addChefao();
	Castelo(sf::RenderWindow* w=nullptr,Jogador* jogador_1 = nullptr);
	~Castelo();
};

