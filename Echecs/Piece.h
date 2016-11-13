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
 * Declaration d'une classe modélisant une piece de jeu d'echec.
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
    * Permet de modifier les coordonnées de la piece.
    * @param x : nouvelle coordonnée x
    * @param y : nouvelle coordonnée y
    */
    void move( int x, int y );

    /**
    * Permet l'affichage des caractéristiques de la pièce.
    * telle que son nom, et ses coordonnées
    */
    void affiche();

    /**
    * Permet de savoir si le mouvement de la piece est autorisé, par rapport au contrainte de la piece elle meme
    * @param e : l'échiquier
    * @param x la coordonnées x de destination
    * @param y la coordonnées y de destination
    * @return true ou false selon que le mouvement est valide ou non.
    */
    virtual bool mouvementValide(Echiquier &e, int x, int y);

    /**
    * Permet de représenter la piece sur le plateau.
    * @return Le charactere correspondant à la piece
    */
    virtual char myChar();

    /**
    * Permet de valider ou non le déplacement avant de l'effectuer, en tenant compte des
    * autres pieces présentes sur l'échiquier
    * @param e : l'échiquier
    * @param x la coordonnées x de destination
    * @param y la coordonnées y de destination
    * @return true ou false selon que le déplacement est valide ou non.
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
