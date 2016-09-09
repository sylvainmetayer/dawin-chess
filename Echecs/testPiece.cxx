/**
 * Programme test de Piece
 *
 * @file testPiece.cxx
 */

#include "Piece.h"

#include "Joueur.h"


#include <iostream>
// Pour utiliser les flux de iostream sans mettre "std::" tout le temps.
using namespace std;

/**
* Vérifie qu'une piece et une autre sont identiques
*@return bool
*/
bool is_same_piece(Piece &p, Piece &p2)
{
    return p.x() == p2.x() && p.y() == p2.y();
}

/**
 * Programme principal
 */
int main( int argc, char** argv )
{
    // instancie un objet p1 de type Piece
    Piece p1;
    Piece p2(4,4,false);
    // p1 est une piece blanche de coordonnees (3,3)
    p1.init( 3, 3, true );

    //p1.affiche();
    //p2.affiche();

    Joueur j1(true);
    Joueur j2(false);

    //j1.affiche();
    j2.affiche();

    Piece tmp = j2.get(2);
    Piece tmp1 = j1.get(2);
    cout<< (is_same_piece( tmp1, tmp1) ? "OUI" : "NON")<<endl;
    cout<< (is_same_piece(tmp, tmp1) ? "OUI" : "NON")<<endl;
}
