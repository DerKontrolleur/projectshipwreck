#pragma once

//////////////////////////////////////////////////////////////////////////////
//Diese Klasse ist nicht erzeugbar, sondern dient nur als Interface für alle//
//Klassen, die eine Animation benötigen										//
//////////////////////////////////////////////////////////////////////////////

#include "Timer.h"

namespace ProjectShipwreckLowClass
{
	class A_Animation
	{
	private:
		int animationframe;//Das ist der Frame, der an die ApplyPicture Funktion mit einem Array übergeben wird, um das richtige Animationsbild auszuschneiden
		ProjectShipwreckHighClass::Timer * p_AnimationTimer;// Der AnimationTimer, der für das Timing der Animation zuständig ist
	public:
		A_Animation(){p_AnimationTimer = new ProjectShipwreckHighClass::Timer();}
		virtual ~A_Animation(){delete p_AnimationTimer;}
		virtual void render() = 0;// vollkommen abstrakte Funktion, die die Klasse, an die diese Klasse vererbt wurde zwingt die FUnktion zu implementieren

	};





}



//------------------------------------------------------END OF FILE--------------------------------------------------------------------------------------