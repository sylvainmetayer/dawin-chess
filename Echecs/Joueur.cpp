/**
 * Mise en oeuvre de Joueur.h
 *
 * @file Joueur.cpp
 */

// A besoin de la declaration de la classe
#include "Joueur.h"

Joueur::Joueur(bool white)
{
    m_white = white;
    init();
    cout<<"Joueur cree"<<endl;
}

void Joueur::init()
{
    int p = 0;

    int y = (m_white)?1:8;
    for (int x = 1; x<=8; x++)
        pieces[p++].init(x,y,m_white);

    y = (m_white)?2:7;
    for (int x = 1; x<=8; x++)
        pieces[p++].init(x,y,m_white);
}

Joueur::~Joueur()
{
    cout << "Joueur detruit"<<endl;
}

bool Joueur::isWhite()
{
    return m_white;
}

Piece Joueur::get(int x) const
{
    return pieces[x];
}

void Joueur::affiche()
{
    int limit = 16;
    for (int i = 0; i < limit; i++)
    {
        pieces[i].affiche();
    }
}
