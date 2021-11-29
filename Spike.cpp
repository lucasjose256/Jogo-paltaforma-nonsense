#include"Spike.h"
Spike::Spike(const float pos_x, const float pos_y) :Obstaculo(pos_x, pos_y)
{
	setTexture();
	setSprite();
	causaDano();
	sprite.setPosition(pos_x, pos_y);
	setTipo(5);
}

Spike::~Spike()
{
}
void Spike::setSprite()
{
	sprite.setTexture(texture);
	sprite.setScale(0.2f, 0.2f);
}

void Spike::setTexture()
{
	try
	{
		texture.loadFromFile("texturas/spike.png");
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what();
	}
}

void Spike::setFisica()
{
	//std::cout << "FISICA SPIKE" << std::endl;
}

void Spike::render(sf::RenderTarget* target)
{
	target->draw(sprite);
}
void Spike::mover()
{
	//std::cout << "Move Tijolo" << std::endl;
}

void Spike::causaDano()
{
	dano = true;
}
