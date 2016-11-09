/**
 * Mise en oeuvre de Pion.h
 *
 * @file Pion.cxx
 */

// A besoin de la declaration de la classe
#include <iostream>
#include <stdlib.h>
#include <assert.h>

#include "Pion.h"

using namespace std;

Pion::Pion( bool white, int p ) : Piece(p,(white)?2:7,white)
{
    this->first_move = true;
    //cout << "Construction Pion specialisee" << endl;
}

// Suppression du const pour pouvoir modifier le pion au premier déplacement.
bool Pion::mouvementValide(Echiquier & e, int x, int y)
{
    if ((x<9 && x>0 && y<9 && y>0) == false) {
        return false;
    }

    int diffX = abs(this->m_x - x);
    int diffY = abs(this->m_y - y);

    if (this->isBlack() == true) {
        // Il faut que la direction soit montante
        if (this->m_y > y) {
            if (this->first_move == true) {
                // On peut se deplacer d'un ou deux
                this->first_move = false;
                if (diffY == 1||diffY == 2)
                    return true;
            } else {
                // On ne peut se deplacer que d'un
                if (diffY == 1) {
                    return true;
                }
            }
        }
    } else {

        // Il faut que la direction soit descendante
        if (this->m_y < y) {
            if (this->first_move == true) {
                // On peut se deplacer d'un ou deux
                this->first_move = false;
                if (diffY == 1||diffY == 2)
                    return true;
            } else {
                // On ne peut se deplacer que d'un
                if (diffY == 1) {
                    return true;
                }
            }
        }
    }

    cout << diffX << " diffy ="<<diffY<<endl;

    return false;
}

char Pion::myChar()
{
  return m_white?'P':'p';
}

bool Pion::prisePossible(Echiquier &e, int x, int y) {

    int _x = this->m_x; // Position de la piece
    int _y = this->m_y;

    bool priseOK = false;

    if(this->isWhite() == true) {

        if( _y < y && ( (_x - x == -1) || (_x - x == 1) ) && this->first_move == false && (e.getPiece(x,y) != 0) ) {

            priseOK = true;
        }
    }
    if(this->isWhite() == false) {

        if( _y > y && ( (_x - x == -1) || (_x - x == 1) ) && this->first_move == false && (e.getPiece(x,y) != 0)  ) {

                priseOK = true;
            }
    }

    return priseOK;

}

bool Pion::deplacementOK(Echiquier &e, int x, int y) {

    int _x = this->m_x; // Position de la piece
    int _y = this->m_y;

    bool depOK = true;
    int i;

    if()

    if( _x != x) {
    }
}
