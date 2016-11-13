/**
 * Mise en oeuvre de Fou.h
 *
 * @file Fou.cxx
 */

#include <iostream>
#include <stdlib.h>

#include "Fou.h"
#include "Echiquier.h"

using namespace std;

Fou::Fou(bool white, bool left) : Piece( left ? 3 : 6,white ? 1:8, white) {}

bool Fou::mouvementValide(Echiquier &e, int x, int y)
{
    int _x = this->m_x; // Position de la piece
    int _y = this->m_y;

    if ((x<9 && x>0 && y<9 && y>0) == false)
    {
        return false;
    }

    int diffX = abs(_x - x);
    int diffY = abs(_y - y);

    if (diffX == diffY)
        return true;

    return false;
}

char Fou::myChar()
{
    return m_white ? 'F' : 'f';
}

bool Fou::deplacementOK(Echiquier &e, int x, int y)
{
    int _x = this->m_x; // Position de la piece
    int _y = this->m_y;
    int tmpY = 0;
    int i;

    bool depOK = true;

    if( _x < x && _y < y)   // test diagonal bas droit
    {
        tmpY = _y;
        for(i = (_x + 1); i < 9; i++)
        {
            tmpY = tmpY +1;
            if(e.getPiece(x,tmpY) != 0)
            {
                depOK = false;
                break;
            }
        }
    }

    if( _x > x && _y < y)   // test diagonal bas gauche
    {
        tmpY = _y;
        for(i = (_x - 1); i < 0; i--)
        {
            tmpY = tmpY +1;
            if(e.getPiece(x,tmpY) != 0)
            {
                depOK = false;
                break;
            }
        }
    }

    if( _x > x && _y > y)   // test diagonal haut gauche
    {

        tmpY = _y;
        for(i = (_x - 1); i < 0; i--)
        {
            tmpY = tmpY - 1;
            if(e.getPiece(x,tmpY) != 0)
            {
                depOK = false;
                break;
            }
        }
    }

    if( _x > x && _y > y)   // test diagonal haut droit
    {

        tmpY = _y;
        for(i = (_x + 1); i < 9; i++)
        {
            tmpY = tmpY - 1;
            if(e.getPiece(x,tmpY) != 0)
            {
                depOK = false;
                break;
            }
        }
    }

    return depOK;

}

char* Fou::getNomPiece()
{
    return "Fou ";
}
