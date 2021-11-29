#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include"Personagem.h"
class Inimigo:public Personagem
{
protected:
	int hp;
	int hpMax;
	int dano;
	int pontos;
	int tipo;
	sf::Clock clock;
	bool chefao;

public:
	Inimigo(const float pos_x, const float pos_y);
	~Inimigo();
	void setInimigo();
	void update();
	void setTipo(int id_inimigo, bool is_chefao);
};

