#include "JoueurBlanc.h"

using namespace std;

JoueurBlanc::JoueurBlanc() : Joueur(true) {}

bool JoueurBlanc::isWhite()
{
    return true;
}
