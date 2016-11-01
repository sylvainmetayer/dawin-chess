/**
 * Mise en oeuvre de Pion.h
 *
 * @file Pion.cxx
 */

// A besoin de la declaration de la classe
#include <iostream>
#include "Pion.h"

using namespace std;

Pion::Pion( bool white, int p ) : Piece(p,(white)?2:7,white)
{
  cout << "Construction Pion specialisee" << endl;
}

bool Pion::mouvementValide(Echiquier & e, int x, int y)
{
  cout << "mouvementValide de Pion" << endl;
  return false;
}

char Pion::myChar()
{
  return m_white?'P':'p';
}
