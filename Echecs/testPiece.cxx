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

    Piece p3=p1; // constructeur par copie
    p3=p2; // affectation

    p3=p1.plusforte(p2);

    Echiquier e;
    e.affiche();

    JoueurBlanc jb;
    JoueurNoir jn;

    jb.affiche();
    jn.affiche();

    jb.placerPieces(e);
    jn.placerPieces(e);

    Roi rb(true);
    Roi rn(false);
    Reine qb(true);
    Reine qn(false);

    Fou fn(false);
    Fou fb(true);
    Tour tb(true);
    Tour tn(false);

    Piece *ptr;
    ptr = &p3;

    // Suppression des pieces inutiles.
    ptr = e.enleverPiece(5,1);
    ptr = e.enleverPiece(5,8);
    ptr = e.enleverPiece(4,1);
    ptr = e.enleverPiece(4,8);
    ptr = e.enleverPiece(3,1);
    ptr = e.enleverPiece(3,8);
    ptr = e.enleverPiece(6,1);
    ptr = e.enleverPiece(6,8);

    // Placement des pièces des joueurs.
    e.placer(&rb);
    e.placer(&rn);
    e.placer(&qb);
    e.placer(&qn);
    e.placer(&fn);
    e.placer(&fb);
    e.placer(&tb);
    e.placer(&tn);

    if (ptr->mouvementValide(e, 5,5))
        cout << "mouvement valide"<<endl;
    else
        cout << "mouvement invalide"<<endl;

    ptr = &rb;
    Roi *rptr = dynamic_cast<Roi *>(ptr);
    if (rptr != NULL)
        rptr->roque(true);
    else
        cout <<"Pb dynamic cast"<<endl;

    if (ptr->mouvementValide(e, 5,5))
        cout << "mouvement valide"<<endl;
    else
        cout << "mouvement invalide"<<endl;

    e.affiche();
}
