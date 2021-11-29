#pragma once
#include "Personagem.h"
#include"Fase.h"

Personagem::Personagem(int vida) {
	setVida(vida);
}

Personagem::~Personagem() {
	delete(fase);
	fase = nullptr;
}

void Personagem::setFase(Fase* fase)
{
	this->fase = fase;
}

Fase* Personagem::getFase()
{
	return fase;
}

void Personagem::setVida(int vida) {
	this->vida = vida;
}

int Personagem::getVida() {
	return vida;
}





