#pragma once

class GameObject
{
private:
	SDL_Renderer* renderer = nullptr;

public:
	GameObject();
	~GameObject();

	void GameObject::render();
	void GameObject::update();
	void GameObject::loadFromFile();
	void GameObject::saveToFile();
	
};

