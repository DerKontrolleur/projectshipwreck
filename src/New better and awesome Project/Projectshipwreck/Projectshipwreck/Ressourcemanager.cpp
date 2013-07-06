#include "RessourceManager.h"

RessourceManager * RessourceManager::Instance()
{
	static RessourceManager Instance;

	return &Instance;
}

void RessourceManager::LoadImage(string key, string filename)
{
	SDL_Surface * LoadedImage = NULL;
	SDL_Surface * OptimizedImage = NULL;

	LoadedImage = IMG_Load(filename.c_str());

	assert(LoadedImage != NULL && "<RessourceManager::LoadImage>: wrong file name");

	OptimizedImage = SDL_DisplayFormat(LoadedImage);

	assert(OptimizedImage != NULL && "<RessourceManager::LoadImage>: error optimizing image");

	this->Pictures.insert(make_pair(key, OptimizedImage));
}

void RessourceManager::ApplyPicture(int positionX, int positionY, SDL_Surface* source, SDL_Surface* destination)
{
	SDL_Rect Offset;

	Offset.x = positionX;
	Offset.y = positionY;

	assert(SDL_BlitSurface(source, NULL, destination, &Offset) != -1 && "<RessourceManager::ApplySurface>: error blitting surface");
}


void RessourceManager::LoadContent()
{
	cout << "Loading images..." << endl;

	LoadImage("background", "background.jpg");
}