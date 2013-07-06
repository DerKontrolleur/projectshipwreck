#include "GameApplicationLayer.h"

void ProjectShipwreckHighClass::GameApplicationLayer::main_Loop()
{
	while(b_GameShutDown != true)
	{
		if(SDL_PollEvent(&GameMainEvent))
		{
			if(ProjectShipwreckHighClass::S_EventHandler::get_Instance()->is_GameToQuit(GameMainEvent))
			{
				cout << "Ich bin hier" << endl;
				b_GameShutDown = true;
			}
		}

		this->p_GameUpdateSource->update_AllFilesUpdateFunctions(this->GameMainEvent);
		this->p_GameUpdateSource->render_AllFilesRenderFunctions();
	}
}


void ProjectShipwreckHighClass::GameApplicationLayer::initialize_GameResources()
{
	S_ResourceManager::get_Instance()->SetScreen( 300,300,32 );
	S_ResourceManager::get_Instance()->SetCaption( "projectshipwreck" );
	S_ResourceManager::get_Instance()->SetTextColor( 255,255,255 );
	S_ResourceManager::get_Instance()->LoadContent();
	S_GameModes::get_Instance()->initialize();
	S_EventHandler::get_Instance()->initialize();
}

void ProjectShipwreckHighClass::GameApplicationLayer::close_GameResources()
{

}