#if !defined Roi_h
#define Roi_h

#include "Piece.h"

class Echiquier;
// #include "Echiquier.h" problème de référence croisée

class Roi : public Piece
{
public:
    Roi(bool white);
    bool mouvementValide(Echiquier &e, int x, int y) const;
    char myChar();
    void roque(bool left);
};

#endif // !defined Piece_h
