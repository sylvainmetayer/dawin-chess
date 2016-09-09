#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED

/**
 * Header de Joueur.cpp
 *
 * @file Joueur.h
 */

 #include <iostream>
 #include "Piece.h"

 using namespace std;

 /**
 * Declaration d'une classe modélisant une piece de jeu d'echec.
 */
class Joueur
{
private:
    Piece pieces[16];
    bool m_white;
    void init();
public:
    ~Joueur();
    Joueur(bool white);
    void affiche();
    bool isWhite();
    Piece get(int x) const;
};

#endif // JOUEUR_H_INCLUDED
