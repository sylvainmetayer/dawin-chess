#if !defined Reine_h
#define Reine_h

#include "Piece.h"
#include "Fou.h"
#include "Tour.h"
#include "Echiquier.h"
#include "debug.h"

class Reine : public Fou, public Tour
{
public:
    Reine(bool white);

    /**
    * Permet de savoir si le mouvement de la piece est autorisé, par rapport au contrainte de la piece elle meme
    * @param e : l'échiquier
    * @param x la coordonnées x de destination
    * @param y la coordonnées y de destination
    * @return true ou false selon que le mouvement est valide ou non.
    */
    bool mouvementValide(Echiquier &e, int x, int y);

    /**
    * Permet de valider ou non le déplacement avant de l'effectuer, en tenant compte des
    * autres pieces présentes sur l'échiquier
    * @param e : l'échiquier
    * @param x la coordonnées x de destination
    * @param y la coordonnées y de destination
    * @return true ou false selon que le déplacement est valide ou non.
    */
    bool deplacementOK(Echiquier &e, int x, int y);

    /**
    * Permet de représenter la piece sur le plateau.
    * @return Le charactere correspondant à la piece
    */
    char myChar();

    /**
    * Permet de savoir le nom de la piece
    * @return le nom de la piece
    */
    char* getNomPiece();
};

#endif // Defined Reine_h
