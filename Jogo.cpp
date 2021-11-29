#include"Jogo.h"
#pragma warning(disable : 4996)
Jogo::Jogo() 
{
	createMenu();	
}

Jogo::~Jogo()
{
	delete this->gameWindow;
	delete(jogador);
	delete (G_D_C);
	lista = nullptr;
	castelo = nullptr;
	cemiterio = nullptr;
	menu = nullptr;
	proj.clear();
	textures.clear();
	
}

void Jogo::render()
{
	//gameWindow->clear(sf::Color::Cyan);//Renderizar a cor dentro de cada fase e nao no jogo
	//gameWindow->clear();
	gameWindow->setView(*view);
	renderPrj();
	if (castelo != nullptr) {
		renderFase(castelo);
		renderInimigos(castelo);
		if (!castelo->getChefaoVivo()) {
			gameWindow->close();
		}
	}
	else if (cemiterio != nullptr){
		renderFase(cemiterio);
		renderInimigos(cemiterio);
		if (!cemiterio->getChefaoVivo()) {
			gameWindow->close();
		}
	}

	else {
		renderFase(castelo);
		renderInimigos(castelo);
		if (!castelo->getChefaoVivo()) {
			gameWindow->clear();
			delete castelo;
			renderFase(cemiterio);
			renderInimigos(cemiterio);
		}
		if (!cemiterio->getChefaoVivo()) {
			gameWindow->clear();
			delete cemiterio;
		}
		

	}
	renderPlayer();	
	gameWindow->display();
	gameWindow->clear();
	
}

void Jogo::update()
{
	while (gameWindow->pollEvent(evento)) {
		if (evento.type == sf::Event::Closed) {
			gameWindow->close();
		}
	}
	
	G_D_C->setPosParaColisao();//mudar para update
	G_D_C->updateColisaoProjetil();
	updatePlayer();
	//updateColisao();
	updateProjetil();
	updateColisao();
	
	if (jogador->getverificaSeestaVivo()) {
		gameWindow->close();
	}
}

void Jogo::setPlayer()
{
	jogador = new Jogador();

}

void Jogo::renderPlayer()
{
	jogador->render(gameWindow);
	view->setCenter(jogador->getPosicao());
	
	
	
}

void Jogo::updatePlayer()
{
	
	jogador->update();
}

void Jogo::setWindow()
{
	gameWindow = new sf::RenderWindow(sf::VideoMode(1000,800), "JOGO");
	gameWindow->setFramerateLimit(100);

}

void Jogo::setJogo()
{
	
}

void Jogo::renderPrj()
{
	G_D_C->renderizaProjetil();

}

void Jogo::updateProjetil()
{	//o personagem vai matar os enimigos com o fogo 
	/*unsigned counter = 0;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

		std::cout << "BULLET INSERTED" << std::endl;
		this->proj.push_back(new Projetil(this->textures
		["BULLET"],this->jogador->getPosForBullet().x, this->jogador->getPosForBullet().y, 1.f, 0.f,6.f));
	}
	for (auto* projetil : this->proj) {

		projetil->update();
											
		/* if (proj. + jogador->getGlobalBounds().width > gameWindow->getSize().x)
		{
			//delete projetil;
			this->proj.erase(this->proj.begin()+ counter);
			--counter;

			std::cout << "NUMERO DE PROJETIL DE FOGO NA TELA" << this->proj.size() << std::endl;
		}

		++counter;
		
		
	}
*/
		
//G_D_C->updateColisaoProjetil();

																								
}

void Jogo::iniTextures()//INICIA O PROJETIL 
{
	/*textures["BULLET"] = new sf::Texture;
	if (!textures["BULLET"]->loadFromFile("texturas/fogo.png")) {
		std::cout << "NÃO FOI POSSIVEL ABRIR A IMAGEM BULLET \n";
	}*/

}

void Jogo::setColisoes()
{
	if (castelo != nullptr) {
		G_D_C = new Gerenciador_de_colisoes(jogador, castelo->getListaEntes(), proj, gameWindow);
	}
	else if (cemiterio != nullptr) {
		G_D_C = new Gerenciador_de_colisoes(jogador, cemiterio->getListaEntes(), proj, gameWindow);
	}
	
}

