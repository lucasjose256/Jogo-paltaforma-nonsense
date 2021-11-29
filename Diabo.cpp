#include"Diabo.h"
#include"Castelo.h"
Diabo::Diabo(const float pos_x, const float pos_y) :Inimigo(pos_x, pos_y)
{
	setTexture();
	setSprite();
	setFisica();
	clock.restart();
	sprite.setPosition(pos_x, pos_y);
	setTipo(7, true);
	setVida(300);
}

Diabo::~Diabo()
{
	delete(fase);
	fase = nullptr;
}
void Diabo::setSprite()
{
	sprite.setTexture(texture);
	sprite.setScale(0.5f,0.5f);
}

void Diabo::setTexture()
{
	try
	{
		texture.loadFromFile("texturas/diabo_3.png");
	}
	catch (const std::exception&)
	{

	}
}

void Diabo::render(sf::RenderTarget* target)
{
	target->draw(sprite);
}

void Diabo::setFisica()
{
	setVelocidadeX(-1.f);
}

void Diabo::mover()
{

	if (clock.getElapsedTime().asSeconds() >= 2) {
		setVelocidadeX(-getVelocidadeX());
		clock.restart();
	}
	sprite.move(sf::Vector2f(getVelocidadeX(), getVelocidadeY()));
}

void Diabo::operator--()
{
	Personagem::vida -= 20;

	if (fase->getChefaoVivo() && Personagem::vida <= 0) {
		fase->setChefaoVivo(false);
	}
}
