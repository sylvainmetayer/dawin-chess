#if !defined Pion_h
#define Pion_h

#include "Piece.h"

#include "Echiquier.h"

class Pion : public Piece
{
protected:
    bool first_move;
public:
    Pion(bool white, int p);
    bool mouvementValide(Echiquier & e, int x, int y );
    char myChar();
    bool deplacementOK(Echiquier &e, int x, int y);
    bool prisePossible(Echiquier &e, int x, int y);
    char* getNomPiece();
};

#endif // !defined Pion_h
