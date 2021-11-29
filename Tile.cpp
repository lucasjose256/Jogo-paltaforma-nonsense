#include"Tile.h"
Tile::Tile(sf::Texture& textura, const bool causa_dano):
	dano(causa_dano)
{
	sprite.setTexture(textura);
}

Tile::~Tile()
{
}

void Tile::update()
{
}

void Tile::render(sf::RenderTarget& target)
{
	target.draw(sprite);
}
