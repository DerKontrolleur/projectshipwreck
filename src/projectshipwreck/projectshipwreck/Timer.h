

#ifndef TIMER_H
#define TIMER_H

#include <SDL.h>
#include <iostream>
using namespace std;

namespace ProjectShipwreckHighClass
{

class Timer
{
    private:
    Uint32 m_tStartTicks;

  
    Uint32 m_tPausedTicks;


    bool m_bTimerPaused;
    bool m_bTimerStarted;

    public:
  
		Timer();
		~Timer() {cout << "Destructor Timer called" << endl;}

    
    void start();
    void stop();
    void pause();
    void unpause();

   
    Uint32 Getticks();

   
    bool IsTimerStarted();
    bool IsTimerPaused();
};

}

#endif



//------------------------------------------------------END OF FILE--------------------------------------------------------------------------------------