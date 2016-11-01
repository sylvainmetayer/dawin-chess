/**
 * Mise en oeuvre de Piece.h
 *
 * @file Piece.cxx
 */

// A besoin de la declaration de la classe
#include <iostream>
#include <stdlib.h>

#include "Roi.h"

using namespace std;


Roi::Roi(bool white) : Piece(5,white ? 1:8, white)
{
    cout << "Construction Roi specialisee" << endl;
}

bool Roi::mouvementValide(Echiquier &e, int x, int y) const
{
    int diffX = abs(this->m_x - x);
    int diffY = abs(this->m_y - y);

    return false;
}

char Roi::myChar()
{
    return m_white ? 'R' : 'r';
}

void Roi::roque(bool left)
{
    cout <<"roque de" << (left ? "gauche":"droit")<< " de Roi"<<endl;
}
