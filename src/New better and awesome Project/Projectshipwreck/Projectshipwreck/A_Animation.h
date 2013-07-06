#pragma once

#include "Timer.h"

namespace ProjectShipwreckLowClass
{
	class A_Animation
	{
	private:
		int animationframe;
		ProjectShipwreckHighClass::Timer * p_AnimationTimer;
	public:
		A_Animation(){p_AnimationTimer = new ProjectShipwreckHighClass::Timer();}
		virtual ~A_Animation(){delete p_AnimationTimer;}
		virtual void render() = 0;
	};





}