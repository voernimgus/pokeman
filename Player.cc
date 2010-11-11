#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "Player.h"
#include "Game.h"

Player::Player() 
  : x(0), y(0), xVel(0), yVel(0), Height(20), Width(20), sprite(NULL) { }

// sköter hantering av när knappen trycks ner och när den släpps upp
// tänk på att sdl har tard-koordinatsystem
void Player::keyboard_input() {
  if (event.type == SDL_KEYDOWN) {   
    switch (event.key.keysym.sym) {
    case SDLK_UP: yVel -= Height; break;
    case SDLK_DOWN: yVel += Height; break;
    case SDLK_LEFT: xVel -= Width; break;
    case SDLK_RIGHT: xVel += Width; break;
    }
  }
  else if (event.type == SDL_KEYUP) {   
    switch (event.key.keysym.sym) {
    case SDLK_UP: yVel += Height; break;
    case SDLK_DOWN: yVel -= Height; break;
    case SDLK_LEFT: xVel += Width; break;
    case SDLK_RIGHT: xVel -= Width; break;
    }
  }
}

int Player::get_x() {
  return x;
}

int Player::get_y() {
  return y;
}

SDL_Surface* Player::get_sprite() {
  return sprite;
}

SDL_Surface* Player::set_sprite(SDL_Surface* sprite_) {
  sprite = sprite_;
}

// uppdaterar spelarens position och sköter kanthantering!
void Player::move() {
  x += xVel;
  if (x<0 || (x + Width > Screen_Width)) x -= xVel;
  y += yVel;
  if (y<0 || (y + Height > Screen_Height)) y -= yVel;
}

/*void Player::update_on_screen() {
  apply_surface(x,y,player,screen);
  }*/
