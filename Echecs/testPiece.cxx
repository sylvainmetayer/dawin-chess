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
    return true; // succ�s
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

    while (true) // Fin de tour � g�rer TODO
    {
        cout << "---------" << endl;
        cout << "Tour joueur " << (tourJb ? "blanc" : "noir") << endl;
        e.affiche();

        if(tourJb == true && jb.chessMat == true && jb.onChess == true) {
            cout << "Joueur blanc, vous �tes echec et mat" << endl;
            cout << "Joueur noir, vous avez gagn�" << endl;
        }
        else if(tourJb == false && jn.chessMat == true && jn.onChess == true) {
            cout << "Joueur noir, vous �tes echec et mat" << endl;
            cout << "Joueur blanc, vous avez gagn�" << endl;
        }
        else if(tourJb == true && jb.onChess == true) { // Si le joueur est en echec
            cout << "Attention joueur blanc, vous etes en echec" << endl;
            Piece* tmpking = e.getKing(true);
            int untilMat = 3;
            cout << "Il vous reste " << untilMat << "essai(s) avant d'etre echec et mat" << endl;

            while(jb.onChess && untilMat > 0) {

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
                    if(piece->isWhite() == true) {
                        Piece* otherKing = e.getKing(false);
                        int x_king = otherKing->x();
                        int y_king = otherKing->y();
                        e.chess(&jb, &jn, x_king, y_king );
                        if(e.chess(&jb, &jn, x_king, y_king) == true ) {
                            untilMat--;
                        }
                    } else {
                        cout << "Erreur "<<endl;
                        exit(1);
                    }
                }


            }
           // coupPossibleChess( tmpking);

        }

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
            if(piece->isWhite() == true) {
                Piece* otherKing = e.getKing(false);
                int x_king = otherKing->x();
                int y_king = otherKing->y();
                e.chess(&jb, &jn, x_king, y_king );

                if(jn.onChess == true) {

                }
            }
            else if(piece->isBlack() == true) {
                Piece* otherKing = e.getKing(true);
                int x_king = otherKing->x();
                int y_king = otherKing->y();
                e.chess(&jn, &jb, x_king, y_king);
            } else {
                cout << "Erreur "<<endl;
                exit(1);
            }
        }

        if (tourOK)
        {
            gameOver = e.gameOver();
            if (gameOver != 0)
            {
                cout << "Bravo Joueur " << (gameOver == 1 ? "Blanc":"Noir") <<", tu as gagne !"<<endl;
                exit(0);
            }

            // Le tour s'est bien pass�, joueur suivant !
            tourJb = !tourJb;
        }
        else
        {
            // Quelque chose ne s'est pas pass� correctement, le joueur corrige son tour.
            cout << "Joueur " << (tourJb ? "blanc" : "noir") << ", votre tour n'est pas valide. Recommencez"<< endl;
        }
    }

    return 0;
}
