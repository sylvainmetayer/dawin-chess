/**
 * Header de Joueur.cxx
 *
 * @file Joueur.h
 */

#if !defined Joueur_h
#define Joueur_h

#include "Echiquier.h"
#include "Piece.h"
#include "Roi.h"
#include "Reine.h"
#include "Tour.h"
#include "Fou.h"
#include "Cavalier.h"
#include "Pion.h"
#include "debug.h"

#include <vector>

using namespace std;

class Joueur
{
protected:
    /**
    * Permet de savoir si le joueur est en echec ou non
    */
    bool onChess;

    /**
    * Permet de savoir si le joueur est en echec et mat.
    */
    bool chessMat;

    vector<Piece *> m_pieces;
public:
    /**
    * Constructeur de Joueur par défaut
    */
    Joueur();

    /**
    * Destructeur de Joueur
    */
    ~Joueur();

    /**
    * Constructeur spécialisé de Joueur
    * @param white : Permet de savoir si l'on instancie un joueur blanc ou noir.
    */
    Joueur(bool white);

    /**
    * Methode qui permet de savoir si le joueur est le joueur blanc.
    */
    virtual bool isWhite()=0;

    /**
    * Permet de placer les pieces du joueur sur l'echiquier.
    * @param e : L'échiquier sur lequel on veut placer les pieces
    */

    void placerPieces(Echiquier &e);

    // Getter & setter
    bool getOnChess();
    bool getChessMat();
    void setChessMat(bool chessMat);
    void setOnChess(bool onChess);
    vector<Piece*> getPieces();
};

#endif
