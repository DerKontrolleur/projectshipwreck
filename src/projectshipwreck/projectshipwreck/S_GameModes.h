#pragma once

//////////////////////////////////////////////////////////////////////////////////////////////
//Diese Klasse ist zuständig für das speichern der aktuellen Spielszene.					//
//Die Datei enthält zusätzlich noch zwei Enumerationen, die den Spielmodus speichern können.//
//////////////////////////////////////////////////////////////////////////////////////////////

namespace ProjectShipwreckEnumerations
{
	enum GAMEMAINMODES {MENUE,DEATH,BOAT,LAND,CLOUDS};
	enum WEATHERTYPE {RAIN,SUN};
};


namespace ProjectShipwreckHighClass
{
	class S_GameModes
	{
	private:
		ProjectShipwreckEnumerations::GAMEMAINMODES CURRENTMODE;
		ProjectShipwreckEnumerations::WEATHERTYPE CURRENTWEATHER;
		S_GameModes():CURRENTMODE(ProjectShipwreckEnumerations::MENUE),CURRENTWEATHER(ProjectShipwreckEnumerations::SUN){}
		S_GameModes(ProjectShipwreckEnumerations::GAMEMAINMODES initGAMEMODE,ProjectShipwreckEnumerations::WEATHERTYPE initWEATHERTYPE):CURRENTMODE(initGAMEMODE),CURRENTWEATHER(initWEATHERTYPE){}
		~S_GameModes(){}
	public:
		static S_GameModes * get_Instance(){static S_GameModes Instance;return &Instance;}
		const ProjectShipwreckEnumerations::GAMEMAINMODES get_GameMainMode(){return CURRENTMODE;}
		void set_GameMainMode(ProjectShipwreckEnumerations::GAMEMAINMODES tempGAMEMODE){CURRENTMODE = tempGAMEMODE;}
		const ProjectShipwreckEnumerations::WEATHERTYPE get_GameWeatherType(){return CURRENTWEATHER;}
		void set_GameMainMode(ProjectShipwreckEnumerations::WEATHERTYPE tempWEATHER){CURRENTWEATHER = tempWEATHER;}
		void initialize(){}
	};
}


//------------------------------------------------------END OF FILE--------------------------------------------------------------------------------------
