#include "JoueurBlanc.h"

using namespace std;

JoueurBlanc::JoueurBlanc() : Joueur(true)
{
    cout << "Construction Joueur Blanc par defaut" << endl;
}

bool JoueurBlanc::isWhite()
{
    return true;
}

void JoueurBlanc::jouer(Echiquier &e, int x, int y)
{

}