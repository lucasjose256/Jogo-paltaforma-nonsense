#include"Entidade.h"

Entidade::Entidade()
{
}

Entidade::~Entidade()
{
}

void Entidade::setVelocidade(sf::Vector2f velocidade)
{
	this->velocidade.x = velocidade.x;
	this->velocidade.y = velocidade.y;
}
void Entidade::mover(){}

