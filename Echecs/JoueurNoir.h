#if !defined JoueurNoir_h
#define JoueurNoir_h

#include <vector>

#include "Piece.h"
#include "Echiquier.h"
#include "Joueur.h"
#include "Roi.h"
#include "Reine.h"
#include "Tour.h"
#include "Fou.h"
#include "Cavalier.h"
#include "Pion.h"
#include "debug.h"

class JoueurNoir : public Joueur
{
public:
    JoueurNoir();

    /**
    * Methode qui permet de savoir si le joueur est le joueur blanc.
    */
    bool isWhite();
};

#endif
