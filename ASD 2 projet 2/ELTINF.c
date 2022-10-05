#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include"ELTPRIM.h"

ELEMENT elementCreer(void) {
ELEMENT e ;
e=(ELEMENT)malloc(sizeof(information));
return e ;
}
void elementLire(ELEMENT* e){
printf("Donner le jour :)\n");
  do {
  scanf ("%i",&((*e)->dat.jour));
     } while ((*e)->dat.jour> 31);
  printf("Donner le mois :)\n");
  do {
  scanf ("%i",&((*e)->dat.mois));
     }    while((*e)->dat.mois > 12);
  printf("Donner l'ann%ce :)\n",130);
  do {
  scanf ("%i",&((*e)->dat.annee));
     }while((*e)->dat.annee <1900);
  printf("Donner le nombre de cas positifs :) \n");
  scanf("%i",&((*e)-> CAS_POS));
  printf("Donner le nombre des gu%crisons  :) \n", 130);
  scanf("%i",&((*e)-> GUERISONS));
  printf("Donner le nombre de d%cc%cs      :) \n", 130,138 );
  scanf("%i",&((*e)->DECES));
  printf("Donner le nombre des vaccin%cs   :) \n",130);
  scanf("%i",&((*e)->NB_VACCINES));
  printf("Donner le gouvernorat            :) \n");
  fgets(&(*e)->Nom,20,stdin);
}
void elementDetruire (ELEMENT e){
free(e);
}
void elementAfficher(ELEMENT e){
printf("\n");
printf("la date : %i/%i/%i :) \n",e->dat.jour ,e->dat.mois ,e->dat.annee);
printf("le nombre des cas positifs : %i \n",e-> CAS_POS);
printf("le nombre des gu%crisons :%i \n", 130, e-> GUERISONS);
printf("le nombre de d%cc%cs :%i \n", 130,138,e->DECES  );
printf("le nombre des vaccin%cs : %i \n",130,e->NB_VACCINES );
printf("\n");
printf("\n");
}

void AfficherElement(ELEMENT e)
{
    printf(" %11s   %02i/%02i/%04i  %7i        %5i      %3i    %4i\n",e->Nom,e->dat.jour ,e->dat.mois ,e->dat.annee,e-> CAS_POS,e-> GUERISONS,e->DECES,e->NB_VACCINES);
}



void elementAffecter(ELEMENT* e1, ELEMENT e2){
*e1=e2 ;
}
void elementCopier(ELEMENT * e1, ELEMENT e2) {
    (*e1)->dat.jour= e2->dat.jour ;
    (*e1)->dat.mois= e2->dat.mois ;
    (*e1)->dat.annee= e2->dat.annee ;
    (*e1)-> CAS_POS=e2-> CAS_POS;
    (*e1)->  GUERISONS=e2-> GUERISONS;
    (*e1)-> DECES =e2-> DECES;
    (*e1)-> NB_VACCINES=e2-> NB_VACCINES;
}

int elementComparer(ELEMENT e1, ELEMENT e2){
    if(( ((e1)->dat.annee) - (e2->dat.annee)==0)&&(((e1)->dat.mois) - (e2->dat.mois) ==0)&&(((e1)->dat.jour) - (e2->dat.jour) ==0)&&(((e1)->CAS_POS) - (e2->CAS_POS) ==0)&&(((e1)->GUERISONS) - (e2->GUERISONS) ==0)&&(((e1)->DECES) - (e2->DECES) ==0)) return( 0 );
else return(-1);


}





