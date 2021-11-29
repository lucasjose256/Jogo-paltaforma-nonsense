
#include "Projetil.h"

Projetil::Projetil()
{
}

Projetil::Projetil(sf::Texture* textura, float pos_x, float pos_y, float x_dir, float y_dir, float mov_speed)
{
			
			
	this->body.setTexture(*textura);
	this->dir.x = x_dir;
	this->dir.y = y_dir;
	this->mov_speed = mov_speed;
	this->body.setPosition(pos_x, pos_y);

}

Projetil::~Projetil()
{	



}

void Projetil::update()
{
	this->body.move(this->mov_speed*this->dir);

}

void Projetil::render(sf::RenderTarget* target)
{

	target->draw(this->body);
}

const sf::FloatRect Projetil::getBoundPrj() const
{
	return this->body.getGlobalBounds();
}
