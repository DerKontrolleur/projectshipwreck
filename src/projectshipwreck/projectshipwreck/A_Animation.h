#pragma once

//////////////////////////////////////////////////////////////////////////////
//Diese Klasse ist nicht erzeugbar, sondern dient nur als Interface f�r alle//
//Klassen, die eine Animation ben�tigen										//
//////////////////////////////////////////////////////////////////////////////

#include "Timer.h"

namespace ProjectShipwreckLowClass
{
	class A_Animation
	{
	private:
		int animationframe;//Das ist der Frame, der an die ApplyPicture Funktion mit einem Array �bergeben wird, um das richtige Animationsbild auszuschneiden
		ProjectShipwreckHighClass::Timer * p_AnimationTimer;// Der AnimationTimer, der f�r das Timing der Animation zust�ndig ist
	public:
		A_Animation(){p_AnimationTimer = new ProjectShipwreckHighClass::Timer();}
		virtual ~A_Animation(){delete p_AnimationTimer;}
		virtual void render() = 0;// vollkommen abstrakte Funktion, die die Klasse, an die diese Klasse vererbt wurde zwingt die FUnktion zu implementieren

	};





}



//------------------------------------------------------END OF FILE--------------------------------------------------------------------------------------