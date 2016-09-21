/**
 * Header de Piece.cxx
 *
 * @file Piece.h
 */

#if !defined Piece_h
#define Piece_h

class Echiquier;
// #include "Echiquier.h" problème de référence croisée

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
    void init( int x, int y, bool white );
    void move( int x, int y );
    int x() const;
    int y() const;
    bool isWhite() const;
    bool isBlack() const;
    void affiche() const;
    const Piece & plusforte(const Piece & autre) const;
    virtual bool mouvementValide(Echiquier &e, int x, int y) const;
    virtual char myChar();
};

class Roi : public Piece
{
    public:
        Roi(bool white);
        bool mouvementValide(Echiquier &e, int x, int y) const;
        char myChar();
        void roque(bool left);
};


class Tour : virtual public Piece
{
    public:
        Tour(bool white, bool left);
        bool mouvementValide(Echiquier &e, int x, int y) const;
        char myChar();
};

class Fou : virtual public Piece
{
    public:
        Fou(bool white, bool left);
        bool mouvementValide(Echiquier &e, int x, int y) const;
        char myChar();
};

class Reine : public Fou, public Tour
{
    public:
        Reine(bool white);
        bool mouvementValide(Echiquier &e, int x, int y) const;
        char myChar();
};


class Cavalier : public Piece
{
 public:
  Cavalier(bool white, bool left);
  bool mouvementValide(Echiquier & e, int x, int y );
  char myChar();
};

class Pion : public Piece
{
 public:
  Pion(bool white, int p);
  bool mouvementValide(Echiquier & e, int x, int y );
  char myChar();
};


#endif // !defined Piece_h
