#if !defined Fou_h
#define Fou_h

#include "Piece.h"
class Echiquier;

class Fou : virtual public Piece
{
public:
    Fou(bool white, bool left);
    bool mouvementValide(Echiquier &e, int x, int y);
    bool deplacementOK(Echiquier &e, int x, int y);
    char myChar();
    char* getNomPiece();
};

 #endif // Fou_h
