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

// Pour utiliser les flux de iostream sans mettre "std::" tout le temps.
using namespace std;

bool compare(const Piece &p1, const Piece &p2)
{
    return (p1.x()==p2.x()) && (p1.y()==p2.y());
}

/**
 * Programme principal
 */
int main( int argc, char** argv )
{
    // Création de l'échiquier
    Echiquier e;
    e.affiche(); // Le plateau est vide

    // Création des joueurs et des pièces associées
    JoueurBlanc jb;
    JoueurNoir jn;

    // On place les pièces des joueurs sur l'échiquier
    jb.placerPieces(e);
    jn.placerPieces(e);

    // Début du jeu
    e.affiche();
}
