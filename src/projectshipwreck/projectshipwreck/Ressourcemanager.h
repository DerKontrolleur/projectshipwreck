#pragma once

#include <SDL.h>
#include "SDL_image.h"

#include <assert.h>
#include <string>

#include <iostream>
using namespace std;


#include <unordered_map>

class RessourceManager
{
private:
	SDL_Surface * Screen;

	unordered_map<string, SDL_Surface*> Pictures;

	RessourceManager()
	{
		assert(SDL_Init(SDL_INIT_EVERYTHING) != -1 && "<RessourceManager::Constructor>: error setting up SDL");

		SDL_WM_SetCaption("projectshipwreck", NULL);

		this->Screen = SDL_SetVideoMode(0, 0, 32, SDL_SWSURFACE | SDL_RESIZABLE);

		cout << "RessourceManager constructed" << endl;
	}

public:

	~RessourceManager()
	{
		this->Pictures.clear();

		cout << "RessourceManager destroyed" << endl;
	}


	static RessourceManager* Instance();


	void LoadImage(string key, string filename);
	void ApplyPicture(int positionX, int positionY, SDL_Surface* source, SDL_Surface* destination);
	void LoadContent();

	SDL_Surface* GetScreen() const { return this->Screen; }
	void SetScreen(SDL_Surface* Screen) { this->Screen = Screen; }

	SDL_Surface* GetPicture(string key) { this->Pictures.at(key); }
};