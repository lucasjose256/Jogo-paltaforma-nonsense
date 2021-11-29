#include"Medusa.h"
Medusa::Medusa(const float pos_x, const float pos_y):Inimigo(pos_x,pos_y)
{
	setTexture();
	setSprite();
	setFisica();
	clock.restart();
	sprite.setPosition(pos_x, pos_y);
	setTipo(1,false);

}

Medusa::~Medusa()
{
}
void Medusa::setSprite()
{
	sprite.setTexture(texture);
	sprite.setScale(0.4f, 0.4f);
}

void Medusa::setTexture()
{
	try
	{
		texture.loadFromFile("texturas/medusa.png");
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what();
	}
}

void Medusa::render(sf::RenderTarget* target)
{
	target->draw(sprite);
}

void Medusa::setFisica()
{
	setVelocidadeX(-5.f);
}

void Medusa::updateMedusa()
{
}

void Medusa::mover()
{
	  
	if (clock.getElapsedTime().asSeconds() >= 2) {
		setVelocidadeX(-getVelocidadeX());
		clock.restart();
	}
	sprite.move(sf::Vector2f(getVelocidadeX(),getVelocidadeY()));
}
