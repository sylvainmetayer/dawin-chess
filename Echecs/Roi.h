#if !defined Roi_h
#define Roi_h

#include "Piece.h"
class Echiquier;
#include "debug.h"

class Roi : public Piece
{
public:
    Roi(bool white);

    /**
    * Permet de savoir si le mouvement de la piece est autoris�, par rapport au contrainte de la piece elle meme
    * @param e : l'�chiquier
    * @param x la coordonn�es x de destination
    * @param y la coordonn�es y de destination
    * @return true ou false selon que le mouvement est valide ou non.
    */
    bool mouvementValide(Echiquier &e, int x, int y);

    /**
    * Permet de repr�senter la piece sur le plateau.
    * @return Le charactere correspondant � la piece
    */
    char myChar();

    void roque(bool left);

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
    * Permet de savoir le nom de la piece
    * @return le nom de la piece
    */
    char* getNomPiece();
};

#endif // !defined Piece_h
