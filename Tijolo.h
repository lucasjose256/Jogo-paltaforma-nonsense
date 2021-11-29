#pragma once
#include"Obstaculo.h"
class Tijolo:public Obstaculo
{
private:
public:
	Tijolo(const float pos_x, const float pos_y);
	~Tijolo();
	void setSprite();
	void setTexture();
	void setFisica();
	void  render(sf::RenderTarget* target);
	void mover();
	void causaDano();
};


