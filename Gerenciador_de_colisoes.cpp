#include "Gerenciador_de_colisoes.h"
#include "Gerenciador_de_colisoes.h"
#include "Diabo.h"
#include "Slime.h"

Gerenciador_de_colisoes::Gerenciador_de_colisoes(Jogador* j1, ListaEntes* lista, std::vector<Projetil*> proj, sf::RenderWindow* gameWindow)
{
	this->j1 = j1;
	this->listaColisoes = lista;
	this->cooldownattackMax =32;
	this->cooldownattack = this->cooldownattackMax;
	this->proj = proj;
	j1->setVida(1000000);
	this->gameWindow = gameWindow;
	iniTexturesProj();
}




Gerenciador_de_colisoes::~Gerenciador_de_colisoes()
{
	delete listaColisoes;
	
	for (auto& i : this->textures) {

		delete i.second;


	}
	for (auto& i : this->proj) {

		delete i;

	}

}

void Gerenciador_de_colisoes::setPosParaColisao()
{
	Lista<Entidade>::Elemento* aux = listaColisoes->getPrim();
	Entidade* entidade{};

	sf::FloatRect nextPos;
	sf::FloatRect playerBounds = j1->getGlobalBounds();
	sf::FloatRect entidadeBounds;
	unsigned counter = 0;
	//fazer com a lista de objetos as colisoes
	// e os inimigos iram em outra funçao,pois se o jogador encostar nele,ele morre
	//Gerenciamento de dano

	
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)&& canAttack()) {

		//std::cout << "BULLET INSERTED" << std::endl;
		this->proj.push_back(new Projetil(this->textures
			["BULLET"], this->j1->getPosForBullet().x, this->j1->getPosForBullet().y, 1.f, 0.f, 6.f));
		//Criar um cool down
	}
	updateAttack();
	for (auto* projetil : this->proj) {

		projetil->update();
	}

	for (int i = 0; i < listaColisoes->getTam(); i++) {
		nextPos = j1->getGlobalBounds();
		nextPos.left += j1->getVelocidadeX();
		nextPos.left += j1->getVelocidadeY();
		entidade = aux->getItem();
		entidadeBounds = entidade->getSprite()->getGlobalBounds();




		
		if (entidadeBounds.intersects(nextPos)) {
			//colisao baixo
		 if (playerBounds.top < entidadeBounds.top
			&& playerBounds.top + playerBounds.height
			< entidadeBounds.top + entidadeBounds.height
			&& playerBounds.left<entidadeBounds.left + entidadeBounds.width
			&& playerBounds.left + playerBounds.width>entidadeBounds.left) {


			j1->setVelocidadeY(0.f);
			
			j1->setPosicao(playerBounds.left, entidadeBounds.top - playerBounds.height);

			if (entidade->getTipo() == 1 || entidade->getTipo() == 3 || entidade->getTipo() == 5) {
				j1->setVida(j1->getVida() - 5);
				if (j1->getVida() <= 0) {
					j1->SetverificaSeestaVivo(true);
				}
			}
			else if (entidade->getTipo() == 7 || entidade->getTipo() == 8) {
				j1->setVida(j1->getVida() - 20);
				if (j1->getVida() <= 0) {
					j1->SetverificaSeestaVivo(true);
				}
			}


		}
			//colisao cima
			else if (playerBounds.top > entidadeBounds.top
				&& playerBounds.top + playerBounds.height
			> entidadeBounds.top + entidadeBounds.height
				&& playerBounds.left<entidadeBounds.left + entidadeBounds.width
				&& playerBounds.left + playerBounds.width>entidadeBounds.left) {
			 

				j1->setVelocidadeY(0.f);

				j1->setPosicao(playerBounds.left, entidadeBounds.top + entidadeBounds.height);
				if (entidade->getTipo() == 1 || entidade->getTipo() == 3 || entidade->getTipo() == 5) {
				//	std::cout << "-20 de vida" << "\n";
					j1->setPosicao(j1->getPosicao().x, j1->getPosicao().y);
					j1->setVida(j1->getVida() - 5);
					if (j1->getVida() <= 0) {
						j1->SetverificaSeestaVivo(true);

					}
				}
				else if (entidade->getTipo() == 7 || entidade->getTipo() == 8) {
					j1->setVida(j1->getVida() - 20);
					if (j1->getVida() <= 0) {
						j1->SetverificaSeestaVivo(true);
					}
				}

			}
		
			
		
			//std::cout << "COLIDIUUUUU" << std::endl;
			//colisao direita
			if (playerBounds.left < entidadeBounds.left
				&& playerBounds.left + playerBounds.width
				< entidadeBounds.left + entidadeBounds.width
				&& playerBounds.top<entidadeBounds.top + entidadeBounds.height
				&& playerBounds.top + playerBounds.height>entidadeBounds.top) {


				j1->setVelocidadeX(0.f);
				j1->setPosicao(entidadeBounds.left - playerBounds.width, playerBounds.top);

				if (entidade->getTipo() == 1 || entidade->getTipo() == 3 || entidade->getTipo() == 5) {

					//std::cout << "-20 de vida" << "\n";

					j1->setPosicao(j1->getPosicao().x - 20, j1->getPosicao().y);
					j1->setVida(j1->getVida() - 5);
					if (j1->getVida() <= 0) {
						j1->SetverificaSeestaVivo(true);
					}
				}
				else if (entidade->getTipo() == 7 || entidade->getTipo() == 8) {
					j1->setVida(j1->getVida() - 20);
					if (j1->getVida() <= 0) {
						j1->SetverificaSeestaVivo(true);
					}
				}

			}

			//colisao esquerda
			else if (playerBounds.left > entidadeBounds.left
				&& playerBounds.left + playerBounds.width
			> entidadeBounds.left + entidadeBounds.width
				&& playerBounds.top<entidadeBounds.top + entidadeBounds.height
				&& playerBounds.top + playerBounds.height>entidadeBounds.top) {


				j1->setVelocidadeX(0.f);
				j1->setPosicao(entidadeBounds.left + entidadeBounds.width, playerBounds.top);
				if (entidade->getTipo() == 1 || entidade->getTipo() == 3 || entidade->getTipo() == 5) {
					j1->setPosicao(j1->getPosicao().x + 15, j1->getPosicao().y);
					j1->setVida(j1->getVida() - 5);
					if (j1->getVida() <= 0) {
						j1->SetverificaSeestaVivo(true);
					}
				}
				else if (entidade->getTipo() == 7 || entidade->getTipo() == 8) {
				j1->setVida(j1->getVida() - 20);
				if (j1->getVida() <= 0) {
					j1->SetverificaSeestaVivo(true);
				}
			}

			}


		}
		aux = aux->getProx(); if (aux == nullptr) { break; }
	}
}

