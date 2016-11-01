/**
 * Mise en oeuvre de Cavalier.h
 *
 * @file Cavalier.cpp
 */

// A besoin de la declaration de la classe
#include <iostream>
#include "Cavalier.h"

using namespace std;


bool Cavalier::mouvementValide(Echiquier & e, int x, int y)
{
  cout << "mouvementValide de Cavalier" << endl;
  return false;
}

char Cavalier::myChar()
{
  return m_white?'C':'c';
}

Cavalier::Cavalier( bool white, bool left ) : Piece((left)?2:7,(white)?1:8,white)
{
  cout << "Construction Cavalier specialisee" << endl;
}
