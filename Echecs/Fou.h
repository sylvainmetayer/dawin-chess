#if !defined Fou_h
#define Fou_h

#include "Piece.h"
#include "debug.h"
class Echiquier;

class Fou : virtual public Piece
{
public:

    /**
    * Constructeur de Fou
    * @param white Couleur de la piece
    * @param left Situ� a gauche ou non
    */
    Fou(bool white, bool left);

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

#endif // Fou_h
