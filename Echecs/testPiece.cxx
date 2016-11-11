/**
 * Programme test de Piece
 *
 * @file testPiece.cxx
 */

#include "testPiece.h"

using namespace std;

// http://cpp.developpez.com/faq/cpp/?page=Manipulation-de-la-console#Comment-verifier-les-valeurs-saisies-avec-cin
bool read_choice( int & N )
{
    while ( ! ( cin >> N ) || N < 1 || N > 8 )
    {
        if ( cin.eof() )
        {
            // ^D  (^Z sous windows); Fin du flux d'entree !
            return false;
        }
        else if ( cin.fail() )
        {
            cout << "Saisie incorrecte, recommencez : ";
            cin.clear();
            cin.ignore( numeric_limits<streamsize>::max(), '\n' );
        }
        else
        {
            cout << "Le chiffre n'est pas entre 1 et 8, recommencez : ";
        }
    }
    return true; // succès
}

void saisie(int &x, int &y)
{
    cout << "x :";
    read_choice(x);
    cout<<"y :";
    read_choice(y);
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
    int gameOver;
    int position_x, postion_y;

    jb.placerPieces(e);
    jn.placerPieces(e);

    cout << "---------------------" << endl;
    cout << "Bienvenue sur l'echiquier de la DoomPr0gTeam " << endl;
    cout << "---------------------" << endl;

    while (true) // Fin de tour à gérer TODO
    {
        cout << "---------" << endl;
        cout << "Tour joueur " << (tourJb ? "blanc" : "noir") << endl;
        e.affiche();

        cout << "Selectionner la piece a deplacer :" << endl;
        saisie(position_x, postion_y);
        Piece *piece = e.getPiece(position_x, postion_y);

        while (piece == NULL || piece->isWhite() != tourJb)
        {
            cout << "Piece non existante ou ce n'est pas la votre" << endl;
            cout << "Merci de recommencer." << endl;

            saisie(position_x, postion_y);
            piece = e.getPiece(position_x, postion_y);
        }

        piece->affiche();
        cout << "Destination :" << endl;
        saisie(position_x, postion_y);

        if (!e.deplacer(piece, position_x, postion_y))
        {
            cout << "Le deplacement a echoue (deplacement non valide ou impossible)." << endl;
            tourOK = false;
        }
        else
        {
            tourOK = true;
        }

        if (tourOK)
        {
            gameOver = e.gameOver();
            if (gameOver != 0)
            {
                cout << "Bravo Joueur " << (gameOver == 1 ? "Blanc":"Noir") <<", tu as gagne !"<<endl;
                exit(0);
            }

            // Le tour s'est bien passé, joueur suivant !
            tourJb = !tourJb;
        }
        else
        {
            // Quelque chose ne s'est pas passé correctement, le joueur corrige son tour.
            cout << "Joueur " << (tourJb ? "blanc" : "noir") << ", votre tour n'est pas valide. Recommencez"<< endl;
        }
    }
}
