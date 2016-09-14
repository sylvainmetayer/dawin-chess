/**
 * Header de Piece.cxx
 *
 * @file Piece.h
 */

#if !defined Piece_h
#define Piece_h

/**
 * Declaration d'une classe mod�lisant une piece de jeu d'echec.
 */
class Piece
{
private:
  int m_x;
  int m_y;
  bool m_white;

public:

  // Constructeurs
  Piece(); // d�faut
  Piece( int x, int y, bool white ); //  sp�cialis�
  Piece(const Piece & autre); //  copie

  // DESTRUCTEUR
  ~Piece(); // Destructeur

  // Op�rateurs
  Piece &operator=(const Piece & autre); // op�rateur =

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
