#include "S_EventHandler.h"

bool ProjectShipwreckHighClass::S_EventHandler::is_GameToQuit(SDL_Event & tempEvent)
{
	if(tempEvent.type == SDL_QUIT)
	{
		return true;
	}
	else
	{
		return false;
	}
}