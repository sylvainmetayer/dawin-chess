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
    // Initialisation
    Echiquier e;
    JoueurBlanc jb;
    JoueurNoir jn;

    // Le joueur blanc commence
    bool tourJb = true;
    bool tourOK = false;
    int position_x, postion_y;

    jb.placerPieces(e);
    jn.placerPieces(e);

    cout << "---------------------" << endl;
    cout << "Bienvenue sur l'echuiquier de la DoomPr0gTeam " << endl;
    cout << "---------------------" << endl;

    while (true) // Fin de tour à gérer TODO
    {
        cout << "---------" << endl;
        cout << "Tour joueur " << (tourJb ? "blanc" : "noir") << endl;
        e.affiche();

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

        if (!e.deplacer(piece, position_x, postion_y)) {
            cout << "Le deplacement a echoue (deplacement non valide ou impossible)." << endl;
            tourOK = false;
        } else {
            tourOK = true;
        }

        if (tourOK) {
            // Il faut check s'il s'agit de la fin de partie. TODO

            // Le tour s'est bien passé, joueur suivant !
            tourJb = !tourJb;
        } else {
            // Quelque chose ne s'est pas passé correctement, le joueur corrige son tour.
            cout << "Joueur " << (tourJb ? "blanc" : "noir") << ", votre tour n'est pas valide. Recommencez"<< endl;
        }

    }
}
