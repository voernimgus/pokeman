#include "Timer.h"
#include "SDL/SDL.h"

Timer::Timer() :
  startticks(0), 
  pauseticks(0),
  paused(false), 
  started(false)
{ }

void Timer::start() {
  started = true;
  paused = false;
  startticks = SDL_GetTicks();
}

void Timer::stop() {
  started = false;
  paused = false;
}

void Timer::pause() {
  if (started == true && paused == false) {
    paused = true;
    pauseticks = SDL_GetTicks() - startticks;
  }
}

void Timer::unpause() {
  if (paused == true) {
    paused = false;
    startticks = SDL_GetTicks() - pauseticks;
    pauseticks = 0;
  }
}

int Timer::get_ticks() {
  if (started == true) {
    if (paused == true) return pauseticks;
    else return SDL_GetTicks() - startticks;
 }
 return 0;
}

bool Timer::is_started() {
return started;
}

bool Timer::is_paused() {
return paused;
}
