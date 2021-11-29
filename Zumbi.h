#pragma once
#include"Inimigo.h"
class Zumbi :public Inimigo
{
private:
public:
	
	Zumbi(const float pos_x, const float pos_y);
	~Zumbi();
	void setSprite();
	void setTexture();
	void  render(sf::RenderTarget* target);
	void mover();
	void setFisica();

};


