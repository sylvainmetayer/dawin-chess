#if !defined Roi_h
#define Roi_h

#include "Piece.h"
class Echiquier;
#include "debug.h"

class Roi : public Piece
{
public:
    Roi(bool white);
    bool mouvementValide(Echiquier &e, int x, int y);
    char myChar();
    void roque(bool left);
    bool deplacementOK(Echiquier &e, int x, int y);
    char* getNomPiece();
};

#endif // !defined Piece_h
