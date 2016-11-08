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
    // Cr�ation de l'�chiquier
    Echiquier e;
    //e.affiche(); // Le plateau est vide

    // Cr�ation des joueurs et des pi�ces associ�es
    JoueurBlanc jb;
    JoueurNoir jn;

    // On place les pi�ces des joueurs sur l'�chiquier
    jb.placerPieces(e);
    jn.placerPieces(e);

    cout << "---------------------" << endl;
    cout << "Bienvenue sur l'echuiquier de la DoomPr0gTeam " << endl;
    cout << "---------------------" << endl;

    // D�but du jeu
    e.affiche();

//    Piece *pion = e.getPiece(1,2);
//    pion->affiche();
//
//    bool test = pion->mouvementValide(e, 1,4);
//    bool fail = pion->mouvementValide(e, 1,3);
//
//    cout << (fail == false ? "FAUX" : "VRAI")<< " "<<  (test == true ? "VRAI" : "FAUX") << endl;

    bool tourJb = true;
    bool tourOK = false;
    int position_x, postion_y;

    while (true) // Fin de tour � g�rer TODO
    {
        cout << "Debut tour joueur " << (tourJb ? "blanc" : "noir") << endl;

        cout << "Selectionner la piece a deplacer :" << endl;
        saisie(position_x, postion_y);
        Piece *piece = e.getPiece(position_x, postion_y);

        while (piece == NULL || piece->isWhite() != tourJb) {
            cout << "Piece non existante ou ce n'est pas la votre" << endl;
            cout << "Merci de recommencer." << endl;

            saisie(position_x, postion_y);
            piece = e.getPiece(position_x, postion_y);
        }

        piece->affiche();
        cout << "Destination :" << endl;
        saisie(position_x, postion_y);

        // TODO se r�f�rer � Tiphaine pour les d�placements.
        if (!piece->mouvementValide(e,x,y)) {
            cout << "Ce mouvement n'est pas valide pour cette piece."<< endl;
            tourOK = false;
        } else if (!e.deplacer(piece, x, y)) {
            cout << "Le deplacement a echoue (deplacement non valide ou impossible)." << endl;
            tourOK = false;
        } else {
            tourOK = true;
        }

        if (tourOK) {
            // Le tour s'est bien pass�, joueur suivant !
            tourJb = !tourJb;
        } else {
            // Quelque chose ne s'est pas pass� correctement, le joueur corrige son tour.
            cout << "Joueur " << (tourJb ? "blanc" : "noir") << ", ton tour n'est pas valide. Recommence"<< endl;
        }

    }
}
