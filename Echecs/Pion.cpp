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
    if ((x<9 && x>0 && y<9 && y>0) == false)
    {
        return false;
    }

    int diffX = abs(this->m_x - x);
    int diffY = abs(this->m_y - y);

    bool moveOK = false;

    if (diffX != 0)
    {
        moveOK = false;
    }
    else
    {
        if (this->isBlack() == true)
        {
            // Il faut que la direction soit montante
            if (this->m_y > y)
            {
                if (this->first_move == true)
                {
                    // On peut se deplacer d'un ou deux
                    this->first_move = false;
                    if (diffY == 1||diffY == 2)
                        moveOK = true;
                }
                else
                {
                    // On ne peut se deplacer que d'un
                    if (diffY == 1)
                    {
                        moveOK = true;
                    }
                }
            }
        }
        else
        {

            // Il faut que la direction soit descendante
            if (this->m_y < y)
            {
                if (this->first_move == true)
                {
                    // On peut se deplacer d'un ou deux
                    this->first_move = false;
                    if (diffY == 1||diffY == 2)
                        moveOK = true;
                }
                else
                {
                    // On ne peut se deplacer que d'un
                    if (diffY == 1)
                    {
                        moveOK = true;
                    }
                }
            }
        }

        if (moveOK == true && e.getPiece(x,y) != 0) {
            // On ne peut pas faire le déplacement, le déplacement est correct mais on ne peut prendre les pieces qu'en diagonales
            cout << "Le mouvement du pion est correct, mais il ne peut prendre une piece verticalement."<<endl;
            moveOK = false;
        }

    }

    cout << "MoveOK : "<< (moveOK == true ? "VRAI":"FAUX") <<endl;
    cout << "Prise possible " << ( prisePossible(e, x, y) ? "VRAI" : "FAUX")<<endl;

    if(prisePossible(e, x, y))
    {
        // Regle particuliere de deplacement pour le pion pour prendre une piece
        return true;
    }

    if (!prisePossible(e, x, y) && diffX != 0)
    {
        // Un pion ne peut pas se déplacer en diagonale sans prendre de piece !
        return false;
    }

    return moveOK;
}

char Pion::myChar()
{
    return m_white?'P':'p';
}

bool Pion::prisePossible(Echiquier &e, int x, int y)
{

    // Position de la piece
    int _x = this->m_x;
    int _y = this->m_y;

    // Différence piece / eatMe
    int diffX = abs(_x - x);
    int diffY = abs(_y - y);

    Piece *eatMe = e.getPiece(x,y);

    if (eatMe == 0)
    {
        // Pas de prise possible puisque pas de piece
        return false;
    }


    if (this->first_move == true)
    {
        // La prise se fait uniquement en diagonale, de 1 ou 2 en y puisque premier mouvement.
        // De plus, il faut que les couleurs de piece soient différentes.
        if ( ((diffX==1 && diffY==1)||(diffX==1 && diffY==2)) && this->isWhite() != eatMe->isWhite() )
            return true;
    }
    else
    {
        if ( ((diffX==1 && diffY==1)) && this->isWhite() != eatMe->isWhite() )
            return true;
    }

    return false;
}

bool Pion::deplacementOK(Echiquier &e, int x, int y)
{

    int _x = this->m_x; // Position de la piece
    int _y = this->m_y;

    bool depOK = false;
    int i;

    // FIXME On ne commit pas quand on ne finit pas une fonction :'(
    // TODO Supprimer le return true une fois que la fonction sera corrigée.
    return true;

    if( _x != x && prisePossible(e, x, y) == true)
    {
    }

    //if(this->)
}

char* Pion::getNomPiece()
{
    return "Pion";
}
