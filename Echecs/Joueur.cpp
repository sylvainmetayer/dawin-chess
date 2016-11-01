#include <iostream>
#include "Joueur.h"
#include <assert.h>

#include "Roi.h"
#include "Reine.h"
#include "Tour.h"
#include "Fou.h"
#include "Cavalier.h"
#include "Pion.h"

using namespace std;

Joueur::Joueur()
{
    cout << "Construction Joueur par defaut" << endl;
}


JoueurNoir::JoueurNoir() : Joueur(false)
{
    cout << "Construction Joueur Noir par defaut" << endl;
}

Joueur::Joueur(bool white)
{
    cout << "constructeur specialise joueur" <<endl;

    Roi *r = new Roi(white);
    m_pieces.push_back(r);

    // De même pour les pions, reine, cavalier, ...
    Reine *q = new Reine(white);
    m_pieces.push_back(q);

    Tour *tg = new Tour(white, true);
    m_pieces.push_back(tg);

    Tour *td = new Tour(white, false);
    m_pieces.push_back(td);

    Cavalier *cd = new Cavalier(white, false);
    m_pieces.push_back(cd);

    Cavalier *cg = new Cavalier(white, true);
    m_pieces.push_back(cg);

    Fou *fg = new Fou(white, true);
    m_pieces.push_back(fg);
    Fou *fd = new Fou (white, false);
    m_pieces.push_back(fd);

    Pion *p;
    for (int i=1; i<=8; i++)
    {
        p = new Pion(white, i);
        m_pieces.push_back(p);
    }
}

Joueur::~Joueur()
{
    // TODO penser à gérer les delete
    cout << "Destruction Joueur" << endl;
}

void Joueur::affiche()
{
    vector<Piece *>::iterator p = m_pieces.begin();

    while (p != m_pieces.end())
    {
        (*p)->affiche();
        p++;
    }
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


void JoueurNoir::jouer(Echiquier &e, int x, int y)
{

}
