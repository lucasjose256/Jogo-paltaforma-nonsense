#include "Cemiterio.h"
Cemiterio::Cemiterio(sf::RenderWindow* w, Jogador* jogador_1) : Fase(w, jogador_1)
{
	setCenario();
	setEntes();
	setSprite();
	//addJogador();
	//setCenario();
	w->draw(spriteFase);

}

Cemiterio::~Cemiterio()
{
	Lista<Entidade>::Elemento* aux = lista->getPrim();
	while (aux != nullptr) {
		if (aux->getItem()->getTipo() >= 1) {
			delete aux->getItem();
		}
		aux = aux->getProx();
	}
	delete lista;
}

void Cemiterio::setSprite()
{
	if (!textureFase.loadFromFile("texturas/cemiterio_novo.png")) {
		//std::cout << "[LOG_ERRO] ERRO LER Cemiterio_novo.PNG" << std::endl;
	}
	try
	{
		textureFase.loadFromFile("texturas/cemiterio_novo.png");
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what();
	}

	sf::Vector2u TextureSize;  //Added to store texture size.
	TextureSize = textureFase.getSize();


	float scaleX = (float)size_x / TextureSize.x;
	float scaleY = (float)size_y / TextureSize.y;
	spriteFase.setTexture(textureFase);
	spriteFase.setScale(scaleX, scaleY);
	spriteFase.setOrigin(sf::Vector2f(50.f, 335.f));
}

void Cemiterio::setEntes()
{
	addMedusa();
	addZumbi();
	addSpike();
	addTijolo();
	addPipe();
	addChao();
	addChefao();

}
void Cemiterio::addMedusa()
{
	srand((unsigned)time(0));
	int qtd = 3 + (rand() % 20);

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

void Cemiterio::addZumbi()
{
	srand((unsigned)time(0));
	int qtd = 3 + (rand() % 15);

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

void Cemiterio::addSpike()
{
	int distancia = 1;
	for (int i = 1; i <= 10; i++) {
		Spike* aux;
		aux = new Spike((300.f * (i * distancia)), (675.f));
		lista->push(aux);
		distancia++;
	}
}

void Cemiterio::addTijolo()
{
	for (int i = 1; i <= 10; i++) {
		Tijolo* aux;
		aux = new Tijolo((500.f * i), (400.f));
		lista->push(aux);
	}
}

void Cemiterio::addPipe()
{
	for (int i = 1; i <= 10; i++) {
		Pipe* aux;
		aux = new Pipe((900.f * i), (700.f));
		lista->push(aux);
	}
}

void Cemiterio::addChao()
{
	for (int i = 0; i <= 30; i++) {
		Chao* aux;
		aux = new Chao((900.f * i), (800.f));
		lista->push(aux);
	}
}
void Cemiterio::addChefao() {
	Slime* chefao = new Slime(6000.f, 350.f);
	lista->push(chefao);
	chefao->setFase(this);
	setChefaoVivo(true);
	lista->push(chefao);

}



