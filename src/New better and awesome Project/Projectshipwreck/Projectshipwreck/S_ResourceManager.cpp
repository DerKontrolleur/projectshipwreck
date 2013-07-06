#include "S_ResourceManager.h"
using namespace ProjectShipwreckHighClass;

void S_ResourceManager::LoadImage(string key, string filename)
{
	SDL_Surface* loadedImage = NULL;
	SDL_Surface* optimizedImage = NULL;

	try {
		loadedImage = IMG_Load(filename.c_str());
	}
	catch (exception loadIMG) {
		cout << "<RessourceManager::LoadImage>: wrong filename" << endl;
	}

	try {
		optimizedImage = SDL_DisplayFormat(loadedImage);
	}
	catch (exception optimizeIMG) {
		cout << "<RessourceManager::LoadImage>: error optimizing image" << endl;
	}

	this->Pictures.insert(make_pair(key, optimizedImage));
}


void S_ResourceManager::LoadMusic(string key, string filename) {
	Mix_Music* loadedMusic = NULL;

	try {
		loadedMusic = Mix_LoadMUS(filename.c_str());
	}
	catch (exception loadMusic) {
		cout << "<RessourceManager::LoadMusic>: error loading music" << endl;
	}

	this->Music.insert(make_pair(key, loadedMusic));
}


void S_ResourceManager::LoadSound(string key, string filename) {
	Mix_Chunk* loadedSound = NULL;

	try {
		loadedSound = Mix_LoadWAV(filename.c_str());
	}
	catch (exception loadSound) {
		cout << "<RessourceManager::LoadSound>: error loading sound" << endl;
	}

	this->Sounds.insert(make_pair(key, loadedSound));
}


void S_ResourceManager::LoadFont(string filename, int size) {
	this->font = TTF_OpenFont(filename.c_str(), size);
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

	//LoadImage();

	cout << "Loading music..." << endl;

	//LoadMusic();

	cout << "Loading sound files..." << endl;

	//LoadSound();

	cout << "Loading fonts..." << endl;

	//LoadFont();
}