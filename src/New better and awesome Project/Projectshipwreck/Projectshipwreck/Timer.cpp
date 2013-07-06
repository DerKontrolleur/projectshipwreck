#include "Timer.h"

using namespace ProjectShipwreckHighClass;

Timer::Timer()
{
   
    m_tStartTicks = 0;
    m_tPausedTicks = 0;
    m_bTimerPaused = false;
    m_bTimerStarted = false;
	cout << "Constructor Timer called" << endl;
}

void Timer::start()
{
  
    m_bTimerStarted = true;

  
    m_bTimerPaused = false;

   
    m_tStartTicks = SDL_GetTicks();
}

void Timer::stop()
{

    m_bTimerStarted = false;

    
    m_bTimerPaused = false;
}

void Timer::pause()
{
    if( ( m_bTimerStarted == true ) && ( m_bTimerPaused == false ) )
    {
       
        m_bTimerPaused = true;

      
        m_tPausedTicks = SDL_GetTicks() - m_tStartTicks;
    }
}

void Timer::unpause()
{
    
    if( m_bTimerPaused == true )
    {
        
        m_bTimerPaused = false;

        
        m_tStartTicks = SDL_GetTicks() - m_tPausedTicks;

        
        m_tPausedTicks = 0;
    }
}

Uint32 Timer::Getticks()
{
    
    if( m_bTimerStarted == true )
    {
        
        if( m_bTimerPaused == true )
        {
            
            return m_tPausedTicks;
        }
        else
        {
           
            return SDL_GetTicks() - m_tStartTicks;
        }
    }

   
    return 0;
}

bool Timer::IsTimerStarted()
{
    return m_bTimerStarted;
}

bool Timer::IsTimerPaused()
{
    return m_bTimerPaused;
}
