#include "Timer.h"

Timer::Timer()
{
    startAt = 0;
    //ctor
}

Timer::~Timer()
{
    //dtor
}


void Timer::start()
{
    startAt = clock();
}

void Timer::stop()
{

}

clock_t Timer::getTicks()
{
    return clock() - startAt;
}


void Timer::reset()
{
    startAt = clock();
}
