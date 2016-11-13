#if !defined Pion_h
#define Pion_h

#include "Piece.h"
#include "debug.h"
#include "Echiquier.h"

class Pion : public Piece
{
protected:
    bool first_move;
public:
    Pion(bool white, int p);

    /**
    * Permet de savoir si le mouvement de la piece est autorisé, par rapport au contrainte de la piece elle meme
    * @param e : l'échiquier
    * @param x la coordonnées x de destination
    * @param y la coordonnées y de destination
    * @return true ou false selon que le mouvement est valide ou non.
    */
    bool mouvementValide(Echiquier & e, int x, int y );

    /**
    * Permet de représenter la piece sur le plateau.
    * @return Le charactere correspondant à la piece
    */
    char myChar();

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
    * Permet de savoir si un pion peut prendre une piece à une position donnée.
    * @param x : la position a tester
    * @param y : la position à tester
    * @param e : L'échiquier
    *
    * @return true ou false selon que la prise d'une piece est possible ou non.
    */
    bool prisePossible(Echiquier &e, int x, int y);

    /**
    * Permet de savoir le nom de la piece
    * @return le nom de la piece
    */
    char* getNomPiece();
};

#endif // !defined Pion_h
