#pragma once
#include "SDL.h"
#include "SDL_image.h"

class GameObject
{
private:
	SDL_Renderer* renderer = nullptr;

public:
	GameObject();
	~GameObject();

	void GameObject::render();
	void GameObject::update();
	void GameObject::loadFromFile(const char* fileName);
	void GameObject::saveToFile();
	
};

