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
    * Permet de savoir si le mouvement de la piece est autoris�, par rapport au contrainte de la piece elle meme
    * @param e : l'�chiquier
    * @param x la coordonn�es x de destination
    * @param y la coordonn�es y de destination
    * @return true ou false selon que le mouvement est valide ou non.
    */
    bool mouvementValide(Echiquier & e, int x, int y );

    /**
    * Permet de repr�senter la piece sur le plateau.
    * @return Le charactere correspondant � la piece
    */
    char myChar();

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
    * Permet de savoir si un pion peut prendre une piece � une position donn�e.
    * @param x : la position a tester
    * @param y : la position � tester
    * @param e : L'�chiquier
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
