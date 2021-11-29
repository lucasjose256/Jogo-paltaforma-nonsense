#include"Slime.h"
Slime::Slime(const float pos_x, const float pos_y) :Inimigo(pos_x, pos_y)
{
	setTexture();
	setSprite();
	setFisica();
	clock.restart();
	sprite.setPosition(pos_x, pos_y);
	setTipo(8, true);
	setVida(300);
}

Slime::~Slime()
{
	delete(fase);
	fase = nullptr;
}
void Slime::setSprite()
{
	sprite.setTexture(texture);
	sprite.setScale(0.2f, 0.5f);
}

void Slime::setTexture()
{
	try
	{
		texture.loadFromFile("texturas/slime.png");
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what();
	}
}

void Slime::render(sf::RenderTarget* target)
{
	target->draw(sprite);
}

void Slime::setFisica()
{
	setVelocidadeX(-1.f);
}

void Slime::updateSlime()
{

}

void Slime::mover()
{

	if (clock.getElapsedTime().asSeconds() >= 2) {
		setVelocidadeX(-getVelocidadeX());
		clock.restart();
	}
	sprite.move(sf::Vector2f(getVelocidadeX(), getVelocidadeY()));
}

void Slime::operator--()
{
	Personagem::vida -= 20;
}
