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
#include "Echiquier.h"

#include "Piece.h"
using namespace std;

Tour::Tour(bool white, bool left) : Piece(left ? 1 : 8,white ? 1:8, white)
{
    //cout << "Construction Tour specialisee" << endl;
}

bool Tour::mouvementValide(Echiquier &e, int x, int y)
{
    if ((x<9 && x>0 && y<9 && y>0) == false) {
        return false;
    }

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


/**
 * Recupere la piece situee sur une case.
 * @param Echiquier
 * @param x un entier entre 1 et 8
 * @param y un entier entre 1 et 8
 *
 * @return true si le deplacement et possible, false si non
 */
bool Tour::deplacementOK(Echiquier &e, int x, int y) {

    int _x = this->m_x; // Position de la piece
    int _y = this->m_y;

    int i;

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

    return depOK;

}

char* Tour::getNomPiece()
{
    return "Tour";
}
