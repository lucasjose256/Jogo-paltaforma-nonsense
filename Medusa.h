#pragma once
#include"Inimigo.h"
class Medusa:public Inimigo
{
private:
public:
	Medusa(const float pos_x, const float pos_y);
	~Medusa();
	void setSprite();
	void setTexture();
	const sf::FloatRect  getGlobalBounds() const { return sprite.getGlobalBounds(); };
	void  render(sf::RenderTarget* target);
	void setFisica();
	void  updateMedusa();
	void mover();

};

