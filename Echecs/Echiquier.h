/**
 * Header de Echiquier.cxx
 *
 * @file Echiquier.h
 */

#if !defined Echiquier_h
#define Echiquier_h

#include "Piece.h"

class Joueur;

/**
 * Declaration d'une classe modélisant une piece de jeu d'echec.
 */
class Echiquier
{
private:
  /**
   * Les cases de l'echiquier
   */
  Piece* m_cases[ 64 ];

public:

  /**
   * Constructeur par défaut.
   * Initialise à vide l'echiquier.
   */
  Echiquier();

  /**
   * Recupere la piece situee sur une case.
   *
   * @param x un entier entre 1 et 8
   * @param y un entier entre 1 et 8
   *
   * @return 0 si aucune piece n'est sur cette case et un pointeur
   * vers une piece sinon.
   */
  Piece* getPiece( int x, int y );

  /**
   * Place une piece sur l'echiquier, aux coordonnees specifiees dans la piece.
   *
   * @param p un pointeur vers une piece
   *
   * @return 'true' si le placement s'est bien passe, 'false' sinon
   * (case occupee, coordonnees invalides, piece vide )
   */
  bool placer( Piece* p );

  /**
   * Deplace une piece sur l'echiquier, des coordonnees specifiees
   * dans la piece aux coordonnees x,y.
   *
   * @param p un pointeur vers une piece
   * @param x un entier entre 1 et 8
   * @param y un entier entre 1 et 8
   *
   * @return 'true' si le placement s'est bien passe, 'false' sinon
   * (case occupee, coordonnees invalides, piece vide, piece pas
   * presente au bon endroit sur l'echiquier)
   */
  bool deplacer( Piece* p, int x, int y );

  /**
   * Enleve la piece situee sur une case (qui devient vide).
   *
   * @param x un entier entre 1 et 8
   * @param y un entier entre 1 et 8
   *
   * @return 0 si aucune piece n'est sur cette case et le pointeur
   * vers la piece enlevee sinon.
   */
  Piece* enleverPiece( int x, int y );

  /**
   * Affiche l'echiquier avec des # pour les cases noires et . pour
   * les blanches si elles sont vides, et avec B pour les pieces
   * blanches et N pour les pieces noires.
   */
  void affiche();

    /**
    * Permet de savoir si la pièce peux être
    * prise ou non par une autre piece
    **/
    bool caseLibre(Piece &p, int x, int y);

    /**
     * Permet la prise d'une piece par une autre,
     * la supprimant ainsi du plateau
     */
    bool prise(Piece *eater, int x, int y);

    /**
    * Cette fonction permet de savoir si le joueur du tour suivant sera en echec ou non
    *  x et y correspondent à la position du roi du joueur du tour suivant.
    */
    bool chess(Joueur *duTour, Joueur *tourSuivant, int x, int y);

    /**
    * Cette fonction permet de savoir si la partie est finie ou non.
    * @return 0 si la partie n'est pas finie, 1 si le joueur blanc a gagné
    * et 2 si le joueur noir a gagné.
    *
    */
    int gameOver();

    /**
    * Cette fonction retourne le Roi de la couleur demandée.
    * Utilisée pour vérifier la fin du jeu
    * @param white Couleur du Roi souhaitée.
    * @return pointeur sur la piece demandée, NULL sinon
    */
    Piece* getKing(bool white);

};

#endif // !defined Echiquier_h
