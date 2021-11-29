#pragma once
#include"ListaEntidades.h"
#include"Jogador.h"
#include"Cenario.h"
class Fase
{
protected:
	
	ListaEntes* lista;
	Jogador* jogador_1;
	sf::Sprite spriteFase;
	sf::Texture textureFase;
	sf::RenderWindow  *window;
	float size_y;
	float size_x;
	bool chefaoVivo;

public:
	Fase(sf::RenderWindow*w = nullptr,Jogador* j= nullptr);
	~Fase();
	virtual void setSprite() = 0;
	virtual void setEntes() = 0;
	void setListaEntes();
	ListaEntes* getList() const { return lista; };
	void render(sf::RenderTarget*  target);
	void draw();
	//sf::RenderWindow* getWindow() const { return this->w; };
	sf::Sprite getSprite() { return spriteFase; };
	sf::Texture getTexture() { return textureFase; };
	void setSizes(const float  size_x, const float size_y);
	void setCenario(){}
	void setChefaoVivo(bool vivo) { chefaoVivo = vivo; };
	const bool getChefaoVivo() const { 
		//std::cout << chefaoVivo << std::endl;
		return chefaoVivo; };
};

