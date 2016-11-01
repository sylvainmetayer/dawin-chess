#if !defined Tour_h
#define Tour_h

#include "Piece.h"

class Echiquier;
// #include "Echiquier.h" problème de référence croisée

class Tour : virtual public Piece
{
public:
    Tour(bool white, bool left);
    bool mouvementValide(Echiquier &e, int x, int y);
    char myChar();
};

#endif // Tour_h
