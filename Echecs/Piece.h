/**
 * Header de Piece.cxx
 *
 * @file Piece.h
 */

#if !defined Piece_h
#define Piece_h

/**
 * Declaration d'une classe modélisant une piece de jeu d'echec.
 */
class Piece
{
private:
  int m_x;
  int m_y;
  bool m_white;

public:

  // Constructeurs
  Piece(); // défaut
  Piece( int x, int y, bool white ); //  spécialisé
  Piece(const Piece & autre); //  copie

  // DESTRUCTEUR
  ~Piece(); // Destructeur

  // Opérateurs
  Piece &operator=(const Piece & autre); // opérateur =

  // FONCTIONS
  void init( int x, int y, bool white );
  void move( int x, int y );
  int x() const;
  int y() const;
  bool isWhite() const;
  bool isBlack() const;
  void affiche() const;

  Piece plusforte(const Piece & p) const;
};

#endif // !defined Piece_h
