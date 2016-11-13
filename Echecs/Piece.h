/**
 * Header de Piece.cxx
 *
 * @file Piece.h
 */

#if !defined Piece_h
#define Piece_h

#include "debug.h"
class Echiquier;

/**
 * Declaration d'une classe mod�lisant une piece de jeu d'echec.
 */
class Piece
{
protected:
    int m_x;
    int m_y;
    bool m_white;

public:
    Piece();
    ~Piece();
    Piece( int x, int y, bool white );
    Piece(const Piece & autre);
    Piece & operator=(const Piece & autre);

    /**
    * Permet de modifier les coordonn�es de la piece.
    * @param x : nouvelle coordonn�e x
    * @param y : nouvelle coordonn�e y
    */
    void move( int x, int y );

    /**
    * Permet l'affichage des caract�ristiques de la pi�ce.
    * telle que son nom, et ses coordonn�es
    */
    void affiche();

    /**
    * Permet de savoir si le mouvement de la piece est autoris�, par rapport au contrainte de la piece elle meme
    * @param e : l'�chiquier
    * @param x la coordonn�es x de destination
    * @param y la coordonn�es y de destination
    * @return true ou false selon que le mouvement est valide ou non.
    */
    virtual bool mouvementValide(Echiquier &e, int x, int y);

    /**
    * Permet de repr�senter la piece sur le plateau.
    * @return Le charactere correspondant � la piece
    */
    virtual char myChar();

    /**
    * Permet de valider ou non le d�placement avant de l'effectuer, en tenant compte des
    * autres pieces pr�sentes sur l'�chiquier
    * @param e : l'�chiquier
    * @param x la coordonn�es x de destination
    * @param y la coordonn�es y de destination
    * @return true ou false selon que le d�placement est valide ou non.
    */
    virtual bool deplacementOK(Echiquier &e, int x, int y);

    /**
    * Permet de savoir le nom de la piece
    * @return le nom de la piece
    */
    virtual char* getNomPiece();

    // Getter / Setter
    int x() const;
    int y() const;
    bool isWhite() const;
    bool isBlack() const;
};

#endif // !defined Piece_h
