/**
 * Mise en oeuvre de Echiquier.h
 *
 * @file Echiquier.cxx
 */

#include <iostream>
#include <cstring>
#include "Echiquier.h"

#include "Joueur.h"

using namespace std;

/**
 * Constructeur par d�faut.
 * Initialise � vide l'echiquier.
 */
Echiquier::Echiquier()
{
    for (int i=0; i<64; i++)
        m_cases[i]=NULL;
}

/**
 * Recupere la piece situee sur une case.
 *
 * @param x un entier entre 1 et 8
 * @param y un entier entre 1 et 8
 *
 * @return 0 si aucune piece n'est sur cette case et un pointeur
 * vers une piece sinon.
 */
Piece*
Echiquier::getPiece( int x, int y )
{
    if ((x<9 && x>0 && y<9 && y>0) == false)
    {
        return NULL;
    }
    return m_cases[(x-1)+8*(y-1)];
}


/**
 * Place une piece sur l'echiquier, aux coordonnees specifiees dans la piece.
 *
 * @param p un pointeur vers une piece
 *
 * @return 'true' si le placement s'est bien passe, 'false' sinon
 * (case occupee, coordonnees invalides, piece vide )
 */
bool
Echiquier::placer( Piece* p )
{
    if ((p->x()<9 && p->x()>0 && p->y()<9 && p->y()>0) == false)
    {
        return false;
    }

    if (Echiquier::getPiece(p->x(),p->y())==NULL && p!=NULL)
    {
        m_cases[(p->x()-1)+8*((*p).y()-1)]=p;
        return true;
    }
    else
        return false;
}

/**
 * Deplace une piece sur l'echiquier, des coordonnees specifiees
 * dans la piece aux coordonnees x,y.
 *
 * @param p un pointeur vers une piece
 * @param x un entier entre 1 et 8
 * @param y un entier entre 1 et 8
 *
 * @return 'true' si le placement s'est bien passe, 'false' sinon
 * (case occupee, coordonnees invalides, piece vide, piece pas
 * presente au bon endroit sur l'echiquier)
 */
bool Echiquier::deplacer( Piece* p, int x, int y )
{

    if (!this->caseLibre(*p, x,y))
    {
        return false;
    }

    if (!p->mouvementValide(*this,x,y))
    {
        if (DEBUG)
            cout << "MouvementValide Fail"<< endl;
        return false;
    }

    if (!p->deplacementOK(*this, x,y))
    {
        if (DEBUG)
            cout << "DeplacementOK Fail"<<endl;
        return false;
    }

    if (!this->prise(p, x,y))
    {
        if (DEBUG)
            cout << "Prise Fail" << endl;
        return false;
    }

    Piece * deplacement = this->enleverPiece(p->x(), p->y());
    if (deplacement != 0)
    {
        deplacement->move(x,y);
        this->placer(deplacement);
    }

    return true;
}

/**
 * Enleve la piece situee sur une case (qui devient vide).
 *
 * @param x un entier entre 1 et 8
 * @param y un entier entre 1 et 8
 *
 * @return 0 si aucune piece n'est sur cette case et le pointeur
 * vers la piece enlevee sinon.
 */
Piece* Echiquier::enleverPiece( int x, int y )
{
    Piece *tmp;
    tmp = m_cases[(x-1)+8*(y-1)];
    m_cases[(x-1)+8*(y-1)] = NULL;
    return tmp;
}

/**
 * Affiche l'echiquier avec des # pour les cases noires et . pour
 * les blanches si elles sont vides, et avec B pour les pieces
 * blanches et N pour les pieces noires.
 */
void Echiquier::affiche()
{
    cout << endl << "  12345678" << endl;
    for ( int y = 1; y <= 8; ++y )
    {
        cout << y << " ";
        for ( int x = 1; x <= 8; ++x )
        {
            char c;
            Piece* p = getPiece( x, y );
            if ( p == 0 )
                c = ( ( x + y ) % 2 ) == 0 ? '#' : '.';
            else
                c = p->myChar();
            cout << c;
        }
        cout << " " << y << endl;
    }
    cout << "  12345678" << endl;
}

