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

void handleChess(Echiquier &e, Joueur &joueur, Joueur &autreJoueur)
{

    bool whiteTurn = joueur.isWhite() == true ? true : false;
    int position_x, position_y;
    Piece* tmpking = e.getKing(whiteTurn);

    cout << "Attention joueur " << (whiteTurn == true ? "blanc":"noir" ) << ", vous etes en echec" << endl;

    cout << "Selectionner la piece a deplacer :" << endl;
    saisie(position_x, position_y);
    Piece *piece = e.getPiece(position_x, position_y);

    while (piece == NULL || piece->isWhite() != whiteTurn)
    {
        cout << "Piece non existante ou ce n'est pas la votre" << endl;
        cout << "Merci de recommencer." << endl;

        saisie(position_x, position_y);
        piece = e.getPiece(position_x, position_y);
    }

    piece->affiche();
    cout << "Destination :" << endl;
    saisie(position_x, position_y);

    if (!e.deplacer(piece, position_x, position_y))
    {
        cout << "Le deplacement a echoue (deplacement non valide ou impossible)." << endl;
    }

    if (e.chess(autreJoueur, joueur, e.getKing(whiteTurn)->x(), e.getKing(!whiteTurn)->y() ) == true )  {
        joueur.setChessMat(true);
    }
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
    int position_x, position_y;

    jb.placerPieces(e);
    jn.placerPieces(e);

    cout << "---------------------" << endl;
    cout << "Bienvenue sur l'echiquier de la DoomPr0gTeam " << endl;
    cout << "---------------------" << endl;

    while (true)
    {
        cout << "---------" << endl;
        cout << "Tour joueur " << (tourJb ? "blanc" : "noir") << endl;

        // DEBUG
        cout << "Etat du jeu" << endl;
        cout << "Tour " << (tourJb == true ? "BLANC" : "NOIR") << endl;
        cout << "JB chessMat" << (jb.getChessMat() == true ? "O":"N") << endl;
        cout << "JN chessMat" << (jn.getChessMat() == true ? "O":"N") << endl;
        cout << "JB onChess " << (jb.getOnChess() == true ? "O" : "N") << endl;
        cout << "JN onChess " << (jn.getOnChess() == true ? "O" : "N") << endl;

        if (e.checkChessMat(jb))
            exit(0);

        if (e.checkChessMat(jn))
            exit(0);

        e.affiche();

        // Si le joueur blanc est en echec depuis un tour
        if(tourJb == true && jb.getOnChess() == true)
        {
            handleChess(e, jb, jn);
        }
        else if (tourJb == false && jn.getOnChess() == true)
        {
            // Si le joueur noir est en echec depuis un tour.
            handleChess(e, jn, jb);
        }
        else
        {
            // Tour normal.
            cout << "Selectionner la piece a deplacer :" << endl;
            saisie(position_x, position_y);
            Piece *piece = e.getPiece(position_x, position_y);

            while (piece == NULL || piece->isWhite() != tourJb)
            {
                cout << "Piece non existante ou ce n'est pas la votre" << endl;
                cout << "Merci de recommencer." << endl;

                saisie(position_x, position_y);
                piece = e.getPiece(position_x, position_y);
            }

            piece->affiche();
            cout << "Destination :" << endl;
            saisie(position_x, position_y);

            if (!e.deplacer(piece, position_x, position_y))
            {
                cout << "Le deplacement a echoue (deplacement non valide ou impossible)." << endl;
                tourOK = false;
            }
            else
            {
                tourOK = true;

                if(tourJb == true)
                {
                    Piece* otherKing = e.getKing(false);
                    int x_king = otherKing->x();
                    int y_king = otherKing->y();
                    e.chess(jb, jn, x_king, y_king );
                }
                else
                {
                    Piece* otherKing = e.getKing(true);
                    int x_king = otherKing->x();
                    int y_king = otherKing->y();
                    e.chess(jn, jb, x_king, y_king);
                }
            }

            // Le tour s'est bien passé, joueur suivant !
            if (tourOK)
            {
                tourJb = !tourJb;
            }
            else
            {
                // Quelque chose ne s'est pas passé correctement, le joueur corrige son tour.
                cout << "Joueur " << (tourJb ? "blanc" : "noir") << ", votre tour n'est pas valide. Recommencez"<< endl;
            }
        }
    }
    return 0;
}
