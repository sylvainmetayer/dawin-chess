#if !defined Cavalier_h
#define Cavalier_h

#include "Piece.h"
#include "debug.h"
class Echiquier;
// #include "Echiquier.h" problème de référence croisée

class Cavalier : public Piece
{
public:
    /**
    * Constructeur de Cavalier
    * @param white Couleur du cavalier
    * @param left Situé a gauche ou non
    */
    Cavalier(bool white, bool left);

    /**
    * Permet de savoir si le mouvement de la piece est autorisé, par rapport au contrainte de la piece elle meme
    * @param e : l'échiquier
    * @param x la coordonnées x de destination
    * @param y la coordonnées y de destination
    * @return true ou false selon que le mouvement est valide ou non.
    */
    bool mouvementValide(Echiquier & e, int x, int y );

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

 #endif // Cavalier_h