void Gerenciador_de_colisoes::renderizaProjetil()
{
	for (auto* projetil : this->proj) {

		projetil->render(this->gameWindow);
	}


}
void Gerenciador_de_colisoes::updateAttack()
{	if(this->cooldownattack<this->cooldownattackMax)
	this->cooldownattack += 1.f;


}
bool Gerenciador_de_colisoes::canAttack()
{	if (this->cooldownattack >= this->cooldownattackMax)
{
	this->cooldownattack = 0.f;
	return true;
}

	return false;
}
void Gerenciador_de_colisoes::updateColisaoProjetil()
{
	//Lista<Entidade>::Elemento* aux = new Lista<Entidade>::Elemento();
	
	
	sf::FloatRect nextPos;
	sf::FloatRect playerBounds = j1->getGlobalBounds();
	sf::FloatRect entidadeBounds;
	Entidade* entidade{  };

	
	for (auto* projetil : this->proj) {
		unsigned counter = 0;
		projetil->update();
		Lista<Entidade>::Elemento* aux = listaColisoes->getPrim();
		for (int i = 1; i <= listaColisoes->getTam(); i++) {
			 entidade= aux->getItem();
			entidadeBounds = entidade->getSprite()->getGlobalBounds();
			
			if (projetil->getBoundPrj().intersects(entidadeBounds)&&(entidade->getTipo()==1|| entidade->getTipo() == 3)) {
			//	std::cout << "PROJETIL ACERTOU ALGO" << std::endl;
				//listaColisoes->pop(entidade);
				delete this->proj.at(counter);
				this->proj.erase(this->proj.begin() + counter);
				--counter;
				entidade->getSprite()->setPosition(4454545,878788);
				j1->operator++();
				break;
			}

			if (projetil->getBoundPrj().intersects(entidadeBounds) && (entidade->getTipo() == 7))
			{
				Diabo *aux = static_cast<Diabo*>(entidade);
				aux->operator--();
				delete this->proj.at(counter);
				this->proj.erase(this->proj.begin() + counter);
				--counter;
				if (aux->getVida() <= 0) {
					entidade->getSprite()->setPosition(4454545, 878788);
				}
				break;

			}
			
			if (projetil->getBoundPrj().intersects(entidadeBounds) && (entidade->getTipo() == 8))
			{
				Slime* aux = static_cast<Slime*>(entidade);
				aux->operator--();
				delete this->proj.at(counter);
				this->proj.erase(this->proj.begin() + counter);
				--counter;
				if (aux->getVida() <= 0) {
					entidade->getSprite()->setPosition(4454545, 878788);
				}
				break;

			}

			aux = aux->getProx();

			if (aux == nullptr) {
				break; 
			}
		}
		++counter;
	}
}


void Gerenciador_de_colisoes::iniTexturesProj()
{
	textures["BULLET"] = new sf::Texture;
	if (!textures["BULLET"]->loadFromFile("texturas/fogo.png")) {
		//std::cout << "NÃO FOI POSSIVEL ABRIR A IMAGEM BULLET \n";
	}
}
