//////////////////////////////////////////////////////////////////////////////////////////
//// This class is a singleton. It is used to load and manage all data like pictures /////
//// soundfiles, ... */																/////
/////////////////////////////////////////////////////////////////////////////////////////
#pragma once


#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include <string>

#include <iostream>
using namespace std;

#include <unordered_map>


namespace ProjectShipwreckHighClass {

	class S_ResourceManager
	{
	private:
		SDL_Surface * screen;	// A pointer to the SDL_Surface that saves the screen
		Mix_Music* music;	// A pointer to the SDL_Surface that saves the game music

		// Sounds
		Mix_Chunk* scratch;
		Mix_Chunk* high;
		Mix_Chunk* med;
		Mix_Chunk* low;

		unordered_map<string, SDL_Surface*> Pictures;	// Used to get pictures with a keyword

		S_ResourceManager()
		{
			// Try to initialize SDL
			try {
				SDL_Init(SDL_INIT_EVERYTHING);
			}
			catch (exception sdlINIT) {
				cout << "<S_ResourceManager::Constructor>: error setting up SDL" << endl;
			}

			SDL_WM_SetCaption("projectshipwreck", NULL); // Name that is displayed in game window

			// Try to get the screen
			try {
				this->screen = SDL_SetVideoMode(0, 0, 32, SDL_SWSURFACE | SDL_RESIZABLE);
			}
			catch (exception getScreen) {
				cout << "S_ResourceManager::Constructor: error getting screen" << endl;
			}

			cout << "S_ResourceManager constructed" << endl;
		}

	public:
		~S_ResourceManager()
		{
			this->Pictures.clear();

			cout << "S_ResourceManager destroyed" << endl;
		}


		// Static pointer to access this singleton
		static S_ResourceManager* get_Instance() {
			static S_ResourceManager Instance;
			return &Instance;
		}


		void LoadImage(string key, string filename);
		void LoadSound();
		void ApplyPicture(int positionX, int positionY, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL);
		void LoadContent(); // Call once at the beginning to load everything
		void UpadteScreen() { SDL_Flip(this->screen); } // Call after any picture is changed

		SDL_Surface* GetScreen() const { return this->screen; }
		void SetScreen(SDL_Surface* screen) { this->screen = screen; }

		SDL_Surface* GetPicture(string key) { return this->Pictures.at(key); }
	};
}