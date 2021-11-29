#include"Fase.h"

Fase::Fase(sf::RenderWindow *w, Jogador* j)
{
	this->lista = new ListaEntes();
	//this->w = w;
	jogador_1 = j;
	this->window = window;

}

Fase::~Fase()
{
	jogador_1 = nullptr;
	this->lista = nullptr;
}

void Fase::render(sf::RenderTarget*target)
{
	target->draw(this->spriteFase);

}

void Fase::draw()
{
	this->window->draw(spriteFase);
}

void Fase::setSizes(const float size_x, const float size_y)
{
	this->size_x = size_x;
	this->size_y = size_y;
}

void Fase::setListaEntes()
{
}
