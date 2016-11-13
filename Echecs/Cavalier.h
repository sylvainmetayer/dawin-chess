#if !defined Cavalier_h
#define Cavalier_h

#include "Piece.h"
#include "debug.h"
class Echiquier;
// #include "Echiquier.h" problème de référence croisée

class Cavalier : public Piece
{
public:
    Cavalier(bool white, bool left);
    bool mouvementValide(Echiquier & e, int x, int y );
    bool deplacementOK(Echiquier &e, int x, int y);
    char myChar();
    char* getNomPiece();
};

 #endif // Cavalier_h
