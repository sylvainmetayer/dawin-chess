#if !defined Pion_h
#define Pion_h

#include "Piece.h"

class Echiquier;
// #include "Echiquier.h" problème de référence croisée

class Pion : public Piece
{
protected:
    bool first_move;
public:
    Pion(bool white, int p);
    bool mouvementValide(Echiquier & e, int x, int y );
    char myChar();
};

#endif // !defined Pion_h
