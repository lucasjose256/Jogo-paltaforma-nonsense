#include"Zumbi.h"

Zumbi::Zumbi(const float pos_x, const float pos_y) :Inimigo(pos_x, pos_y)
{
	setTexture();
	setSprite();
	setFisica();
	sprite.setPosition(pos_x, pos_y);
	setTipo(3, false);
}

Zumbi::~Zumbi()
{
}
void Zumbi::setSprite()
{
	sprite.setTexture(texture);
	sprite.setScale(0.5f, 0.5f);
}

void Zumbi::setTexture()
{
	try
	{
		texture.loadFromFile("texturas/zumbi_cavaleiro.png");
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what();
	}
}

void Zumbi::render(sf::RenderTarget* target)
{
	target->draw(sprite);
}

void Zumbi::mover()
{
	if (clock.getElapsedTime().asSeconds() >= 1.5) {
		setVelocidadeX(-getVelocidadeX());
		clock.restart();
	}
	sprite.move(sf::Vector2f(getVelocidadeX(), getVelocidadeY()));
}
void Zumbi::setFisica()
{
	setVelocidadeX(-0.5f);
}
