#include"Pipe.h"

Pipe::Pipe(const float pos_x, const float pos_y) :Obstaculo(pos_x, pos_y)
{
	setTexture();
	setSprite();
	causaDano();
	sprite.setPosition(pos_x, pos_y);
	setTipo(2);
	
}

Pipe::~Pipe()
{
}
void Pipe::setSprite()
{
	sprite.setTexture(texture);
	sprite.setScale(0.1f, 0.1f);
}

void Pipe::setTexture()
{
	try
	{
		texture.loadFromFile("texturas/pipe.png");
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what();
	}
}

void Pipe::setFisica()
{
	//std::cout << "FISICA Pipe" << std::endl;
}

void Pipe::render(sf::RenderTarget* target)
{
	target->draw(sprite);
}
void Pipe::mover()
{
	//std::cout << "Move Tijolo" << std::endl;
}

void Pipe::causaDano()
{
	dano = false;
}

