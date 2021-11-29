#include"Jogador.h"
#include <time.h>
#include <ctime>
Jogador::Jogador()
{
	setTexture();
	setSprite();
	setFisica();
	//pontos = 0;
}

Jogador::~Jogador()
{
	//pontos = 0;
}

void Jogador::update()
{
	updateMovimento();
	updateFisica();
}


void Jogador::updateMovimento()
{
	float alturapulo = 20;
	

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		mover(-5.f, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		mover(5.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		mover(0.f, -5.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		mover(0.f, 5.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {

		
		
	//std::cout<<"PULO \n";
		velocidade.y = -sqrt(1.0f * 9.81 * alturapulo);
		

		//achar uma solucao para o boneco não voar
		
	}
}



void Jogador::render(sf::RenderTarget* target)
{
	target->draw(sprite);
}

void Jogador::setSprite()
{
	sprite.setTexture(texture);
	sprite.setScale(0.2f, 0.2f);
	
}

void Jogador::setTexture()
{
	try
	{
		texture.loadFromFile("texturas/simon.png");
	}
	catch (const std::exception&)
	{

	}
	
}

bool Jogador::canJump()
{
	if (this->jumpCooldown >= this->jumpCooldownMax)
	{
		this->jumpCooldown = 0.f;
		return true;
	}

	
	return false;
}

void Jogador::updateJump()
{
	if (this->jumpCooldown < this->jumpCooldownMax)
		this->jumpCooldown += 0.5f;



}



void Jogador::setFisica()
{
	velocidade_max = 8.5f;//troquei de 10 para 8.5,devido as colisoes
	velocidade_min = 1.f;
	aceleracao = 3.f;
	aceleracao_negativa = 0.93f;
	gravidade = 3.f;
	velocidade_max_y = 15.f;
	this->jumpCooldownMax =20;
	this->jumpCooldown = this->jumpCooldownMax;
}

void Jogador::updateFisica()
{
	velocidade.y = velocidade.y + (1.0f * gravidade);
	if (std::abs(velocidade.x) > velocidade_max_y) {
		
		velocidade.y = velocidade_max_y * ((velocidade.y < 0.f) ? -1.f : 1.f);
	}
	velocidade = velocidade  *  aceleracao_negativa;

	if (std::abs(velocidade.x) < velocidade_min) {
		velocidade.x = 0.f;
	}
	if (std::abs(velocidade.y) < velocidade_min) {
		velocidade.y = 0.f;
	}
	sprite.move(velocidade);
}

void Jogador::mover(const float dir_x, const float dir_y) {
	velocidade.x = velocidade.x + (dir_x * aceleracao);
	if (std::abs(velocidade.x) > velocidade_max)
	{
		velocidade.x = velocidade_max * ((velocidade.x < 0.f) ? -1.f : 1.f);
	}
}

void Jogador::mover()
{
	//std::cout << "movejogador" << std::endl;
}
