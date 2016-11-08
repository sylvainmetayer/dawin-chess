#include <iostream>
#include <stdlib.h>
#include <assert.h>

#include "Cavalier.h"

using namespace std;

bool Cavalier::mouvementValide(Echiquier & e, int x, int y)
{
    if ((x<9 && x>0 && y<9 && y>0) == false) {
        return false;
    }

    int diffX = abs(this->m_x - x);
    int diffY = abs(this->m_y - y);

    if ((diffX == 2 && diffY == 1)||(diffY == 2 && diffX == 1))
        return true;

    return false;
}

char Cavalier::myChar()
{
  return m_white?'C':'c';
}

Cavalier::Cavalier( bool white, bool left ) : Piece((left)?2:7,(white)?1:8,white)
{
  //cout << "Construction Cavalier specialisee" << endl;
}
