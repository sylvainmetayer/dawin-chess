#include <iostream>

#include "Joueur.h"

using namespace std;

Joueur::Joueur() {}

Joueur::Joueur(bool white)
{
    this->setOnChess(false);
    this->setChessMat(false);

    Roi *r = new Roi(white);
    m_pieces.push_back(r);

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
    if (DEBUG)
        cout << "Destruction Joueur" << endl;
}


void Joueur::placerPieces(Echiquier &e)
{
    for (int i=0; i<16; i++)
    {
        e.placer(m_pieces[i]);
    }
}

bool Joueur::getOnChess()
{
    return this->onChess;
}

bool Joueur::getChessMat()
{
    return this->chessMat;
}

void Joueur::setChessMat(bool chessMat)
{
    this->chessMat = chessMat;
}

void Joueur::setOnChess(bool onChess)
{
    this->onChess = onChess;
}

vector<Piece*> Joueur::getPieces()
{
    return this->m_pieces;
}

