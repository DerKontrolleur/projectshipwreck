#include "SaveAndLoad.h"

void ProjectShipwreckLowClass::SaveAndLoad::save_AllGameFiles()
{
	try
	{
		ofstream DATASTREAMTOSAVE;
		DATASTREAMTOSAVE.open("SAVE.sav",ios::out);
		if(DATASTREAMTOSAVE.is_open() != true)
		{
			throw "<SaveAndLoad::save_AllGameFiles>: Datenstream konnte nicht erstellt werden";
		}

		DATASTREAMTOSAVE << "<GameMode>: \n";
		DATASTREAMTOSAVE << ProjectShipwreckHighClass::S_GameModes::get_Instance()->get_GameMainMode() << "\n";

		DATASTREAMTOSAVE.close();

		cout << "Succesfully saved game" << endl;
	}
	catch(char * SaveError)
	{
		cerr << "Error: " << SaveError << endl;
	}

}