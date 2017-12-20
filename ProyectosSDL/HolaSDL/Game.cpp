#include "Game.h"

Game::Game() {

}

Game::~Game()
{
	for (int i = 0; i < NUM_TEXTURES; i++)
		delete textures[i];

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

// Inicializa todos los atributos
void Game::loadGame() {
	// Para ver si window se inicializa bien
	if (window == nullptr || renderer == nullptr)
		cout << "ERROR 404: window or renderer not found.";
	else {
		// Inicializaci�n de texturas
		// En el loadMenu()
		// Inicializa el mapa con level01
		ifstream level("..\\levels\\level01.pac");
		map = new GameMap(this);
		map->loadMap(level, 20, textures[3]);
		// Lee el n� de fantasmas
		int numGhost, typeGhost;
		level >> numGhost;
		
		// Bucle para crear fantasmas
		for (int i = 0; i < numGhost; i++)
		{
			// Lee el tipo de fantasma que es
			level >> typeGhost; // Si es 0, normal, si 1, evolucionado
			if (typeGhost == 1) {
				characters.push_back(new SmartGhost(this));// Crea un nuevo fantasma
			  // como se ha hecho push back, el �ltimo obj de la lista es el fantasma creado
				characters.back()->loadCharacter(level, 8, 20, textures[4], this);
			}
			else {
				characters.push_back(new Ghost(this));// Crea un nuevo fantasma
				  // como se ha hecho push back, el �ltimo obj de la lista es el fantasma creado
				characters.back()->loadCharacter(level, 0, 20, textures[4], this); 
			}
		}
		// Carga pacman
		pacman = new Pacman(this);
		characters.push_front(pacman);// Crea un nuevo fantasma
		// como se ha hecho push back, el �ltimo obj de la lista es el fantasma creado
		characters.front()->loadCharacter(level, 10, 20, textures[4], this);
		
		// asigna a los smart el target
		for (it = characters.begin(); it != characters.end(); ++it)
			if(typeid (*(*it)) == typeid (SmartGhost))
				(*it)->setTarget(pacman->getPosAct());

		// Primero pintar fondo (mapa) y luego lo demas
		map->render();
		for (auto c : characters)
			c->render();

		level.close();
		SDL_RenderPresent(renderer);
	}
}

void Game::loadMenu() {
	winX = winY = SDL_WINDOWPOS_CENTERED;

	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow("PACMAN", winX, winY, winWidth, winHeigth, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	// Para ver si window se inicializa bien
	if (window == nullptr || renderer == nullptr)
		cout << "ERROR 404: window or renderer not found.";
	else {
		// Inicializaci�n de texturas
		for (int i = 0; i < NUM_TEXTURES; i++) {
			textures[i] = new Textures;
			textures[i]->loadTextureFromImage(renderer, infoT[i].filename, infoT[i].numFils, infoT[i].numCols);
		}

		SDL_Rect rectDest;

		rectDest.x = 0;
		rectDest.y = 0;
		rectDest.h = winHeigth;
		rectDest.w = winWidth;
		textures[0]->renderFullText(rectDest);

		rectDest.y = (winHeigth / 2) + 150;
		rectDest.x = winWidth / 5 + 30;
		rectDest.h = 100;
		rectDest.w = 300;
		textures[1]->renderFullText(rectDest);

		rectDest.y = winHeigth / 2;
		rectDest.x = winWidth / 5 + 30;
		rectDest.h = 100;
		rectDest.w = 300;
		textures[2]->renderFullText(rectDest);

		SDL_RenderPresent(renderer);
	}
}

// Bucle principal del juego
void Game::run() {
	loadMenu();
	while(menu)
		handleEvents();
	
	loadGame();
	while (!exit) {
		startTime = SDL_GetTicks();
		handleEvents();
		update();
		render();
		frameTime = SDL_GetTicks() - startTime;
		if (frameTime<FRAME_RATE) SDL_Delay(FRAME_RATE - frameTime);
	}
}

// Dibuja el estado actual del juego
void Game::render() {
	map->render();
	for (auto c : characters)
		c->render();
	SDL_RenderPresent(renderer);
}

// Actualiza el estado de los elementos
void Game::update() {
	for (auto c : characters)
		c->update();
}

// Se encarga de los eventos de teclado
void Game::handleEvents() {
	if (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT)
			exit = true;
		// Eventos de felchas de direcci�n
		else if (event.type == SDL_KEYDOWN) {
			if (event.key.keysym.sym == SDLK_UP)
				pacman->nextDir(0, -1);
			else if (event.key.keysym.sym == SDLK_DOWN)
				pacman->nextDir(0, 1);
			else if (event.key.keysym.sym == SDLK_LEFT)
				pacman->nextDir(-1, 0);
			else if (event.key.keysym.sym == SDLK_RIGHT)
				pacman->nextDir(1, 0);
		}
		else if (event.type == SDL_MOUSEBUTTONDOWN)
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				
				int x, y;
				SDL_GetMouseState(&x, &y);
				if (((x > winWidth / 5 + 30) && x < (winWidth / 5 + 330)) && (y > winHeigth / 2 && y < winHeigth / 2 + 100))
				{
					//loadfromfile(getFileName());
					menu = false;
					cout << "Has pulsado";
					}
				else if ((x > (winWidth / 5 + 30) && x < (winWidth / 5 + 330)) && (y >((winHeigth / 2) + 150) && y < ((winHeigth / 2) + 250))) {
					//save = true;
					menu = false;
					cout << "Has pulsado";
				}
			}
	}
}

