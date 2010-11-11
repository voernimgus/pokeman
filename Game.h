/*
 * IDA Programvaruproduktion AB (u.p.a.) 
 *
 * IDENTIFIERING 
 *
 * Filnamn:    Game.h 
 * Enhetsnamn: Game
 * Typ:        Definitioner hörande till klassen Game
 * Revision:   0.1
 * Skriven av: en bamsepenis
 * 
 *
 * BESKRIVNING 
 * 
 * 
 *
 * REVISIONSBERÄTTELSE 
 * 
 * Revision     Datum   Förändringar 
 * 0.1          101109  Dokumentet skapas
 */

#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include <string>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

using namespace std;

const int Screen_Width = 640;
const int Screen_Height = 480;
const int BPP = 32;
const int FPS = 20;


class Game {
 public:
  /*Game();
    ~Game();*/
  void run();
  bool init(); //initierar meny och start av spelet
  /* void handle_input(); //sköter tangentbordet*/
  bool load_files();
  void update_on_screen();
  void load_game();
  void clean_up();
  SDL_Surface* load_image(string);
  Player player;
};

#endif


