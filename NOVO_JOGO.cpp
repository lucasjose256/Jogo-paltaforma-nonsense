#include"Jogo.h"
#include <iostream>


int main()
{
    bool running = true;
    Jogo jogo;
    while(jogo.getWindow()->isOpen()) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
            running = false;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
            running = true;
        }
        if (running) {
            jogo.render();
            jogo.update();
        }
        
    }
    jogo.salvar();
  
}
