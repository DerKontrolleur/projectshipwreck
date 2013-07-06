#pragma once

#include "S_Resourcemanager.h"

namespace ProjectShipwreckLowClass
{
	class S_EventHandler
	{
	private:
		S_EventHandler(){}
		~S_EventHandler(){}

	public:
		static S_EventHandler * get_Instance(){static S_EventHandler Instance; return &Instance;}
		bool is_GameToQuit(SDL_Event & tempEvent);
	};
}