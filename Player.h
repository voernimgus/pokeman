#ifndef PLAYER_H
#define PLAYER_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"


class Player {
 public: 
  Player();
  void keyboard_input();
  void move();
  SDL_Surface* get_sprite();
  SDL_Surface* set_sprite(SDL_Surface*);
  int get_x();
  int get_y();
  SDL_Event event;
  /*void update_on_screen();*/
 private:
  SDL_Surface* sprite;
  int x,y;
  int xVel, yVel;
  int Height, Width;
};


#endif
