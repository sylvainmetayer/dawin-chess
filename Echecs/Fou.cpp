/**
 * Mise en oeuvre de Fou.h
 *
 * @file Fou.cxx
 */

// A besoin de la declaration de la classe
#include <iostream>
#include <stdlib.h>
#include <assert.h>

#include "Fou.h"


using namespace std;

Fou::Fou(bool white, bool left) : Piece( left ? 3 : 6,white ? 1:8, white)
{
    //cout << "Construction Fou specialisee" << endl;
}

bool Fou::mouvementValide(Echiquier &e, int x, int y)
{
    assert(x<9 && x>0 && y<9 && y>0);

    int diffX = abs(this->m_x - x);
    int diffY = abs(this->m_y - y);

    if (diffX != diffY)
        return false;

    return true;
}

char Fou::myChar()
{
    return m_white ? 'F' : 'f';
}
