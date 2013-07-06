#include "GameApplicationLayer.h"

void ProjectShipwreckHighClass::GameApplicationLayer::main_Loop()
{
	while(b_GameShutDown != true)
	{
		if(SDL_PollEvent(&GameMainEvent))
		{
			if(ProjectShipwreckHighClass::S_EventHandler::get_Instance()->is_GameToQuit(GameMainEvent))
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
	S_GameModes::get_Instance()->initialize();
	S_EventHandler::get_Instance()->initialize();
	}
	catch(exception GameInitialization)
	{
		cout << "GameInitialization failed badly!" << endl;
	}
}

void ProjectShipwreckHighClass::GameApplicationLayer::close_GameResources()
{

}