#pragma once
#include"SFML/Graphics.hpp"
class Projetil
{
private:
	sf::Sprite body;
	sf::Texture textura;
	sf::Vector2f dir;
	float mov_speed;
public:
	Projetil();
	Projetil(sf::Texture* textura, float pos_x, float pos_y, float x_dir, float y_dir, float mov_speed);
	~Projetil();
	void update();
	void render(sf::RenderTarget* target);
	 const sf::FloatRect getBoundPrj() const;
};
