#ifndef JOUEURBLANC_H_INCLUDED
#define JOUEURBLANC_H_INCLUDED

#include "Joueur.h"
#include <iostream>
#include "debug.h"

class JoueurBlanc : public Joueur
{
    public:
        JoueurBlanc();
        bool isWhite();
};

#endif // JOUEURBLANC_H_INCLUDED
