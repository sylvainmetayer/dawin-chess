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
#include "Echiquier.h"


using namespace std;

Fou::Fou(bool white, bool left) : Piece( left ? 3 : 6,white ? 1:8, white)
{
    //cout << "Construction Fou specialisee" << endl;
}

bool Fou::mouvementValide(Echiquier &e, int x, int y)
{
    bool mooveOK = false; // Valeur a retourne a la fin de la fonction
    bool isOver = false; // bool pour le while
    int _x = this->m_x; // Position de la piece
    int _y = this->m_y;

    if ((x<9 && x>0 && y<9 && y>0) == false) {
        mooveOK = false;
    }

    if(_x == x || _y == y)
        mooveOK = false;

    while(!isOver) {
        if( _x < x && _y < y) { // test diagonal bas droit
            tmpY = _y;
            for(i = (_x + 1); i < 9; i++) {
                tmpY = tmpY +1;
                if( i == x && tmpY == y) {
                    mooveOK = true;
                    isOver = true;
                }
            }
        }
        if( _x > x && _y < y) { // test diagonal bas gauche
        tmpY = _y;
            for(i = (_x - 1); i < 0; i--) {
                tmpY = tmpY +1;
                if( i == x && tmpY == y) {
                    mooveOK = true;
                    isOver = true;
                }
            }
        }

        if( _x > x && _y > y) { // test diagonal haut gauche

            tmpY = _y;
            for(i = (_x - 1); i < 0; i--) {
                tmpY = tmpY - 1;
                if( i == x && tmpY == y) {
                    mooveOK = true;
                    isOver = true;
                }
            }
        }

        if( _x > x && _y > y) { // test diagonal haut droit

            tmpY = _y;
            for(i = (_x + 1); i < 9; i++) {
                tmpY = tmpY - 1;
                if( i == x && tmpY == y) {
                    mooveOK = true;
                    isOver = true;
                }
        }
    }

    return mooveOK;
}

char Fou::myChar()
{
    return m_white ? 'F' : 'f';
}

/**
 * Recupere la piece situee sur une case.
 * @param Echiquier
 * @param x un entier entre 1 et 8
 * @param y un entier entre 1 et 8
 *
 * @return true si le deplacement et possible, false si non
 */
 bool Fou::deplacementOK(Echiquier &e, int x, int y) {


    int _x = this->m_x; // Position de la piece
    int _y = this->m_y;
    int tmpY = 0;

    int i,j;

    bool depOK = true;

    if( _x < x && _y < y) { // test diagonal bas droit
        tmpY = _y;
        for(i = (_x + 1); i < 9; i++) {
            tmpY = tmpY +1;
            if(e.getPiece(x,tmpY) != 0) {
                depOK = false;
                break;
            }
        }
    }

    if( _x > x && _y < y) { // test diagonal bas gauche
        tmpY = _y;
        for(i = (_x - 1); i < 0; i--) {
            tmpY = tmpY +1;
            if(e.getPiece(x,tmpY) != 0) {
                depOK = false;
                break;
            }
        }
    }

    if( _x > x && _y > y) { // test diagonal haut gauche

        tmpY = _y;
        for(i = (_x - 1); i < 0; i--) {
            tmpY = tmpY - 1;
            if(e.getPiece(x,tmpY) != 0) {
                depOK = false;
                break;
            }
        }
    }

    if( _x > x && _y > y) { // test diagonal haut droit

        tmpY = _y;
        for(i = (_x + 1); i < 9; i++) {
            tmpY = tmpY - 1;
            if(e.getPiece(x,tmpY) != 0) {
                depOK = false;
                break;
            }
        }
    }

    return depOK;

 }
