#include "Cenario.h"

Cenario::Cenario(sf::RenderWindow* backgroud)
{
	setWindow(backgroud);
	criaCenario();
}

Cenario::~Cenario()
{
}

void Cenario::criaCenario()
{

	textCen->loadFromFile("texturas/castelo_novo.png");

	this->body.setTexture(textCen);
	this->body.setSize(sf::Vector2f(1000, 800));
	

}
