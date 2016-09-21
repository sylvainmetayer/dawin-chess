#include <iostream>
#include "Joueur.h"
#include <assert.h>

using namespace std;

Joueur::Joueur()
{
    cout << "Construction Joueur par defaut" << endl;
}

JoueurBlanc::JoueurBlanc() : Joueur(true)
{
    cout << "Construction Joueur Blanc par defaut" << endl;
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
    cout << "Destruction Joueur" << endl;
}

void
Joueur::affiche()
{
    vector<Piece *>::iterator p = m_pieces.begin();

    while (p != m_pieces.end())
    {
        (*p)->affiche();
        p++;
    }
}

bool
JoueurBlanc::isWhite()
{
    return true;
}

bool
JoueurNoir::isWhite()
{
    return false;
}

void Joueur::placerPieces(Echiquier & e)
{
    for (int i=0; i<16; i++)
    {
        bool ok=e.placer(m_pieces[i]/*&(m_pieces[i])*/);
        assert(ok);
    }
}

