/**
 * Programme test de Piece
 *
 * @file testPiece.cxx
 */

// Utile pour l'affichage
#include <iostream>
#include "Piece.h"
#include "Joueur.h"
#include "Echiquier.h"
#include "JoueurBlanc.h"

// Pour utiliser les flux de iostream sans mettre "std::" tout le temps.
using namespace std;

bool compare(const Piece &p1, const Piece &p2)
{
    return (p1.x()==p2.x()) && (p1.y()==p2.y());
}

void saisie(int &x, int &y)
{
    cout << "Tapez vos coordonnees x,y" << endl;
    cout << "x :";
    cin >> x;
    cout<<"y :";
    cin >> y;
}

/**
 * Programme principal
 */
int main( int argc, char** argv )
{
    // Cr�ation de l'�chiquier
    Echiquier e;
    e.affiche(); // Le plateau est vide

    // Cr�ation des joueurs et des pi�ces associ�es
    JoueurBlanc jb;
    JoueurNoir jn;

    // On place les pi�ces des joueurs sur l'�chiquier
    jb.placerPieces(e);
    jn.placerPieces(e);

    // D�but du jeu
    e.affiche();

    bool tourJb = true;
    int position_x, postion_y;
    while (true) // Fin de tour � g�rer TODO
    {
        cout << "Debut tour joueur " << (tourJb ? "blanc" : "noir") << endl;
        saisie(position_x, postion_y);
        tourJb ? jb.jouer(e,position_x, postion_y) : jn.jouer(e,position_x, postion_y);
        cout<<position_x<<endl;
        tourJb = !tourJb;
    }
}
