//////////////////////////////////////////////////////////////////////////////////////////
//// This class is a singleton. It is used to load and manage all data like pictures /////
//// soundfiles, ... */																/////
/////////////////////////////////////////////////////////////////////////////////////////
#pragma once


#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#include <string>

#include <iostream>
using namespace std;

#include <unordered_map>


namespace ProjectShipwreckHighClass {

	class S_ResourceManager
	{
	private:
		// Pictures
		SDL_Surface * screen;	// A pointer to the SDL_Surface that saves the screen
		unordered_map<string, SDL_Surface*> Pictures;	// Used to get pictures with a keyword

		// Sounds
		unordered_map<string, Mix_Music*> Music;
		unordered_map<string, Mix_Chunk*> Sounds;

		// Fonts
		TTF_Font* font;

		S_ResourceManager()
		{
			// Try to initialize SDL
			try {
				SDL_Init(SDL_INIT_EVERYTHING);
			}
			catch (exception sdlINIT) {
				cout << "<S_ResourceManager::Constructor>: error setting up SDL" << endl;
			}

			//Initialize SDL_ttf
			try {
				TTF_Init();
			}
			catch (exception sdlTTF) {
				cout << "<S_ResourceManager::Constructor>: error setting up TTF" << endl;
			}

			// Set color of SDL_Font
			SDL_Color textColor = { 255, 255, 255 };

			//Initialize SDL_mixer
			try {
				Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
			}
			catch (exception sdlMixer) {
				cout << "<S_ResourceManager::Constructor>: error setting up sound" << endl;
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
			this->Music.clear();
			this->Sounds.clear();

			cout << "S_ResourceManager destroyed" << endl;
		}


		// Static pointer to access this singleton
		static S_ResourceManager* get_Instance() {
			static S_ResourceManager Instance;
			return &Instance;
		}


		void LoadImage(string key, string filename);
		void LoadSound(string key, string filename);
		void LoadMusic(string key, string filename);
		void LoadFont(string filename, int size);
		void ApplyPicture(int positionX, int positionY, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL);
		void LoadContent();		// Call once at the beginning to load everything
		void Clean();	// Call once when closing the game
		void UpadteScreen() { SDL_Flip(this->screen); }		// Call after any picture is changed

		SDL_Surface* GetScreen() const { return this->screen; }
		void SetScreen(SDL_Surface* screen) { this->screen = screen; }

		SDL_Surface* GetPicture(string key) { return this->Pictures.at(key); }
	};
}