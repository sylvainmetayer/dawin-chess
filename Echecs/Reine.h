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
    * Permet de savoir si le mouvement de la piece est autoris�, par rapport au contrainte de la piece elle meme
    * @param e : l'�chiquier
    * @param x la coordonn�es x de destination
    * @param y la coordonn�es y de destination
    * @return true ou false selon que le mouvement est valide ou non.
    */
    bool mouvementValide(Echiquier &e, int x, int y);

    /**
    * Permet de valider ou non le d�placement avant de l'effectuer, en tenant compte des
    * autres pieces pr�sentes sur l'�chiquier
    * @param e : l'�chiquier
    * @param x la coordonn�es x de destination
    * @param y la coordonn�es y de destination
    * @return true ou false selon que le d�placement est valide ou non.
    */
    bool deplacementOK(Echiquier &e, int x, int y);

    /**
    * Permet de repr�senter la piece sur le plateau.
    * @return Le charactere correspondant � la piece
    */
    char myChar();

    /**
    * Permet de savoir le nom de la piece
    * @return le nom de la piece
    */
    char* getNomPiece();
};

#endif // Defined Reine_h
