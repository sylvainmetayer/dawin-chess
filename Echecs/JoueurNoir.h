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
        bool isWhite();
};

#endif
