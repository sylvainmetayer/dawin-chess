#if !defined JoueurNoir_h
#define JoueurNoir_h

#include "Piece.h"
#include "Echiquier.h"
#include <vector>
#include "Joueur.h"

class JoueurNoir : public Joueur
{
    public:
        JoueurNoir();
        bool isWhite();
        void jouer(Echiquier &e, int x, int y);
};

#endif
