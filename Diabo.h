#pragma once
#include"Inimigo.h"
class Fase;
class Diabo :public Inimigo
{
private:
	Fase* fase;
public:
	Diabo(const float pos_x, const float pos_y);
	~Diabo();
	void setSprite();
	void setTexture();
	const sf::FloatRect  getGlobalBounds() const { return sprite.getGlobalBounds(); };
	void  render(sf::RenderTarget* target);
	void setFisica();
	void mover();
	void operator--();
	void setFase(Fase* pFase) { fase = pFase; };
	Fase* getFase() { return fase; };

};

