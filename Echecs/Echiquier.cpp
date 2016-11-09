/**
 * Mise en oeuvre de Echiquier.h
 *
 * @file Echiquier.cxx
 */

#include <iostream>
#include <assert.h>

// A besoin de la declaration de la classe
#include "Echiquier.h"

using namespace std;

/**
 * Constructeur par défaut.
 * Initialise à vide l'echiquier.
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
    if ((x<9 && x>0 && y<9 && y>0) == false) {
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
    assert(p->x()<9 && p->x()>0 && p->y()<9 && p->y()>0);
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
bool
Echiquier::deplacer( Piece* p, int x, int y )
{

    if (!p->mouvementValide(*this,x,y)) {
            cout << "Ce mouvement n'est pas valide pour cette piece."<< endl;
            return false;
    }

    if (!this->caseLibre(*p, x,y)) {
        return false;
    }

    if (!p->deplacementOK(*this, x,y)) {
        return false;
    }

    // Missing : est-ce que j'ai une piece sur mon trajet ?

    // Gestion de la suppression des pièces sur le passage TODO

    // Dernière étape : On déplace la pièce.
    Piece * deplacement = this->enleverPiece(p->x(), p->y());
    if (deplacement != 0) {
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
Piece*
Echiquier::enleverPiece( int x, int y )
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
void
Echiquier::affiche()
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
                c = p->myChar();//p->isWhite() ? 'B' : 'N';
            cout << c;
        }
        cout << " " << y << endl;
    }
    cout << "  12345678" << endl;
}

/**
* Permet de savoir si la pièce peux être
* prise ou non par une autre piece
**/
bool
Echiquier::caseLibre(Piece &p, int x, int y) {

    cout << "Case Libre : ";
    // Récupération de la pièce à la position données
    Piece* p1 = getPiece(x, y);

    if(p1 == 0) {
            cout << "Aucune piece sur cette case" << endl;
        return true;
    }
    if(p1->isWhite()==true && p.isWhite()==true) {
        cout << "Ceci est une de vos pieces ! Attention !" << endl;
        return false;
    }
    else {
        cout << "Piece adverse, prise possible" << endl;
        return true;
    }
}

/**
 * Permet la prise d'une piece par une autre,
 * la supprimant ainsi du plateau
 */
//bool
//Echiquier::prise(Piece &p, int x, int y) {
//
//    bool priseOK = false;
//
//    Piece* p1 = getPiece(x, y);
//    if(getPiece(x, y) != 0) {
//        enleverPiece(x,y);
//        cout << "La piece en (" << x << "," << y<< ") a ete supprime" << endl;
//        priseOK = true;
//    }
//
//    return priseOK;
//}
