/**
 * Mise en oeuvre de Tour.h
 *
 * @file Tour.cxx
 */

// A besoin de la declaration de la classe
#include <iostream>
#include <stdlib.h>
#include <assert.h>

#include "Tour.h"

#include "Piece.h"
using namespace std;

Tour::Tour(bool white, bool left) : Piece(left ? 1 : 8,white ? 1:8, white)
{
    //cout << "Construction Tour specialisee" << endl;
}

bool Tour::mouvementValide(Echiquier &e, int x, int y)
{
    assert(x<9 && x>0 && y<9 && y>0);

    int diffX = abs(this->m_x - x);
    int diffY = abs(this->m_y - y);

    if (diffX != 0 && diffY != 0)
        return false;

    return true;
}

char Tour::myChar()
{
    return m_white ? 'T' : 't';
}
