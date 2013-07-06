#pragma once


//////////////////////////////////////////////////////////////////////////////////////////
//Klasse ist ein Singleton und ist zuständig für alle Objekte, die durch TastenBerührung//
//beeinflusst werden können. Somit also insbesondere Player, Menue etc.					//
//////////////////////////////////////////////////////////////////////////////////////////
#include "S_Resourcemanager.h"

namespace ProjectShipwreckHighClass
{
	class S_EventHandler
	{
	private:
		S_EventHandler(){}
		~S_EventHandler(){}

	public:
		static S_EventHandler * get_Instance(){static S_EventHandler Instance; return &Instance;}
		bool is_GameToQuit(SDL_Event & tempEvent);
		void initialize(){}
	};
}