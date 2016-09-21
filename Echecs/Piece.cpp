/**
 * Mise en oeuvre de Piece.h
 *
 * @file Piece.cxx
 */

// A besoin de la declaration de la classe
#include <iostream>
#include "Piece.h"

using namespace std;

Piece::Piece()
{
    // ne fait rien => objet instancie mais non valide.
    cout << "Construction Piece par defaut" << endl;
}

Piece::~Piece()
{
    cout << "Destruction Piece" << endl;
}

Roi::Roi(bool white) : Piece(5,white ? 1:8, white)
{
    cout << "Construction Roi specialisee" << endl;
}

Fou::Fou(bool white, bool left) : Piece( left ? 3 : 6,white ? 1:8, white)
{
    cout << "Construction Fou specialisee" << endl;
}

Tour::Tour(bool white, bool left) : Piece(left ? 1 : 8,white ? 1:8, white)
{
    cout << "Construction Tour specialisee" << endl;
}

Reine::Reine(bool white) : Piece(4, (white?1:8), white ),
                Fou(white, true), Tour(white, true)
{
    m_white = white;
    cout << "Construction Reine specialisee" << endl;
}

Piece::Piece( int x, int y, bool white )
{
    m_x = x;
    m_y = y;
    m_white = white;
    cout << "Construction Piece specialisee" << endl;
}

Piece::Piece( const Piece & autre)
{
    m_x = autre.m_x;
    m_y = autre.m_y;
    m_white = autre.m_white;
    cout << "Construction Piece par copie" << endl;
}

Piece &
Piece::operator=( const Piece & autre)
{
    m_x = autre.m_x;
    m_y = autre.m_y;
    m_white = autre.m_white;
    cout << "Affectation Piece" << endl;
    return *this;
}

void
Piece::init( int x, int y, bool white )
{
    m_x = x;
    m_y = y;
    m_white = white;
}

void
Piece::move( int x, int y )
{
    m_x = x;
    m_y = y;
}

int
Piece::x() const
{
    return m_x;
}

int
Piece::y() const
{
    return m_y;
}

bool
Piece::isWhite() const
{
    return m_white;
}

bool
Piece::isBlack() const
{
    return !m_white;
}

void
Piece::affiche() const
{
    cout << "Piece: x=" << m_x << " y=" << m_y << " "
         << ( m_white ? "blanche" : "noire" ) << endl;
}

const Piece &
Piece::plusforte(const Piece & autre) const
{
    /* FAUX !!!
    Piece tmp;
    if (true)
      tmp=autre;
    else
      tmp=*this;
    return tmp;
    */
    if (true)
        return autre;
    else
        return *this;
}

bool Piece::mouvementValide(Echiquier &e, int x, int y) const
{
    cout <<"Mouvement valide"<<endl;
    return false;
}

char Piece::myChar()
{
    return m_white ? 'B' : 'N';
}


bool Roi::mouvementValide(Echiquier &e, int x, int y) const
{
    cout <<"Mouvement valide"<<endl;
    return false;
}

char Roi::myChar()
{
    return m_white ? 'R' : 'r';
}

void Roi::roque(bool left)
{
    cout <<"roque de" << (left ? "gauche":"droit")<< " de Roi"<<endl;
}

bool Reine::mouvementValide(Echiquier &e, int x, int y) const
{
    return Fou::mouvementValide(e,x,y) || Tour::mouvementValide(e,x,y);
}

char Reine::myChar()
{
    return m_white ? 'Q' : 'q';
}

bool Tour::mouvementValide(Echiquier &e, int x, int y) const
{
    cout <<"Mouvement valide"<<endl;
    return false;
}

char Tour::myChar()
{
    return m_white ? 'T' : 't';
}

bool Fou::mouvementValide(Echiquier &e, int x, int y) const
{
    cout <<"Mouvement valide"<<endl;
    return false;
}

char Fou::myChar()
{
    return m_white ? 'F' : 'f';
}
