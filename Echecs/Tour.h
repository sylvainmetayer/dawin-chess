#if !defined Tour_h
#define Tour_h

#include "Piece.h"
#include "Echiquier.h"

class Echiquier;

class Tour : virtual public Piece
{
public:
    Tour(bool white, bool left);
    bool mouvementValide(Echiquier &e, int x, int y);
    bool deplacementOK(Echiquier &e, int x, int y);
    char myChar();
    char* getNomPiece();
};

#endif // Tour_h
