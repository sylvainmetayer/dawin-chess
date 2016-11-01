#if !defined Fou_h
#define Fou_h

#include "Piece.h"

class Echiquier;
// #include "Echiquier.h" problème de référence croisée

class Fou : virtual public Piece
{
public:
    Fou(bool white, bool left);
    bool mouvementValide(Echiquier &e, int x, int y) const;
    char myChar();
};

 #endif // Fou_h
