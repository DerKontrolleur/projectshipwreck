#include "S_EventHandler.h"

bool ProjectShipwreckHighClass::S_EventHandler::is_GameToQuit(SDL_Event& Event)
{
	if(Event.type == SDL_QUIT)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ProjectShipwreckHighClass::S_EventHandler::HandleInputEvents(SDL_Event& Event) {
	ProjectShipwreckHighClass::S_InputManager::get_Instance()->InputEvents(Event);

	/* Handle events here */
}