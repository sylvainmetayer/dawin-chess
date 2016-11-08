#include <iostream>
#include <stdlib.h>
#include <assert.h>

#include "Roi.h"

using namespace std;

Roi::Roi(bool white) : Piece(5,white ? 1:8, white)
{
    //cout << "Construction Roi specialisee" << endl;
}

bool Roi::mouvementValide(Echiquier &e, int x, int y)
{
    assert(x<9 && x>0 && y<9 && y>0);

    int diffX = abs(this->m_x - x);
    int diffY = abs(this->m_y - y);

    if ((diffX == 1 && diffY == 0 )||(diffX == 0 && diffY == 1))
        return true;

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
