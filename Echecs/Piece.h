/**
 * Header de Piece.cxx
 *
 * @file Piece.h
 */

#if !defined Piece_h
#define Piece_h

#include <iostream>
using namespace std;

/**
 * Declaration d'une classe modélisant une piece de jeu d'echec.
 */
class Piece
{
private:
    int m_x;
    int m_y;
    bool m_white;

public:
    Piece();
    ~Piece();
    Piece(int x, int y, bool white);
    void init( int x, int y, bool white );
    void move( int x, int y );
    int x() const;
    int y() const;
    bool isWhite();
    bool isBlack();
    void affiche();
    Piece piecePlusForte(const Piece &p) const;
};

#endif // !defined Piece_h
