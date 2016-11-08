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
    //e.affiche(); // Le plateau est vide

    // Création des joueurs et des pièces associées
    JoueurBlanc jb;
    JoueurNoir jn;

    // On place les pièces des joueurs sur l'échiquier
    jb.placerPieces(e);
    jn.placerPieces(e);

    cout << "---------------------" << endl;
    cout << "Bienvenue sur l'echuiquier de la DoomPr0gTeam " << endl;
    cout << "---------------------" << endl;

    // Début du jeu
    e.affiche();

//    Piece *pion = e.getPiece(1,2);
//    pion->affiche();
//
//    bool test = pion->mouvementValide(e, 1,4);
//    bool fail = pion->mouvementValide(e, 1,3);
//
//    cout << (fail == false ? "FAUX" : "VRAI")<< " "<<  (test == true ? "VRAI" : "FAUX") << endl;

    bool tourJb = true;
    int position_x, postion_y;

    while (true) // Fin de tour à gérer TODO
    {
        cout << "Debut tour joueur " << (tourJb ? "blanc" : "noir") << endl;

        cout << "Selectionner la piece a deplacer :" << endl;
        saisie(position_x, postion_y);
        Piece *piece = e.getPiece(position_x, postion_y);

        while (piece == NULL || piece->isWhite() != tourJb) {
            cout << "Piece non existante ou ce n'est pas la votre" << endl;
            cout << "Merci de recommencer." << endl;

            saisie(position_x, postion_y);
            Piece *piece = e.getPiece(position_x, postion_y);
        }

        piece->affiche();
        cout << "Destination :" << endl;
        saisie(position_x, postion_y);

        tourJb ? jb.jouer(e,position_x, postion_y) : jn.jouer(e,position_x, postion_y);
        tourJb = !tourJb;
    }
}
