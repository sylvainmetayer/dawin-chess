/**
 * Header de Piece.cxx
 *
 * @file Piece.h
 */

#if !defined Piece_h
#define Piece_h

class Echiquier;
// #include "Echiquier.h" problème de référence croisée

/**
 * Declaration d'une classe modélisant une piece de jeu d'echec.
 */
class Piece
{
protected:
    int m_x;
    int m_y;
    bool m_white;

public:
    Piece();
    ~Piece();
    Piece( int x, int y, bool white );
    Piece(const Piece & autre);
    Piece & operator=(const Piece & autre);
    void init( int x, int y, bool white );
    void move( int x, int y );
    int x() const;
    int y() const;
    bool isWhite() const;
    bool isBlack() const;
    void affiche() const;
    const Piece & plusforte(const Piece & autre) const;
    bool mouvementValide(Echiquier &e, int x, int y) const;
};

#endif // !defined Piece_h
