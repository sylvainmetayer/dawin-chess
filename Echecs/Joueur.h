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
};

class JoueurBlanc : public Joueur
{
public:
    JoueurBlanc();
    bool isWhite();
};

class JoueurNoir : public Joueur
{
public:
    JoueurNoir();
    bool isWhite();
};

#endif
