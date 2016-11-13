/**
 * Programme test de Piece
 *
 * @file testPiece.cxx
 */

#include "testPiece.h"

using namespace std;

/**
* Fonction de saisie sécurisée, afin de s'assurer que le
* jeu ne crashe pas si l'on saisit autre chose qu'un entier.
* La saisie est autorisée s'il s'agit d'un nombre entre 1 et 8
* @param n Le nombre qui contiendra le résultat de la saisie.
* Cette fonction est tirée du site ci-dessous.
* @see http://cpp.developpez.com/faq/cpp/?page=Manipulation-de-la-console#Comment-verifier-les-valeurs-saisies-avec-cin
* @return true ou false selon que la saisie est réussie ou non.
*/
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
    return true;
}

/**
* Fonction qui permet de saisir les valeurs x et y en appelant la saisie sécurisée.
* @param x : la valeur x à saisir
* @param y : la valeur y à saisir.
*/
void saisie(int &x, int &y)
{
    cout << "x :";
    read_choice(x);
    cout<<"y :";
    read_choice(y);
}

/**
* Dans le cas ou l'on se trouve en échecs, cette fonction est appelée afin de gérer le cas.
* Elle va demander au joueur en echec de jouer, et vérifier s'il est toujours en échec.
* Si oui, alors il sera échec et mat.
* @param e : l'échiquier
* @param joueur : Le joueur en echec
* @param autreJoueur : l'autre joueur
*/
void handleChess(Echiquier &e, Joueur &joueur, Joueur &autreJoueur)
{

    bool whiteTurn = joueur.isWhite() == true ? true : false;
    int position_x, position_y;

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

    if (e.chess(autreJoueur, joueur, e.getKing(whiteTurn)->x(), e.getKing(!whiteTurn)->y() ) == true )
    {
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
    bool tourJoueurBlanc = true;

    bool tourOK = false;
    int position_x, position_y;

    jb.placerPieces(e);
    jn.placerPieces(e);

    cout << "---------------------" << endl;
    cout << "Bienvenue sur l'echiquier de la DoomPr0gTeam " << endl;
    cout << "---------------------" << endl;

    while (true)
    {
        cout << "---------" << endl;
        cout << "Tour joueur " << (tourJoueurBlanc ? "blanc" : "noir") << endl;

        if (DEBUG)
        {
            cout << "Etat du jeu" << endl;
            cout << "Tour " << (tourJoueurBlanc == true ? "BLANC" : "NOIR") << endl;
            cout << "JB chessMat" << (jb.getChessMat() == true ? "O":"N") << endl;
            cout << "JN chessMat" << (jn.getChessMat() == true ? "O":"N") << endl;
            cout << "JB onChess " << (jb.getOnChess() == true ? "O" : "N") << endl;
            cout << "JN onChess " << (jn.getOnChess() == true ? "O" : "N") << endl;
        }


        if (e.checkChessMat(jb))
            exit(0);

        if (e.checkChessMat(jn))
            exit(0);

        e.affiche();

        if(tourJoueurBlanc == true && jb.getOnChess() == true)
        {
            if (DEBUG)
                cout << "JB en echec"<<endl;
            handleChess(e, jb, jn);
        }
        else if (tourJoueurBlanc == false && jn.getOnChess() == true)
        {
            if (DEBUG)
                cout << "JN en echec"<<endl;
            handleChess(e, jn, jb);
        }
        else
        {
            // Tour normal.
            cout << "Selectionner la piece a deplacer :" << endl;
            saisie(position_x, position_y);
            Piece *piece = e.getPiece(position_x, position_y);

            while (piece == NULL || piece->isWhite() != tourJoueurBlanc)
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
                if(tourJoueurBlanc == true)
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
                tourJoueurBlanc = !tourJoueurBlanc;
            }
            else
            {
                // Quelque chose ne s'est pas passé correctement, le joueur corrige son tour.
                cout << "Joueur " << (tourJoueurBlanc ? "blanc" : "noir") << ", votre tour n'est pas valide. Recommencez"<< endl;
            }
        }
    }
    return 0;
}
