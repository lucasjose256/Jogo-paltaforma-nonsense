#pragma once
#include "Fase.h"
#include"Pipe.h"
#include"Zumbi.h"
#include"Spike.h"
#include<vector>
#include "ListaEntidades.h"
#include"Projetil.h"
#include "Medusa.h"
#include"Lista.h"
class Gerenciador_de_colisoes
{
private:
	sf::RenderWindow* gameWindow;
	ListaEntes* listaColisoes;
	ListaEntes* listEnt;
	Jogador* j1;
	std::map<std::string, sf::Texture*>textures;
	std::vector<Projetil*> proj;
	float cooldownattack;
	float cooldownattackMax;
public:
	
	Gerenciador_de_colisoes(Jogador* j1, ListaEntes* lista, std::vector<Projetil*> proj, sf::RenderWindow* gameWindow);
	~Gerenciador_de_colisoes();
	void setPosParaColisao();
	void renderizaProjetil();
	void updateAttack();
	bool canAttack();
	void updateColisaoProjetil();
	void iniTexturesProj();
	void moveProjetil();
};

