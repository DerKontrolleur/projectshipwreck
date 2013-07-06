#include "GameApplicationLayer.h"

void ProjectShipwreckHighClass::GameApplicationLayer::main_Loop()
{
	while(b_GameShutDown != true)
	{
		if(SDL_PollEvent(&GameMainEvent))
		{
			if(ProjectShipwreckLowClass::S_EventHandler::get_Instance()->is_GameToQuit(GameMainEvent))
			{
				b_GameShutDown = true;
			}
		}
	}
}


void ProjectShipwreckHighClass::GameApplicationLayer::initialize_GameResources()
{
	try
	{
	S_ResourceManager::get_Instance()->LoadContent();
	}
	catch(exception GameInitialization)
	{
		cout << "GameInitialization failed badly!" << endl;
	}
}

void ProjectShipwreckHighClass::GameApplicationLayer::close_GameResources()
{

}