void Jogo::updateColisao()
{	
	
	
	
	//COLISAO ESQUERDA
	if(jogador->getPosicao().x<0.f)
	{
		jogador->setPosicao(0.f,jogador->getPosicao().y);
	}
	//COLISAO CIMA
	if (jogador->getPosicao().y	< 0.f)
	{
		jogador->setPosicao(jogador->getPosicao().x, 0.f);
	}
	 
	//COLISAO CHAO
	if (jogador->getGlobalBounds().top + jogador->getGlobalBounds().height > gameWindow->getSize().y) {
		jogador->resetVelocidadeY();
		jogador->setPosicao(jogador->getGlobalBounds().left,
			gameWindow->getSize().y - jogador->getGlobalBounds().height);
	}
	


	
	
}

void Jogo::setFase(const int fase)
{
	if (fase == 1) {
		castelo = new Castelo(gameWindow, jogador);
		castelo->setSizes(gameWindow->getSize().x, gameWindow->getSize().y);
		cemiterio = nullptr;
	}
	else if(fase == 2){
		cemiterio = new Cemiterio(gameWindow, jogador);
		cemiterio->setSizes(gameWindow->getSize().x, gameWindow->getSize().y);
		castelo = nullptr;
	}
	else {
		cemiterio = new Cemiterio(gameWindow, jogador);
		cemiterio->setSizes(gameWindow->getSize().x, gameWindow->getSize().y);

		castelo = new Castelo(gameWindow, jogador);
		castelo->setSizes(gameWindow->getSize().x, gameWindow->getSize().y);

	}
	
}

void Jogo::renderInimigos(Fase*fase)
{

	lista = fase->getList();
	Lista<Entidade>::Elemento* aux = lista->getPrim();
	for (int i = 0; i < lista->getTam(); i++) {
		Entidade* entidade = aux->getItem();
		entidade->render(gameWindow);
		entidade->mover();
		
		aux = aux->getProx();
		
	}
	
	
	
}
void Jogo::createMenu()
{
	sf::RenderWindow menuWindow(sf::VideoMode(800, 800), "Menu");
	menu = new Menu(800.f, 800.f);

	while (menuWindow.isOpen()) {
		sf::Event event;
		while (menuWindow.pollEvent(event)) {
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu->moveUp();
					break;
				case sf::Keyboard::Down:
					menu->moveDown();
					break;
				case sf::Keyboard::Return:
					opcMenu(menu->getIndex(), &menuWindow);
					break;
				}
				break;
			case sf::Event::Closed:
				menuWindow.close();
				break;
			default:
				break;
			}
		}
		menu->render(&menuWindow);
		menuWindow.display();
	}
}

void Jogo::opcMenu(const int indexMenu, sf::RenderWindow* menuWindow)
{
	switch (indexMenu)
	{
	case 0:
		menuWindow->close();
		executar();
		break;
	case 1:
		menuWindow->close();
		menu->iniciaJogo2();
		//execGame2();
		break;
	case 2:
		menuWindow->close();
		menu->iniciaCastelo();
		execCastelo();
		break;
	case 3:
		menuWindow->close();
		menu->iniciaCemiterio();
		execCemiterio();
		break;
	case 4:
		menuWindow->close();
		menu->mostraScore();
		mostraScore();
		break;
	case 5:
		//std::cout << "SAIR" << std::endl;
		menuWindow->close();
		break;
	default:
		break;
	}
}

void Jogo::executar()
{
	setWindow();
	setView();
	setPlayer();
	setFase();
	iniTextures();//lucas
	setColisoes();
}

void Jogo::setView()
{
	view = new sf::View(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(512.0f, 750.0f));
}

void Jogo::renderFase(Fase * fase) {
	fase->render(gameWindow);
	
}

void Jogo::execCastelo()
{
	setWindow();
	setView();
	setPlayer();
	setFase(1);
	iniTextures();//lucas
	setColisoes();
}

void Jogo::execCemiterio()
{
	setWindow();
	setView();
	setPlayer();
	setFase(2);
	iniTextures();//lucas
	setColisoes();
}

void Jogo::salvar()
{
	time_t now = time(0);
	char* dt = ctime(&now);

	std::ofstream arquivo("pontuacao.txt");
	arquivo << dt << " pontos: " << jogador->getPontos() << "\n";
	arquivo.close();

}

void Jogo::mostraScore()
{
	std::string pontuacao;

	std::ifstream arquivo("pontuacao.txt");

	while (getline(arquivo, pontuacao)) {
		std::cout << pontuacao << std::endl;
	}

	arquivo.close();
}
