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

	class S_ResourceManager {
	public:
		// Key enums
		enum e_Image {
			key_background
		};

		enum e_Audio {
			key_temp
		};

	private:
		// Pictures
		SDL_Surface * screen;	// A pointer to the SDL_Surface that saves the screen
		unordered_map<e_Image, SDL_Surface*> Pictures;	// Used to get pictures with a keyword
		unordered_map<e_Image, SDL_Surface*>::iterator pictures_it;

		// Sounds
		unordered_map<e_Audio, Mix_Music*> Music;
		unordered_map<e_Audio, Mix_Chunk*> Sounds;
		unordered_map<e_Audio, Mix_Music*>::iterator music_it;
		unordered_map<e_Audio, Mix_Chunk*>::iterator sounds_it;

		// Fonts
		TTF_Font* font;

		


		S_ResourceManager()
		{
			// Try to initialize everything
			try {
				if(SDL_Init(SDL_INIT_EVERYTHING) == -1) {
					throw "<S_ResourceManager::Constructor>: SDL could not be initialized";
				}

			//Initialize SDL_ttf
				if(TTF_Init() == -1) {
					throw "<S_ResourceManager::Constructor>: SDL_ttf could not be initialized";
				}

				// Set color of SDL_Font
				SDL_Color textColor = { 255, 255, 255 };

			//Initialize SDL_mixer
				if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1) {
					throw "<S_ResourceManager::Constructor>: SDL_mixer could not be initialized";
				}
	 
				SDL_WM_SetCaption("projectshipwreck", NULL); // Name that is displayed in game window

				// Try to get the screen
				this->screen = SDL_SetVideoMode(0, 0, 32, SDL_SWSURFACE | SDL_RESIZABLE);
				if(this->screen == NULL) {
					throw "<S_ResourceManager::Constructor>: SDL_SetVideoMode returned NULL";
				}
			}
			catch (char* strException) {
				cerr << "Error: " << strException << endl;
				exit(1);
			}
		}

	public:
		~S_ResourceManager()
		{
			this->Clean();
		}


		// Static pointer to access this singleton
		static S_ResourceManager* get_Instance() {
			static S_ResourceManager Instance;
			return &Instance;
		}


		void LoadImage(e_Image key, string filename);
		void LoadSound(e_Audio key, string filename);
		void LoadMusic(e_Audio key, string filename);
		void LoadFont(string filename, int size);
		void ApplyPicture(int positionX, int positionY, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL);
		void LoadContent();		// Call once at the beginning to load everything
		void Clean();	// Call once when closing the game
		void UpadteScreen() { SDL_Flip(this->screen); }		// Call after any picture is changed

		SDL_Surface* GetScreen() const { return this->screen; }
		void SetScreen(SDL_Surface* temp_screen) { this->screen = temp_screen; }

		SDL_Surface* GetPicture(e_Image key) { return this->Pictures.at(key); }
		Mix_Chunk* GetSound(e_Audio key) { return this->Sounds.at(key); }
		Mix_Music* GetMusic(e_Audio key) { return this->Music.at(key); }
		TTF_Font* GetFont() { return this->font; }
	};
}