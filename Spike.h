#pragma once
#include"Obstaculo.h"
class Spike :public Obstaculo
{
private:
public:
	Spike(const float pos_x, const float pos_y);
	~Spike();
	void setSprite();
	void setTexture();
	void setFisica();
	void  render(sf::RenderTarget* target);
	void  mover();
	void causaDano();

};


