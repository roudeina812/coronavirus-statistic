#ifndef LSTPRIIM_H_INCLUDED
#define LSTPRIIM_H_INCLUDED
#include"LSTSDDD.h"

TAB tabCreer(void);
void tabDetruire(TAB);
int esttabVide(TAB);
int esttabSaturee(TAB);
int tabTaille(TAB);
LISTE tabrecuperer(TAB, int);
int tabinserer(TAB, LISTE,int);
int tabsupprimer(TAB, int);
void tabAfficher(TAB);
TAB tabCopier(TAB);
int tabComparer(TAB , TAB );



#endif // LSTPRIIM_H_INCLUDED
