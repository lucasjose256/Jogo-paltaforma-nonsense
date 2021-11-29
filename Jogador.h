#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include "Personagem.h"
class Jogador:public Personagem
{
private:
	sf::Sprite sprite;
	sf::Texture texture;
	bool vivo;
	float jumpCooldown;
	float jumpCooldownMax;
	int pontos;

public:
	Jogador();
	~Jogador();
	void update();
	void updateFisica();
	void render(sf::RenderTarget  *target);
	void updateMovimento();
	void mover(const float dir_x, const float dir_y);
	void mover();
	void setSprite();
	void setFisica();
	void setTexture();
	const sf::FloatRect  getGlobalBounds() const { return sprite.getGlobalBounds(); };
	void resetVelocidadeY() { velocidade.y = 0.f; };
	void resetVelocidadeX() { velocidade.x = 0.f; };
	void setPosicao(const float x, const float y) { sprite.setPosition(x, y); };
	sf::Vector2f getPosicao() { return sprite.getPosition(); };
	const sf::Vector2f getPosForBullet()const { return sprite.getPosition(); };
	void SetverificaSeestaVivo(bool vivo = true) { this->vivo = vivo; };
	bool getverificaSeestaVivo() { return this->vivo; }
	bool canJump();
	void updateJump();
	void operator++() { this->pontos = this->pontos + 1; };
	const int getPontos() const { return this->pontos; };
};

