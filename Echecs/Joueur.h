/**
 * Header de Joueur.cxx
 *
 * @file Joueur.h
 */

#if !defined Joueur_h
#define Joueur_h

#include "Echiquier.h"
#include "Piece.h"
#include "Roi.h"
#include "Reine.h"
#include "Tour.h"
#include "Fou.h"
#include "Cavalier.h"
#include "Pion.h"

#include <vector>

using namespace std;

class Joueur
{
    protected:
        //Piece m_pieces[16];
        vector<Piece *> m_pieces;
    public:
        Joueur();
        ~Joueur();
        Joueur(bool white);
        void affiche();
        virtual bool isWhite()=0;
        void placerPieces(Echiquier &e);
};

#endif
