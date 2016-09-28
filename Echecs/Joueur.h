/**
 * Header de Joueur.cxx
 *
 * @file Joueur.h
 */

#if !defined Joueur_h
#define Joueur_h

#include "Piece.h"
#include "Echiquier.h"
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
        virtual void jouer(Echiquier &e, int x, int y)=0;
};

class JoueurNoir : public Joueur
{
    public:
        JoueurNoir();
        bool isWhite();
        void jouer(Echiquier &e, int x, int y);
};

#endif
