// nQueensProblem.cpp : Defines the entry point for the console application.
//
#ifndef POPULATION_H
#define POPULATION_H

#include <iostream>
#include "Population.h"

int main() {

  Population<5>* population = NULL;
  const char helpStr[] =
    "This is a Helpstr\n"
    "It is here to help.\n";

  population = new Population<5>;
  population->fnRateFitness();

  population->print(std::cout); // TODO: Segfault, probably ChessBoard ** in Population.h



  return 0;

}

#endif //POPULATION_H
