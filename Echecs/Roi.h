#if !defined Roi_h
#define Roi_h

#include "Piece.h"

//#include "Echiquier.h"
class Echiquier;
// #include "Echiquier.h" problème de référence croisée

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
