#include <iostream>
#include "JoueurNoir.h"


using namespace std;

JoueurNoir::JoueurNoir() : Joueur(false) {}

bool JoueurNoir::isWhite()
{
    return false;
}