/**
* Permet de savoir si la pi�ce peux �tre
* prise ou non par une autre piece
* @param p : la piece qui se d�place
* @param x : coordonn�es x de d�placement
* @param y : coordonn�es y de d�placement
*
* @return true si la prise est possible, false sinon.
**/
bool Echiquier::caseLibre(Piece &p, int x, int y)
{
    if (DEBUG)
        cout << "Case Libre : ";
    Piece* p1 = getPiece(x, y);

    if(p1 == 0)
    {
        if (DEBUG)
            cout << "Aucune piece sur cette case" << endl;
        return true;
    }
    if(p1->isWhite()==true && p.isWhite()==true)
    {
        cout << "Ceci est une de vos pieces ! Attention !" << endl;
        return false;
    }
    else
    {
        if (DEBUG)
            cout << "Piece adverse, prise possible" << endl;
        return true;
    }
}

/**
 * Permet la prise d'une piece par une autre,
 * la supprimant ainsi du plateau
 * @param eater : La piece qui se deplace
 * @param x le x de destination
 * @param y le y de destination
 * @return false si la piece que l'on tente de retirer
 * est de la meme couleur que la piece qui se deplace,
 * true aucune piece n'a ete supprimee ou si
 * la suppression de piece s'est correctement deroulee
 */
bool Echiquier::prise(Piece *eater, int x, int y)
{

    Piece* eatMe = getPiece(x, y);
    if(eatMe != 0)
    {
        eatMe = enleverPiece(x,y);
        if (eatMe != 0)
        {
            if (eatMe->isBlack() == eater->isBlack())
            {
                cout << "Vous ne pouvez pas prendre une piece de votre couleur !"<<endl;
                return false;
            }
            cout << "La piece decrite ci-dessous a ete supprimee."<<endl;
            eatMe->affiche();
            return true;
        }
    }
    if (DEBUG)
        cout << "Aucune piece n'a ete supprimee" << endl;
    return true;
}

/**
* Retourne le roi du joueur donn�
*@param white : true si on veut le roi blanc, false sinon.
*@return pointeur sur le roi demand�, 0 sinon.
*/
Piece* Echiquier::getKing(bool white)
{
    Piece* tmp;
    for (int i = 1; i<=8; i++)
    {
        for (int j = 1; j<=8; j++)
        {
            tmp = this->getPiece(i,j);

            if (tmp != 0 && strcmp("Roi", tmp->getNomPiece()) == 0)
            {
                if (white == true && tmp->isWhite())
                    return tmp;

                if (white == false && tmp->isBlack())
                    return tmp;
            }

        }
    }
    return 0;
}

/**
* Cette fonction permet de savoir si le joueur du tour suivant sera en echec ou non
* x et y correspondent � la position du roi du joueur du tour suivant.
*
* @param x : coordonn�es x du roi adverse.
* @param y : coordonn�es y du roi adverse
* @param duTour : joueur actuel.
* @param tourSuivant : Joueur suivant.
* @return true si le joueur tourSuivant est en echec, false sinon.
*
*/
bool Echiquier::chess(Joueur& duTour, Joueur& tourSuivant, int x, int y)
{
    bool isOnChess;

    int limite = duTour.getPieces().size();
    for(int i=0; i< limite; ++i)
    {
        Piece* p = duTour.getPieces()[i];

        if( p->mouvementValide(*this, x, y) ==  true && p->deplacementOK(*this, x, y) == true)
        {
            tourSuivant.setOnChess(true);
            isOnChess = true;
            break;

        }
        else
        {
            tourSuivant.setOnChess(false);
            isOnChess = false;
        }
    }

    return isOnChess;
}

/**
* Cette fonction permet de savoir si un joueur est echec et mat.
* @param joueur le joueur que l'on souhaite v�rifier.
* @return true ou false selon que le joueur est echec ou mat.
*/
bool Echiquier::checkChessMat(Joueur& joueur)
{
    if (joueur.getChessMat() == true && joueur.getOnChess() == true)
    {
        cout << "Le joueur  " << (joueur.isWhite() ? "Blanc" : "Noir") << " est echec et mat et a perdu." << endl;
        return true;
    }

    return false;
}
