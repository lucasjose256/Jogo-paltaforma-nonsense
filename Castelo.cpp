#include "Castelo.h"
Castelo::Castelo(sf::RenderWindow* w ,Jogador* jogador_1) : Fase(w,jogador_1)
{
	setCenario();
	setEntes();
	setSprite();
	w->draw(spriteFase);

}

Castelo::~Castelo()
{
	Lista<Entidade>::Elemento* aux = lista->getPrim();
	while (aux != nullptr) {
		if (aux->getItem()->getTipo() >= 1) {
			delete aux->getItem();
		}
		aux = aux->getProx();
	}
	delete lista;
	G_D_C = nullptr;
	j1 = nullptr;
}


void Castelo::setSprite()
{
	if (!textureFase.loadFromFile("texturas/castelo_novo.png")) {
		std::cout << "[LOG_ERRO] ERRO LER castelo_novo.PNG" << std::endl;
	}

	sf::Vector2u TextureSize;
	TextureSize = textureFase.getSize();
	

	float scaleX = (float)size_x / TextureSize.x;
	float scaleY = (float)size_y / TextureSize.y;
	spriteFase.setTexture(textureFase);
	spriteFase.setScale(scaleX, scaleY);
	spriteFase.setOrigin(sf::Vector2f(50.f, 335.f));
}

void Castelo::setEntes()
{
	addMedusa();
	addZumbi();
	addSpike();
	addTijolo();
	addPipe();
	addChao();
	addChefao();
	
}

void Castelo::addMedusa()
{
	srand((unsigned)time(0));
	int qtd = 3 + (rand() % 7);

	for (int i = 1; i <= qtd; i++) {
		try
		{
			Medusa* aux;
			aux = new Medusa((600.f * i), (500.f));
			lista->push(aux);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what();
		}
		
		
	}

}

void Castelo::addZumbi()
{
	srand((unsigned)time(0));
	int qtd = 3 + (rand() % 10);

	int distancia = 1;
	for (int i = 1; i <= qtd; i++) {
		try
		{
			Zumbi* aux;
			aux = new Zumbi((200.f * (i * distancia)), (650.f));
			lista->push(aux);
			distancia++;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what();
		}
		
	}

}

void Castelo::addSpike()
{
	for (int i = 1; i <= 10; i++) {
		Spike* aux;
		aux = new Spike((950.f * i), (675.f));
		lista->push(aux);
	}
}

void Castelo::addTijolo()
{
	for (int i = 1; i <= 10; i++) {
		Tijolo* aux;
		aux = new Tijolo((800.f* i), (500.f));
		lista->push(aux);
	}
}

void Castelo::addPipe()
{
	for (int i = 1; i <= 10; i++) {
		Pipe* aux;
		aux = new Pipe((500.f *i), (700.f));
		lista->push(aux);
	}
}

void Castelo::addChao()
{
	for (int i = 0; i <= 30; i++) {
		Chao* aux;
		aux = new Chao((900.f * i), (800.f));
		lista->push(aux);
	}
}

void Castelo::addChefao()
{
	Diabo* chefao = new Diabo(9000.f, 300.f);
	chefao->setFase(this);
	setChefaoVivo(true);
	lista->push(chefao);

}



