#pragma once
#pragma once
#include"Obstaculo.h"
class Chao :public Obstaculo
{
private:
public:
	Chao(const float pos_x, const float pos_y);
	~Chao();
	void setSprite();
	void setTexture();
	void setFisica();
	void  render(sf::RenderTarget* target);
	void mover();
	void causaDano();
};


