/**
 * Programme test de Piece
 *
 * @file testPiece.cxx
 */

#include "testPiece.h"

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

    Piece *reine = e.getPiece(4,1);
    reine->affiche();

    bool test = reine->mouvementValide(e, 3,2);
    bool fail = reine->mouvementValide(e, 2,3);

    cout << (fail == false ? "FAUX" : "VRAI")<< " "<<  (test == true ? "VRAI" : "FAUX") << endl;

    bool tourJb = true;
    int position_x, postion_y;
    while (true) // Fin de tour à gérer TODO
    {
        cout << "Debut tour joueur " << (tourJb ? "blanc" : "noir") << endl;
        saisie(position_x, postion_y);
        tourJb ? jb.jouer(e,position_x, postion_y) : jn.jouer(e,position_x, postion_y);
        cout<<position_x<<endl;
        tourJb = !tourJb;
    }
}
