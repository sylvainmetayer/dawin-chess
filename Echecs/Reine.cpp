/**
 * Mise en oeuvre de Reine.h
 *
 * @file Reine.cpp
 */

// A besoin de la declaration de la classe
#include <iostream>
#include "Reine.h"

using namespace std;

bool Reine::mouvementValide(Echiquier &e, int x, int y)
{
    return Fou::mouvementValide(e,x,y) || Tour::mouvementValide(e,x,y);
}

char Reine::myChar()
{
    return m_white ? 'Q' : 'q';
}

Reine::Reine(bool white) : Piece(4, (white?1:8), white ),
                Fou(white, true), Tour(white, true)
{
    m_white = white;
    //cout << "Construction Reine specialisee" << endl;
}

bool Reine::deplacementOK(Echiquier &e, int x, int y)
{
    return Fou::deplacementOK(e,x,y) || Tour::deplacementOK(e, x, y);
    // TODO have fun
}

char* Reine::getNomPiece()
{
    return "Reine";
}
