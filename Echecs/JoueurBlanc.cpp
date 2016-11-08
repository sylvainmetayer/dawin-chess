#include "JoueurBlanc.h"

using namespace std;

JoueurBlanc::JoueurBlanc() : Joueur(true)
{
    //cout << "Construction Joueur Blanc par defaut" << endl;
}

bool JoueurBlanc::isWhite()
{
    return true;
}

bool JoueurBlanc::jouer(Piece *piece, Echiquier &e, int x, int y)
{
    if (!piece->mouvementValide(e,x,y)) {
        cout << "Ce mouvement n'est pas valide pour cette piece."<< endl;
        return false;
    }

    if (!e.deplacer(piece, x, y)) {
        cout << "Le deplacement a echoue (deplacement non valide ou impossible)." << endl;
        return false;
    }

    return true;
}
