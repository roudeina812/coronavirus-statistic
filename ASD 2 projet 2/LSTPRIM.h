#ifndef LSTPRIM_H_INCLUDED
#define LSTPRIM_H_INCLUDED
#include"ELTPRIM.h"
#include"LSTSDD.h"
LISTE listeCreer(void);
void listeDetruire(LISTE);
int estVide(LISTE);
int estSaturee(LISTE);
int listeTaille(LISTE);
ELEMENT recuperer(LISTE, int);
int inserer(LISTE, ELEMENT,int);
int supprimer(LISTE, int);
void listeAfficher(LISTE);
LISTE listeCopier(LISTE);
int listeComparer(LISTE, LISTE);
void listAffecter(LISTE * L1 , LISTE L2);

#endif // LSTPRIM_H_INCLUDED
