/**
 * Programme test de Piece
 *
 * @file testPiece.cxx
 */

// Utile pour l'affichage
#include <iostream>
#include "Piece.h"
#include "Joueur.h"

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
    // instancie un objet p1 de type Piece
    Piece p1;
    // p1 est une piece blanche de coordonnees (3,3)
    p1.init( 3, 3, true );
    // instancie un objet p2 de type Piece
    Piece p2( 4, 4, false);

    if (p2.isBlack())
    {
        cout << "Piece noire" << endl;
    }
    else
    {
        cout << "Piece blanche" << endl;
    }

    // On l'affiche
    p1.affiche();
    p2.affiche();

    if (compare(p1,p2))
        cout << "memes positions" << endl;
    else
        cout << "differentes positions" << endl;

    Piece p3 = p1;
    p3 =p2;

    p3 = p1.plusforte(p2);
    // Piece tbl[4];
    //Joueur jb(true);
    //Joueur jn(false);
    //jb.affiche();
    //jn.affiche();

    // les objets definis dans cette fonction sont automatiquement détruits.
    // Ex : p1
}
