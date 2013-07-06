#pragma once


//////////////////////////////////////////////////////////////////////////////////////////
//Klasse ist ein Singleton und ist zust�ndig f�r alle Objekte, die durch TastenBer�hrung//
//beeinflusst werden k�nnen. Somit also insbesondere Player, Menue etc.					//
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