#pragma once
#include<SFML/Graphics.hpp>
#include "Entidade.h"
class Cenario
{
private:
    sf::RectangleShape body;
    sf::Texture* textCen;
    sf::RenderWindow* backgroud;
public:
    Cenario(sf::RenderWindow* backgroud);
    ~Cenario();
    void criaCenario();
    void desenhaCenario(sf::RenderWindow* backgroud) { backgroud->draw(body); }
    void setWindow(sf::RenderWindow* window) {
        this->backgroud = window;
    }

    sf::RectangleShape getBody() {
        return body;
    }
    const int getTipoEntidade()const { return 0; }
};