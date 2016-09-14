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
    cout << "Construction Piece par defaut" << endl;
}

Piece::~Piece()
{
    cout << "Destruction Piece" << endl;
}

Piece::Piece( int x, int y, bool white )
{
    m_x = x;
    m_y = y;
    m_white = white;
    cout << "Construction Piece specialisee" << endl;
}

Piece::Piece(const Piece & autre)
{
    m_x = autre.x();
    m_y = autre.y();
    m_white = autre.isWhite();
    cout << "Constructeur par copie"<<endl;
}

Piece& Piece::operator=(const Piece & autre)
{
    m_x = autre.x();
    m_y = autre.y();
    m_white = autre.isWhite();
    cout << "Affectation piece" << endl;
    return *this;
}

void Piece::init( int x, int y, bool white )
{
    m_x = x;
    m_y = y;
    m_white = white;
}

void Piece::move( int x, int y )
{
    m_x = x;
    m_y = y;
}

int Piece::x() const
{
    return m_x;
}

int Piece::y() const
{
    return m_y;
}

bool Piece::isWhite() const
{
    return m_white;
}

bool Piece::isBlack() const
{
    return !m_white;
}

void Piece::affiche() const
{
    cout << "Piece: x=" << m_x << " y=" << m_y << " "
         << ( m_white ? "blanche" : "noire" ) << endl;
}

Piece Piece::plusforte(const Piece &p) const
{
    if (true)
    {
        return p;
    }
    else
    {
        return *this;
    }
}
