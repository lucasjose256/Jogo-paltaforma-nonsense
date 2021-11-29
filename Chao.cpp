#include"Chao.h"
Chao::Chao(const float pos_x, const float pos_y) :Obstaculo(pos_x, pos_y)
{
	setTexture();
	setSprite();
	setFisica();
	clock.restart();
	sprite.setPosition(pos_x, pos_y);
	setTipo(6);

}

Chao::~Chao()
{
}
void Chao::setSprite()
{
	sprite.setTexture(texture);
}

void Chao::setTexture()
{
	try
	{
		texture.loadFromFile("texturas/tijolo.png");
	}
	catch (const std::exception& )
	{
	}
}

void Chao::render(sf::RenderTarget* target)
{
	target->draw(sprite);
}

void Chao::setFisica()
{
	setVelocidadeX(-0.5f);
}


void Chao::mover()
{

	/*if (clock.getElapsedTime().asSeconds() >= 1.5) {
		setVelocidadeX(-getVelocidadeX());
		clock.restart();
	}
	sprite.move(sf::Vector2f(getVelocidadeX(), getVelocidadeY()));*/
}

void Chao::causaDano()
{
	dano = false;
}
