#if !defined Cavalier_h
#define Cavalier_h

#include "Piece.h"

class Echiquier;
// #include "Echiquier.h" problème de référence croisée

class Cavalier : public Piece
{
public:
    Cavalier(bool white, bool left);
    bool mouvementValide(Echiquier & e, int x, int y ) const;
    char myChar();
};

 #endif // Cavalier_h
