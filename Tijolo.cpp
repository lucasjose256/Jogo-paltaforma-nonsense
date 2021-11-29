#include"Tijolo.h"
Tijolo::Tijolo(const float pos_x, const float pos_y) :Obstaculo(pos_x, pos_y)
{
	setTexture();
	setSprite();
	setFisica();
	clock.restart();
	sprite.setPosition(pos_x, pos_y);
	setTipo(4);

}

Tijolo::~Tijolo()
{
}
void Tijolo::setSprite()
{
	sprite.setTexture(texture);
	sprite.setScale(0.2f, 0.2f);
}

void Tijolo::setTexture()
{
	try
	{
		texture.loadFromFile("texturas/brick.png");
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what();
	}
}

void Tijolo::render(sf::RenderTarget* target)
{
	target->draw(sprite);
}

void Tijolo::setFisica()
{
	setVelocidadeX(-0.5f);
}


void Tijolo::mover()
{

	/*if (clock.getElapsedTime().asSeconds() >= 1.5) {
		setVelocidadeX(-getVelocidadeX());
		clock.restart();
	}
	sprite.move(sf::Vector2f(getVelocidadeX(), getVelocidadeY()));*/
}

void Tijolo::causaDano()
{
	dano = false;
}
