#pragma once

//////////////////////////////////////////////////////////////////////////////////////////
//Klasse ist ein Singleton und ist zuständig für alle Objekte, die durch Tastenberührung//
//beeinflusst werden können. Somit also insbesondere Player, Menue etc.					//
//////////////////////////////////////////////////////////////////////////////////////////
#include "S_InputManager.h"
#include "S_Resourcemanager.h"

namespace ProjectShipwreckHighClass
{
	class S_EventHandler
	{
	private:
		S_EventHandler() {}
		~S_EventHandler() {}

	public:
		static S_EventHandler* get_Instance(){static S_EventHandler Instance; return &Instance;}
		bool is_GameToQuit(SDL_Event& Event);
		void initialize(){}

		void HandleInputEvents(SDL_Event& Event);
	};
}


//------------------------------------------------------END OF FILE--------------------------------------------------------------------------------------
