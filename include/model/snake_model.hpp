#ifndef _SNAKE_MODEL_HPP
#define _SNAKE_MODEL_HPP

#include <iostream>
#include <vector>
#include "portaudio.h"

typedef struct Position{
  float x;
  float y;
}pos_2d;

typedef pos_2d vel_2d;

class Corpo {
  private:
  vel_2d velocidade;
  pos_2d posicao;

  public:
  Corpo(vel_2d velocidade, pos_2d p);
  void update(vel_2d nova_velocidade, pos_2d);
  vel_2d get_velocidade();
  pos_2d get_posicao();
};

class Snake{
  private:
    std::vector<Corpo*> *corpos;

  public:
    Snake();
    void hard_copy(Snake *ldc);
    void add_corpo(Corpo *c);
    std::vector<Corpo*> *get_corpos();
};

class ListaDeSnakes {
  private:
    std::vector<Snake*> *snakes;

  public:
    ListaDeSnakes();
    void hard_copy(ListaDeSnakes *lds);
    void add_snake(Snake *c);
    std::vector<Snake*> *get_snakes();
};

#endif