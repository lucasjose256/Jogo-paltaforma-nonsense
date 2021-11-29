#pragma once
#include "Jogador.h"
#include<iostream>
#include<vector>
#include"ListaEntidades.h"
#include"Castelo.h"
#include"Cemiterio.h"
#include"Menu.h"
#include"Projetil.h"
#include<map>
#include<stdio.h>
#include<string.h>
#include"Gerenciador_de_colisoes.h"
#include<chrono>
#include<ctime>
#include <fstream>
#include <string>
class Jogo
{

private:
	
	Gerenciador_de_colisoes* G_D_C;//fazer o gerenciador na classe JOGO
	sf::RenderWindow *gameWindow;
	sf::View *view;
	sf::Event evento;
	Jogador *jogador;
	ListaEntes *lista;
	Castelo* castelo;
	Cemiterio* cemiterio;
	Menu* menu;
	std::vector<Projetil*> proj;
	std::map<std::string, sf::Texture*>textures;

public:
	Jogo();
	~Jogo();
	void render();
	void update();
	void setPlayer();
	void renderPlayer();
	void updatePlayer();
	void setWindow();
	void setJogo();
	void renderPrj();
	void updateProjetil();
	void iniTextures();//lucas
	void setColisoes();
	//essa aqui vai na classe  pra gerenciar a colisao;
	void updateColisao();
	const sf::RenderWindow *getWindow() const { return gameWindow; };
	void  setFase(const int fase = 0);
	void renderInimigos(Fase* fase);
	void createMenu();
	void opcMenu(const int indexMenu, sf::RenderWindow* menuWindow);
	void executar();
	void setView();
	const sf::View* getView() const { return view; };
	void renderFase(Fase* fase);
	void execCastelo();
	void execCemiterio();
	void salvar();
	void mostraScore();
};

