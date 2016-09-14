#include <iostream>
#include "Joueur.h"

using namespace std;

Joueur::Joueur()
{
  cout << "Construction Joueur par defaut" << endl;
}

Joueur::~Joueur()
{
  cout << "Destruction Joueur" << endl;
}

Joueur::Joueur(bool white)
{
  int p=0;
  int y=white?1:8;
  for (int x=1;x<=8;x++)
    m_pieces[p++].init(x,y,white);
  y=white?2:7;
  for (int x=1;x<=8;x++)
    m_pieces[p++].init(x,y,white);
  cout << "Construction Joueur specialise" << endl;
}

void
Joueur::affiche()
{
  for (int i=0;i<16;i++)
    m_pieces[i].affiche();
}

bool
Joueur::isWhite()
{
  return m_pieces[0].isWhite();
}

