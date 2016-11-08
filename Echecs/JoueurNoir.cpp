#include <iostream>
#include "JoueurNoir.h"
#include <assert.h>

#include "Roi.h"
#include "Reine.h"
#include "Tour.h"
#include "Fou.h"
#include "Cavalier.h"
#include "Pion.h"

using namespace std;

JoueurNoir::JoueurNoir() : Joueur(false)
{
    //cout << "Construction Joueur Noir par defaut" << endl;
}


bool JoueurNoir::isWhite()
{
    return false;
}

void Joueur::placerPieces(Echiquier &e)
{
    for (int i=0; i<16; i++)
    {
        bool ok=e.placer(m_pieces[i]);
        assert(ok);
    }
}
