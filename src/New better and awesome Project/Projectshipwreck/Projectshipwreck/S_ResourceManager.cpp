#include "S_ResourceManager.h"
using namespace ProjectShipwreckHighClass;

void S_ResourceManager::LoadImage(string key, string filename)
{
	SDL_Surface* LoadedImage = NULL;
	SDL_Surface* OptimizedImage = NULL;

	try {
		LoadedImage = IMG_Load(filename.c_str());
	}
	catch (exception loadIMG) {
		cout << "<RessourceManager::LoadImage>: wrong filename" << endl;
	}

	try {
		OptimizedImage = SDL_DisplayFormat(LoadedImage);
	}
	catch (exception optimizeIMG) {
		cout << "<RessourceManager::LoadImage>: error optimizing image" << endl;
	}

	this->Pictures.insert(make_pair(key, OptimizedImage));
}

void S_ResourceManager::ApplyPicture(int positionX, int positionY, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip)
{
	SDL_Rect Offset; // Used to store the x in y position in a SDL_Rect because SDL_BlitSurface only takes SDL_Rect

	Offset.x = positionX;
	Offset.y = positionY;

	try {
		SDL_BlitSurface(source, clip, destination, &Offset); // Show the loaded picture on the screen
	}
	catch (exception blitting) {
		cout << "<RessourceManager::ApplySurface>: error blitting surface" << endl;
	}
}


void S_ResourceManager::LoadContent()
{
	cout << "Loading images..." << endl;

	LoadImage("background", "background.jpg");
}