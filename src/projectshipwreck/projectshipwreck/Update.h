#pragma once

///////////////////////////////////////////////////////////////////////////////////
//Die Klasse Update ist ein Teil des ApplicationLayers und enthält alle          //
//übergeordneten UpdateFUnktion. Sie selbst enthält aber immer die höchste Update//
//Funktion.Neben ihr gibt es keine!												 //
///////////////////////////////////////////////////////////////////////////////////

#include "S_ResourceManager.h"
#include "S_EventHandler.h"

namespace ProjectShipwreckLowClass
{
	class Update
	{
	private:

	public:
		Update(){}
		~Update(){}
		Update(const Update & that){}
		Update& operator=(const Update & that){}
		void render_AllFilesRenderFunctions();//Hierein kommen sämtliche render Funktionen aller Klassen
		void update_AllFilesUpdateFunctions(SDL_Event & tempEvent);//HIerein kommen alle update Funktionen sämtlicher Klassen
	};

}

//------------------------------------------------------END OF FILE--------------------------------------------------------------------------------------