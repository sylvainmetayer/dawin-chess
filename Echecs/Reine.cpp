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

    return Fou::mouvementValide(e,x,y) || Tour::mouvementValide(e, x, y);
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

bool Reine::deplacementOK(Echiquier &e, int x, int y) {

    int _x = this->m_x; // Position de la piece
    int _y = this->m_y;

    int i;
    int tmpY = 0;

    bool depOK = true;

    if(_x == x && _y < y) {
        for(i = (_y + 1) ; i < 9; i++) {
            if(e.getPiece(x, i) != 0) {
                depOK = false;
                break;
            }
        }
    }

    if(_x == x && _y > y) {
        for(i = (_y - 1); i > 0; i--) {
            if(e.getPiece(x, i) != 0) {
                depOK = false;
                break;
            }
        }
    }

    if(_y == y && _x < x) {
        for(i = (_x + 1); i < 9; i++) {
            if(e.getPiece(i, y) != 0) {
                depOK = false;
                break;
            }
        }
    }

    if(_y == y && _x > x) {
        for(i = (_x - 1); i > 0; i--) {
            if(e.getPiece(i, y) != 0) {
                depOK = false;
                break;
            }
        }
    }

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

char* Reine::getNomPiece()
{
    return "Reine";
}
