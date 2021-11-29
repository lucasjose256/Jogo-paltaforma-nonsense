#pragma once
#include"Entidade.h"
class Obstaculo:public Entidade
{
protected:
	sf::Clock clock;
	bool dano;

public:
	Obstaculo(const float pos_x, const float pos_y);
	~Obstaculo();
	virtual void setFisica() = 0;
	virtual void causaDano() = 0;
	void setTipo(int id_obstaculo) { id = id_obstaculo; };

};
