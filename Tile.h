#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
class Tile
{

private:
	sf::Sprite sprite;
	const bool dano;
public:
	Tile(sf::Texture  &textura,  const bool causa_dano = false);
	~Tile();
	const sf::FloatRect getGlobalBounds() const { return sprite.getGlobalBounds(); };
	void update();
	void render(sf::RenderTarget &target);
	const int getTipoEntidade()const { return 0; }

};

