#pragma once
#include"Inimigo.h"
class Slime :public Inimigo
{
private:
	Fase* fase;
public:
	Slime(const float pos_x, const float pos_y);
	~Slime();
	void setSprite();
	void setTexture();
	const sf::FloatRect  getGlobalBounds() const { return sprite.getGlobalBounds(); };
	void  render(sf::RenderTarget* target);
	void setFisica();
	void  updateSlime();
	void setFase(Fase* pFase) { fase = pFase; };
	Fase* getFase() { return fase; };
	void mover();
	void operator--();

};