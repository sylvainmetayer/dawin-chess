/**
 * Mise en oeuvre de Tour.h
 *
 * @file Tour.cxx
 */

// A besoin de la declaration de la classe
#include <iostream>
#include "Tour.h"

#include "Piece.h"
using namespace std;


Tour::Tour(bool white, bool left) : Piece(left ? 1 : 8,white ? 1:8, white)
{
    cout << "Construction Tour specialisee" << endl;
}

bool Tour::mouvementValide(Echiquier &e, int x, int y) const
{
    cout <<"Mouvement valide"<<endl;
    return false;
}

char Tour::myChar()
{
    return m_white ? 'T' : 't';
}
