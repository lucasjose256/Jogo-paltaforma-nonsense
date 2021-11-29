#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include<string>
class Entidade
{
protected:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Vector2f velocidade;
	float aceleracao;
	float velocidade_max;
	float velocidade_max_y;
	float velocidade_min;
	float aceleracao_negativa;
	float gravidade;
	float velocidade_x;
	float velocidade_y;
	int id;
public:
	Entidade();
	~Entidade();
	virtual void render(sf::RenderTarget*target) = 0;
	virtual void setSprite() = 0;
	virtual void mover();
	virtual void setTexture() = 0;
	sf::Vector2f getVelocidade() { return velocidade; };
	void setVelocidade(sf::Vector2f velocidade);
	void setVelocidadeX(float vel_x) { velocidade_x = vel_x; };
	float getVelocidadeX() { return velocidade_x; };
	void setVelocidadeY(float vel_y) { velocidade_x = vel_y; };
	float getVelocidadeY() { return velocidade_y; };
	virtual void setTipo() {};
	const int getTipo() const  { return id; };
	sf::Sprite* getSprite() {
		return &sprite;
	}


	
};

