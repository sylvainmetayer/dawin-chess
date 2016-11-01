/**
 * Mise en oeuvre de Fou.h
 *
 * @file Fou.cxx
 */

// A besoin de la declaration de la classe
#include <iostream>
#include "Fou.h"

using namespace std;

Fou::Fou(bool white, bool left) : Piece( left ? 3 : 6,white ? 1:8, white)
{
    cout << "Construction Fou specialisee" << endl;
}

bool Fou::mouvementValide(Echiquier &e, int x, int y) const
{
    cout <<"Mouvement valide"<<endl;
    return false;
}

char Fou::myChar()
{
    return m_white ? 'F' : 'f';
}
