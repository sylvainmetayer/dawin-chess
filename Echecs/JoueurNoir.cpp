#include <iostream>
#include "JoueurNoir.h"


using namespace std;

JoueurNoir::JoueurNoir() : Joueur(false)
{
    //cout << "Construction Joueur Noir par defaut" << endl;
}

bool JoueurNoir::isWhite()
{
    return false;
}
