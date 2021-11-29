#pragma once
#include<iostream>
#include"Entidade.h"
#include<SFML/Graphics.hpp>
class Menu : public Entidade
{
private:
	int opc;
	int selectedIndex;
	sf::Font fonte;
	sf::Text text[6];
	sf::RenderWindow* w;
	float altura, largura;
public:
	Menu(const float altura, const float largura);
	~Menu();
	void iniciaJogo1();
	void iniciaJogo2();
	void mostraScore();
	void iniciaCemiterio();
	void iniciaCastelo();
	void moveUp();
	void moveDown();
	int  getIndex() { return selectedIndex; };
	void setWindow(sf::RenderWindow* w) { this->w = w; };
	void sair();
	void setSprite();
	void setTexture();
	void  render(sf::RenderTarget* target);
	const int getTipoEntidade()const { return 0; }
	void setTipo() {};
};

