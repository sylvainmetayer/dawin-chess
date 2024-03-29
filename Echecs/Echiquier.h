/**
 * Header de Echiquier.cxx
 *
 * @file Echiquier.h
 */

#if !defined Echiquier_h
#define Echiquier_h

#include "debug.h"
#include "Piece.h"

class Joueur;

/**
 * Declaration d'une classe mod�lisant une piece de jeu d'echec.
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
     * Constructeur par d�faut.
     * Initialise � vide l'echiquier.
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
    * Permet de savoir si la pi�ce peux �tre
    * prise ou non par une autre piece
    * @param p : la piece qui se d�place
    * @param x : coordonn�es x de d�placement
    * @param y : coordonn�es y de d�placement
    *
    * @return true si la prise est possible, false sinon.
    */
    bool caseLibre(Piece &p, int x, int y);

    /**
     * Permet la prise d'une piece par une autre,
     * la supprimant ainsi du plateau
     * @param eater : La piece qui se deplace
     * @param x le x de destination
     * @param y le y de destination
     * @return false si la piece que l'on tente de retirer
     * est de la meme couleur que la piece qui se deplace,
     * true aucune piece n'a ete supprimee ou si
     * la suppression de piece s'est correctement deroulee
     */
    bool prise(Piece *eater, int x, int y);

    /**
    * Cette fonction permet de savoir si le joueur du tour suivant sera en echec ou non
    * x et y correspondent � la position du roi du joueur du tour suivant.
    *
    * @param x : coordonn�es x du roi adverse.
    * @param y : coordonn�es y du roi adverse
    * @param duTour : joueur actuel.
    * @param tourSuivant : Joueur suivant.
    * @return true si le joueur tourSuivant est en echec, false sinon.
    *
    */
    bool chess(Joueur &duTour, Joueur &tourSuivant, int x, int y);

    /**
    * Cette fonction retourne le Roi de la couleur demand�e.
    * Utilis�e pour v�rifier la fin du jeu
    * @param white Couleur du Roi souhait�e.
    * @return pointeur sur la piece demand�e, 0 sinon
    */
    Piece* getKing(bool white);

    /**
    * Cette fonction permet de savoir si un joueur est echec et mat.
    * @param joueur le joueur que l'on souhaite v�rifier.
    * @return true ou false selon que le joueur est echec ou mat.
    */
    bool checkChessMat(Joueur& joueur);

};

#endif // !defined Echiquier_h
