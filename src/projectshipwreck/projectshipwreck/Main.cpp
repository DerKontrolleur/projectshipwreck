#include "S_Resourcemanager.h"
#include "GameApplicationLayer.h"

int main(int argc, char* args [])
{
	
	ProjectShipwreckHighClass::GameApplicationLayer * p_GameMainSource = new ProjectShipwreckHighClass::GameApplicationLayer();

	p_GameMainSource->initialize_GameResources();

	p_GameMainSource->main_Loop();

	p_GameMainSource->close_GameResources();



	return 0;
}