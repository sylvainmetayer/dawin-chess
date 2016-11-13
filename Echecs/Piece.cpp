/**
 * Mise en oeuvre de Piece.h
 *
 * @file Piece.cxx
 */

#include <iostream>
#include "Piece.h"

using namespace std;

Piece::Piece() {}

Piece::~Piece()
{
    if (DEBUG)
        cout << "Destruction Piece" << endl;
}

Piece::Piece( int x, int y, bool white )
{
    m_x = x;
    m_y = y;
    m_white = white;
}

Piece::Piece( const Piece & autre)
{
    m_x = autre.m_x;
    m_y = autre.m_y;
    m_white = autre.m_white;
}

Piece & Piece::operator=( const Piece & autre)
{
    m_x = autre.m_x;
    m_y = autre.m_y;
    m_white = autre.m_white;
    return *this;
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

void Piece::affiche()
{
    cout << this->getNomPiece() <<  ": x=" << m_x << " y=" << m_y << " "
         << ( m_white ? "blanche" : "noire" ) << endl;
}

bool Piece::mouvementValide(Echiquier &e, int x, int y)
{
    cout <<"Piece mouvement valide non specialise "<<endl;
    return false;
}

bool Piece::deplacementOK(Echiquier &e, int x, int y)
{
    cout << "Deplacement OK non specialise"<<endl;
    return false;
}

char Piece::myChar()
{
    return m_white ? 'B' : 'N';
}

char* Piece::getNomPiece()
{
    return "Piece non specialisee";
}
