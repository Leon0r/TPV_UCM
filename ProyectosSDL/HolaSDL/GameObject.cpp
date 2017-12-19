#include "GameObject.h"

GameObject::GameObject()
{
}

GameObject::GameObject(Game* game) : game(game)
{
};

GameObject::~GameObject()
{
}

// Asigna el tamaño de celda y el puntero a textura
void GameObject::loadGameObject(int cellSize, Textures* texture) {
	// Inicializa el tamaño de las celdas
	GameObject::cellSize = cellSize;
	rectDest.h = cellSize;
	rectDest.w = cellSize;
	// Asigna el puntero a la textura del GO
	GameObject::texture = texture;
}