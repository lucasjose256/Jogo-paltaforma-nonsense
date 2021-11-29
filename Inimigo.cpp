#include"Inimigo.h"
Inimigo::Inimigo(const float pos_x, const float pos_y)
{
	setInimigo();
	
}

Inimigo::~Inimigo()
{
}

void Inimigo::setInimigo()
{
	hp =     0;
    hpMax = 10;
	dano  =  1;
	pontos = 5;
	tipo =   0;
}


void Inimigo::update()
{
}

void Inimigo::setTipo(int id_inimigo, bool is_chefao)
{
	id = id_inimigo;
	chefao = is_chefao;
}





