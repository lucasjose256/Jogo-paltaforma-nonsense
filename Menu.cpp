#include"Menu.h"

Menu::Menu(const float altura, const float largura)
{
	this->altura = altura;
	this->largura = largura;
	setSprite();


}

Menu::~Menu()
{
}

void Menu::render(sf::RenderTarget* target)
{
	for (int i = 0; i < 6; i++) {
		target->draw(text[i]);
	}
}


void Menu::iniciaJogo1()
{
	//std::cout << "JOGO 1 JOGADOR" << std::endl;
}

void Menu::iniciaJogo2()
{
	//std::cout << "JOGO 2 JOGADOR" << std::endl;
}

void Menu::mostraScore()
{
	//std::cout << "JOGO MOSTRA SCORE" << std::endl;
}

void Menu::iniciaCemiterio()
{
	//std::cout << "INICIA CEMITERIO" << std::endl;
}

void Menu::iniciaCastelo()
{
	//std::cout << "INICIA CASTELO" << std::endl;
}

void Menu::moveUp()
{
	if (selectedIndex - 1 >= 0) {
		text[selectedIndex].setFillColor(sf::Color::Green);
		selectedIndex--;
		text[selectedIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::moveDown()
{
	if (selectedIndex + 1 < 6) {
		this->text[selectedIndex].setFillColor(sf::Color::Green);
		selectedIndex++;
		this->text[selectedIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::setSprite()
{
	w = nullptr;
	opc = -1;
	selectedIndex = 0;
	if (!fonte.loadFromFile("slime.ttf")) {
		//std::cout << "ERRO AO LER FONTE" << std::endl;
	}

	text[0].setFont(fonte);
	text[0].setFillColor(sf::Color::Green);
	text[0].setString("1 JOGADOR");
	text[0].setPosition(sf::Vector2f(altura / 4, largura / 9 * 1));

	text[1].setFont(fonte);
	text[1].setFillColor(sf::Color::Green);
	text[1].setString("2 JOGADORES");
	text[1].setPosition(sf::Vector2f(altura / 4, largura / 9 * 2));

	text[2].setFont(fonte);
	text[2].setFillColor(sf::Color::Green);
	text[2].setString("CASTELO");
	text[2].setPosition(sf::Vector2f(altura / 4, largura / 9 * 3));

	text[3].setFont(fonte);
	text[3].setFillColor(sf::Color::Green);
	text[3].setString("CEMITERIO");
	text[3].setPosition(sf::Vector2f(altura / 4, largura / 9 * 4));

	text[4].setFont(fonte);
	text[4].setFillColor(sf::Color::Green);
	text[4].setString("SCORE");
	text[4].setPosition(sf::Vector2f(altura / 4, largura / 9 * 5));

	text[5].setFont(fonte);
	text[5].setFillColor(sf::Color::Green);
	text[5].setString("SAIR");
	text[5].setPosition(sf::Vector2f(altura / 4, largura / 9 * 6));
}

void Menu::setTexture()
{
}

void Menu::sair()
{
}
