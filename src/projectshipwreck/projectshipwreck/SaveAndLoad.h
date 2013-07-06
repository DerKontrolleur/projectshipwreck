#pragma once

#include "S_GameModes.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

namespace ProjectShipwreckLowClass
{
	class SaveAndLoad
	{
	public:
		SaveAndLoad(){}
		~SaveAndLoad(){}
		SaveAndLoad(const SaveAndLoad & SaveAndLoad){}
		SaveAndLoad & operator= (const SaveAndLoad &){}
		void save_AllGameFiles();
		void load_AllGameFiles();
	};
}