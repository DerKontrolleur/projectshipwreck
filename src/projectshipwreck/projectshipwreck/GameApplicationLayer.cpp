#include "GameApplicationLayer.h"

void ProjectShipwreckHighClass::GameApplicationLayer::main_Loop()
{
	while(b_GameShutDown != true)
	{
		if(SDL_PollEvent(&GameMainEvent))
		{
			if(ProjectShipwreckLowClass::S_EventHandler::get_Instance()->is_GameToQuit(GameMainEvent));
			{
				b_GameShutDown = true;
			}
		}
	}
}


void ProjectShipwreckHighClass::GameApplicationLayer::initialize_GameResources()
{
	RessourceManager::Instance()->LoadContent();
}

void ProjectShipwreckHighClass::GameApplicationLayer::close_GameResources()
{

}