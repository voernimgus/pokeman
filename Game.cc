#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <iostream>
#include "Game.h"
using namespace std;

SDL_Surface* screen = NULL;
/*SDL_Event event;*/

// borde kasta undantag om screen == NULL, sköter initiering av SDL samt screen
// ska ladda alla filer!
bool Game::init() {
  if (SDL_Init(SDL_INIT_EVERYTHING == -1)) return false;
  screen = SDL_SetVideoMode(Screen_Width, Screen_Height, BPP, SDL_SWSURFACE);
  if (screen == NULL) return false;
  SDL_WM_SetCaption("Ultra Pokéman 3400 v.BÄNKA MERA", NULL);
}

// läser in bild från fil till minnen, optimerar den så den kan kopieras och skit
SDL_Surface* Game::load_image(string filename) {
    SDL_Surface* Image = IMG_Load(filename.c_str());
    SDL_Surface* optimizedImage = NULL;
    if(Image != NULL) {
        optimizedImage = SDL_DisplayFormat(Image);
        SDL_FreeSurface(Image);
        if(optimizedImage != NULL) {
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF ) );
        }
    }
    return optimizedImage;
}

void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip=NULL) {
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface( source, clip, destination, &offset );
}

bool Game::load_files() {
  player.set_sprite(load_image("player.jpg"));
  if (player.get_sprite() == NULL) return false;
  return true;
}

void Game::clean_up() {
  SDL_FreeSurface(player.get_sprite());
  SDL_Quit();
}

int main(int argc, char* args[]) {
  bool quit = false;
  Game speljavel;
  if (speljavel.init() == false) return -1;
  if (speljavel.load_files() == false) return -1;
  while (quit == false) 
    while (SDL_PollEvent(&speljavel.player.event)) {
      speljavel.player.keyboard_input();
      if (speljavel.player.event.type == SDL_Quit) quit = true;
      speljavel.player.move();
      SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0x22, 0x8B, 0x22));
      apply_surface(speljavel.player.get_x(),
		    speljavel.player.get_y(),
		    speljavel.player.get_sprite(),
		    screen);
      if (SDL_Flip(screen) == -1) return -1;
    }
  speljavel.clean_up();
  return 0;
} 
