#ifndef JOUEURBLANC_H_INCLUDED
#define JOUEURBLANC_H_INCLUDED

#include "Joueur.h"
#include <iostream>

class JoueurBlanc : public Joueur
{
    public:
        JoueurBlanc();
        bool isWhite();
        bool jouer(Piece *piece,Echiquier &e, int x, int y);
};

#endif // JOUEURBLANC_H_INCLUDED
