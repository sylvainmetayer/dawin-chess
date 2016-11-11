#if !defined Reine_h
#define Reine_h

#include "Piece.h"
#include "Fou.h"
#include "Tour.h"
#include "Echiquier.h"

//class Echiquier;
// #include "Echiquier.h" problème de référence croisée

class Reine : public Fou, public Tour
{
public:
    Reine(bool white);
    bool mouvementValide(Echiquier &e, int x, int y);
    bool deplacementOK(Echiquier &e, int x, int y);
    char myChar();
    char* getNomPiece();
};

#endif // Defined Reine_h
