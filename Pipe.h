#pragma once
#pragma once
#include"Obstaculo.h"
class Pipe :public Obstaculo
{
private:
public:
	
	Pipe(const float pos_x, const float pos_y);
	~Pipe();
	void setSprite();
	void setTexture();
	void setFisica();
	void  render(sf::RenderTarget* target);
	void mover();
	void causaDano();

};