// Devuelve true si la sig casilla en direccion dir es vacia
bool Game::nextCell(int posX, int posY, const int dirX, const int dirY) {
	int auxX = posX;
	int auxY = posY;
	nextPosToroide(auxX, auxY, dirX, dirY);
	return (map->getCellType(auxY, auxX) != 1); // El 1 es muro
}

// Calcula la sig pos (con toroide)
void Game::nextPosToroide(int& posX, int& posY, const int dirX, const int dirY) {
	if (dirX == -1)
		Left(posX);
	else if (dirX == 1)
		Right(posX);
	else if (dirY == -1)
		Up(posY);
	else if (dirY == 1)
		Down(posY);

}

// Consulta si la casilla es comestible: comida o energia, en el segundo caso devuelve true
bool Game::cellEatable(const int x, const int y) {
	bool vit = map->getCellType(y, x) == 3; // Vitamina hace que devuelva true la funci�n
	if (map->getCellType(y, x) == 3 || map->getCellType(y, x) == 2) { // 3: vitamina, 2: comida
		foodLeft--; // Resta a la comida total
		map->fillCell(y, x, 0); // Cambia la casilla a vac�o
	}
	return vit;
}

// Mira si en hay fantasmas en la pos (x,y)
bool Game::isAGhost(int x, int y, list <GameCharacter*>::iterator &it) {
	bool ghost = false;
	int posX, posY;
	it = characters.begin();
	it++; // Esto omite PacMan

	while (it != characters.end() && !ghost)
	{
		(*it)->getPosAct(posX, posY);
		ghost = (posX == x && posY == y);
		it++;
	}
	return ghost;
}

// Metodos auxiliares para calcular la sig pos teniendo en cuenta el toroide
void Game::Up(int& posY) {
	if (posY - 1 < 0)
		posY = map->getNumRow() - 1;
	else
		posY = posY - 1;
}

void Game::Down(int& posY) {
	if (posY + 1 >= map->getNumRow())
		posY = 0;
	else
		posY = posY + 1;
}

void Game::Left(int& posX) {
	if (posX - 1 < 0)
		posX = map->getNumCols() - 1;
	else
		posX = posX - 1;
}

void Game::Right(int& posX) {
	if (posX + 1 >= map->getNumCols())
		posX = 0;
	else
		posX = posX + 1;
}