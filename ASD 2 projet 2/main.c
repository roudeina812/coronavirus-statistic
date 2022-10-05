#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<malloc.h>
#include"ELTPRIM.h"
#include"LSTPRIM.h"
#include"LSTPRIIM.h"
#include<time.h>


typedef struct {
ELEMENT elements[1000];
int LONG;
}fortri,*TRI;


int dateComparer(DATE d1, DATE d2);
void permuter (ELEMENT x,ELEMENT y);
int menu (void);
void SUPPRIMER (TAB T);
void MODIFIER (TAB T);
void SAISIRE (TAB T);
void AFFICHER (TAB T);
void TRITAB (TAB T);


int main()
{
//pour changer les valeurs des elements à chaque fois
srand(time(NULL));
//declaration
LISTE L1,L2,L3,L4,L5,L6,L7,L8,L9,L10,L11,L12,L13,L14,L15,L16,L17,L18,L19,L20,L21,L22,L23,L24;
TAB T;
char gouver[20];
int i,j,choix;
T=tabCreer();
FILE *fp;


L1=listeCreer();
L2=listeCreer();
L3=listeCreer();
L4=listeCreer();
L5=listeCreer();
L6=listeCreer();
L7=listeCreer();
L8=listeCreer();
L9=listeCreer();
L10=listeCreer();
L11=listeCreer();
L12=listeCreer();
L13=listeCreer();
L14=listeCreer();
L15=listeCreer();
L16=listeCreer();
L17=listeCreer();
L18=listeCreer();
L19=listeCreer();
L20=listeCreer();
L21=listeCreer();
L22=listeCreer();
L23=listeCreer();
L24=listeCreer();


tabinserer(T,L1,1);
tabinserer(T,L2,2);
tabinserer(T,L3,3);
tabinserer(T,L4,4);
tabinserer(T,L5,5);
tabinserer(T,L6,6);
tabinserer(T,L7,7);
tabinserer(T,L8,8);
tabinserer(T,L9,9);
tabinserer(T,L10,10);
tabinserer(T,L11,11);
tabinserer(T,L12,12);
tabinserer(T,L13,13);
tabinserer(T,L14,14);
tabinserer(T,L15,15);
tabinserer(T,L16,16);
tabinserer(T,L17,17);
tabinserer(T,L18,18);
tabinserer(T,L19,19);
tabinserer(T,L20,20);
tabinserer(T,L21,21);
tabinserer(T,L22,22);
tabinserer(T,L23,23);
tabinserer(T,L24,24);

strcpy(T->gouv[1]->nom, "ARIANA");
strcpy(T->gouv[2]->nom, "BEJA");
strcpy(T->gouv[3]->nom,"BENAROUS");
strcpy(T->gouv[4]->nom,"BENZART");
strcpy(T->gouv[5]->nom,"EL-KEF");
strcpy(T->gouv[6]->nom,"GABES");
strcpy(T->gouv[7]->nom,"GAFSA");
strcpy(T->gouv[8]->nom,"GASSRINE");
strcpy(T->gouv[9]->nom,"GBELLI");
strcpy(T->gouv[10]->nom,"JENDOUBA");
strcpy(T->gouv[11]->nom,"KEROUAN");
strcpy(T->gouv[12]->nom,"MAHDIYA");
strcpy(T->gouv[13]->nom,"MANOUBA");
strcpy(T->gouv[14]->nom,"MEDNINE");
strcpy(T->gouv[15]->nom,"MONASTIR");
strcpy(T->gouv[16]->nom,"NABEL");
strcpy(T->gouv[17]->nom,"SFAX");
strcpy(T->gouv[18]->nom,"SIDI-BOUZID");
strcpy(T->gouv[19]->nom,"SILIANA");
strcpy(T->gouv[20]->nom,"SOUSSE");
strcpy(T->gouv[21]->nom,"TATAOUIN");
strcpy(T->gouv[22]->nom,"TOUZER");
strcpy(T->gouv[23]->nom,"TUNIS");
strcpy(T->gouv[24]->nom,"ZAGHOUEN");
printf("%i\n",T->gouv[3]->lg);



for(i=1;i<=24;i++)
{
    for(j=1;j<=20;j++)
{ ELEMENT e = elementCreer();
  e->dat.jour=j;
  e->dat.mois=03;
  e->dat.annee=2021;
  e->CAS_POS= rand()%1000;
  e->GUERISONS=rand()%100;
  e->DECES=rand()%100;
  e->NB_VACCINES=rand()%100;
  strcpy(e->Nom,T->gouv[i]->nom);
  inserer(T->gouv[i],e,j);


}

}





tabAfficher(T);




printf("\n");
printf("            *****BIENVENUE*****\n\n\n");

do{

choix =menu();

    switch(choix)
      {
        case 1 :SAISIRE (T);
        break;
        case 2 :MODIFIER(T);
        break;
        case 3 :SUPPRIMER(T);
        break;
        case 4 :AFFICHER(T);
        break ;
        case 5 : fichier(T);
        break;
        case 6 :TRITAB(T);

      }


}while(choix!=7);
printf("au revoir :) \n");


    return 0;
}




int menu (void)
{ int choix;
    printf("pour saisie des nouveaux statistiques tapper sur 1 :) \n\n");
printf("pour modifier des coordonn%ces tapper sur 2            :) \n\n",130);
printf("pour supprimer des coordonn%ces tapper sur 3           :) \n\n",130);
printf("pour afficher les statistiques tapper sur 4            :) \n\n");
printf("pour lire une fichier de vous tapper sur 5             :) \n\n");
printf("pour trier les statistiques tapper sur 6               :) \n\n");
printf("pour quitter tapper sur 7                              :) \n\n");
scanf("%i",&choix);
return choix;
}

void fichier(LISTE L[24])
{
    FILE *f;
    char filename[100],str[40],m[8][12];
    ELEMENT e;
    printf("Donner Le Chemin De Fichier : ");
    scanf("%s",filename);

    for(int i=0;i<strlen(filename);i++)
    {
        if(filename[i]=='\\')
        {
            for(int j=strlen(filename);j>i;j--)
                filename[j+1]=filename[j];
            filename[i+1]='\\';
            i++;
        }
    }
    printf("%s\n",filename);
    f=fopen(filename,"r");
    while(fgets(str,40,f)!=NULL)
    {
        e=elementCreer();
        int j=0,k=0;
        for(int i=0; i<40; i++)
        {
            if(str[i]!='#')
                m[j][k]=str[i];
            else
            {
                m[j][k]='\0';
                j++;
                k=-1;
            }
            k++;
        }

        strcpy(e->Nom,m[0]);
        e->dat.jour=atoi(m[1]);
        e->dat.mois=atoi(m[2]);
        e->dat.annee=atoi(m[3]);
        e->CAS_POS=atoi(m[4]);
        e->GUERISONS=atoi(m[5]);
        e->DECES=atoi(m[6]);
        e->NB_VACCINES=atoi(m[7]);
        AfficherElement(e);

        int i=0;
        while(i<24 && strcmp(e->Nom,L[i]->nom))
            i++;
        if(i<24)
        {
            int j=1;
            while(j<=listeTaille(L[i]) && dateComparer(e->dat,recuperer(L[i],j)->dat)>0)
                j++;

            if(j<=listeTaille(L[i]))
                supprimer(L[i],j);
            inserer(L[i],e,j);
        }
        listeAfficher(L[i]);
    }
}

void AFFICHER (TAB T)
{ char gouver [30] ;
 int i ;
     printf("donner le gouvernorat demand%c \n",130);
            scanf("%s",gouver);
            i=1;
            for(i=1;i<=24;i++)
                {if(strcmp(T->gouv[i]->nom,gouver)==0)
                 {listeAfficher(T->gouv[i]);
                     }}
}
void SAISIRE (TAB T)
{ int i;
    printf("donner le date \n");
ELEMENT b =elementCreer();
printf("donner le jour  \n");
scanf("%i",&(b->dat.jour));
printf("donner le mois  \n");
scanf("%i",&(b->dat.mois));
printf("donner l'annee  \n");
scanf("%i",&(b->dat.annee));

for(i=1;i<=24;i++)
{

ELEMENT e = elementCreer();
  e->dat.jour=b->dat.jour;
  e->dat.mois=b->dat.mois;
  e->dat.annee=b->dat.annee;
  printf("donner le nombre des cas positifs :) \n ");
 scanf("%i",&(e->CAS_POS));
 printf("donner le nombre des guerisons :) \n ");
 scanf("%i",&(e->GUERISONS));
printf("donner le nombre des deces :) \n ");
 scanf("%i",&(e->DECES));
 printf("donner le nombre des vaccinees :) \n ");
 scanf("%i",&(e->NB_VACCINES));
  e->NB_VACCINES=rand()%100;
  inserer(T->gouv[i],e,T->gouv[i]->lg+1);


}
}
 void MODIFIER (TAB T)
{

char gouver [30];
int trouve =0;
int i,j;
DATE l;
NOEUD a;

printf("donner la date a modifier \n");
printf(" le jour  \n \a");
scanf("%i",&(l.jour));
printf(" le mois  \n\a");
scanf("%i",&(l.mois));
printf(" l'annee  \n\a");
scanf("%i",&(l.annee));
printf("donner le gouvernorat \n");
scanf("%s",gouver);

i=1;
while((i<24)&&(!trouve))
{if(strcmp(T->gouv[i]->nom,gouver)==0)
 {  trouve =1;
     a=T->gouv[i]->tete;

   for(j=1;j<T->gouv[j]->lg;j++)
    {
       if(dateComparer(a->info->dat,l)==0)
         {
            printf("avant la modification les coordon%ces sont : \n",130);
         printf("le nombre des cas positifs : %i \n\n",a->info-> CAS_POS);
         printf("le nombre des gu%crisons :%i \n\n", 130, a->info-> GUERISONS);
         printf("le nombre de d%cc%cs :%i \n\n", 130,138,a->info->DECES  );
         printf("le nombre des vaccin%cs : %i \n\n",130,a->info->NB_VACCINES );
         printf("apr%cs la modification : \n\n\n", 130);
          printf("donner le nombre de cas positifs :) \n\n");
          scanf("%i",&((a)->info-> CAS_POS));
          printf("donner le nombre des gu%crisons :) \n\n", 130);
          scanf("%i",&((a)->info-> GUERISONS));
          printf("donner le nombre de d%cc%cs :) \n\n", 130,138 );
          scanf("%i",&((a)->info->DECES));
          printf("donner le nombre des vaccin%cs :) \n\n",130);
          scanf("%i",&((a)->info->NB_VACCINES));


           }
       a=a->suivant;

       }


 }
 else i++;
;

}
}
void SUPPRIMER (TAB T)
{
    int trouve =0 ,i,j;
    char gouver [30];
    printf("donner la date  \n");

DATE P;

printf(" le jour  \n \a");
scanf (" %i",&(P.jour));
printf(" le mois  \n\a");
scanf (" %i",&(P.mois));
printf(" l'annee  \n\a");
scanf (" %i",&(P.annee));
printf("donner le gouvernorat \n");
scanf("%s",gouver);


ELEMENT r =elementCreer();
i=1;
while((i<=24)&&(!trouve))
{if(strcmp(T->gouv[i]->nom,gouver)==0)
 {  trouve =1;

   for(j=1;j<T->gouv[i]->lg;j++)
    { r= recuperer(T->gouv[i],j);

       if(dateComparer(r->dat,P)==0)
         {
             supprimer(T->gouv[i],j);

         }


    }
    listeAfficher(T->gouv[i]);
    } else i++;
    }
}


void TRITAB (TAB T)
{
  DATE d;
int i,j,x,k=1;
int prior_1, prior_2,prior_3,prior_4;
printf("donner le jour :)\n");
  do {
  scanf ("%i",&d.jour);
     } while (d.jour> 31);
  printf("donner le mois :)\n");
  do {
  scanf ("%i",&d.mois);
     }    while(d.mois > 12);
  printf("donner l'ann%ce :)\n",130);
  do {scanf ("%i",&d.annee);}while(d.annee<1900);
printf(" si vous voulez un tri croissant tapez 1 sinon 0\n");
do{
scanf("%i",&x);}while ((x>1)||(x<0));
printf("donner la priorit%c des cas positifs : ",130);
do{
scanf("%i",&prior_1);}while ((prior_1>4)||(prior_1<1));
printf("donner la priorit%c des deces : ",130);
do{
scanf("%i",&prior_2);}while ((prior_2>4)||(prior_2<1));
printf("donner la priorit%c des gu%crisons : ",130);
do{
scanf("%i",&prior_3);}while ((prior_3>4)||(prior_3<1));
printf("donner la priorit%c des nombres de vaccins : ",130);
do{
scanf("%i",&prior_4);}while ((prior_4>4)||(prior_4<1));



TRI R;
R=(TRI)malloc(sizeof(fortri));
R->LONG=0;

NOEUD q;
//printf("%i\n",R->LONG);
//printf("  GOUVERNORAT      DATE     CAS POSITIFS  GUERISONS  DECES  VACCINES \n");
   for(i=1;i<=24;i++)
 {q=T->gouv[i]->tete;
    for(j=1;j<=T->gouv[i]->lg;j++)
    { if(dateComparer(q->info->dat,d)==0)
       { ELEMENT e = elementCreer();
         elementAffecter(&e,recuperer(T->gouv[i],j));
        elementAffecter(&(R->elements[k]),e);
        k++;
        R->LONG++;
        }
        q=q->suivant;
    }

  }
printf("%i",R->LONG);
  printf("  GOUVERNORAT      DATE     CAS POSITIFS  GUERISONS  DECES  VACCINES \n");
for(i=1;i<=(R->LONG);i++)
{
    AfficherElement(R->elements[i]);

}
 //printf("%i",R->LONG);



//printf(" les nombres des cases: %i",R->LONG);


if(x==1){
if ((prior_1==1)&&(prior_2==2)&&(prior_3==3)&&(prior_4==4))

{for(i=1;i<R->LONG;i++)
{for(j=1;j<R->LONG;j++){
if((R->elements[j]->CAS_POS)< (R->elements[j+1]->CAS_POS))

{permuter(R->elements[j],R->elements[j+1]);}
else {if((R->elements[j]->CAS_POS)== (R->elements[j+1]->CAS_POS))
        {if((R->elements[j]->DECES)< (R->elements[j+1]->DECES))
            {permuter(R->elements[j],R->elements[j+1]);}
              else {if((R->elements[j]->DECES)==(R->elements[j+1]->DECES))
                      {if((R->elements[j]->GUERISONS)< (R->elements[j+1]->GUERISONS))
                          { permuter(R->elements[j],R->elements[j+1]);}
                            else {if ((R->elements[j]->GUERISONS)== (R->elements[j+1]->GUERISONS))
                                    {if((R->elements[j]->NB_VACCINES)< (R->elements[j+1]->NB_VACCINES))
                                                       permuter(R->elements[j],R->elements[j+1]);
                                                        }}
                           }}
    }}}
}

}
else{
if ((prior_1==1)&&(prior_2==3)&&(prior_3==2)&&(prior_4==4))

{for(i=1;i<R->LONG;i++)
{for(j=1;j<R->LONG;j++){
if((R->elements[j]->CAS_POS)< (R->elements[j+1]->CAS_POS))

{permuter(R->elements[j],R->elements[j+1]);}
else {if((R->elements[j]->CAS_POS)== (R->elements[j+1]->CAS_POS))
        {if((R->elements[j]->GUERISONS)< (R->elements[j+1]->GUERISONS))
            {permuter(R->elements[j],R->elements[j+1]);}
              else {if((R->elements[j]->GUERISONS)==(R->elements[j+1]->GUERISONS))
                      {if((R->elements[j]->DECES)< (R->elements[j+1]->DECES))
                          { permuter(R->elements[j],R->elements[j+1]);}
                            else {if ((R->elements[j]->DECES)== (R->elements[j+1]->DECES))
                                    {if((R->elements[j]->NB_VACCINES)< (R->elements[j+1]->NB_VACCINES))
                                                       permuter(R->elements[j],R->elements[j+1]);
                                                        }}
                           }}
    }}}
}

}
else { if ((prior_1==1)&&(prior_2==3)&&(prior_3==4)&&(prior_4==2))

{for(i=1;i<R->LONG;i++)
{for(j=1;j<R->LONG;j++){
if((R->elements[j]->CAS_POS)< (R->elements[j+1]->CAS_POS))

{permuter(R->elements[j],R->elements[j+1]);}
else {if((R->elements[j]->CAS_POS)== (R->elements[j+1]->CAS_POS))
        {if((R->elements[j]->NB_VACCINES)< (R->elements[j+1]->NB_VACCINES))
            {permuter(R->elements[j],R->elements[j+1]);}
              else {if((R->elements[j]->NB_VACCINES)==(R->elements[j+1]->NB_VACCINES))
                      {if((R->elements[j]->DECES)< (R->elements[j+1]->DECES))
                          { permuter(R->elements[j],R->elements[j+1]);}
                            else {if ((R->elements[j]->DECES)== (R->elements[j+1]->DECES))
                                    {if((R->elements[j]->GUERISONS)< (R->elements[j+1]->GUERISONS))
                                                       permuter(R->elements[j],R->elements[j+1]);
                                                        }}
                           }}
    }}}
}

}
else{
        if ((prior_1==1)&&(prior_2==2)&&(prior_3==4)&&(prior_4==3))

{for(i=1;i<R->LONG;i++)
{for(j=1;j<R->LONG;j++){
if((R->elements[j]->CAS_POS)< (R->elements[j+1]->CAS_POS))

{permuter(R->elements[j],R->elements[j+1]);}
else {if((R->elements[j]->CAS_POS)== (R->elements[j+1]->CAS_POS))
        {if((R->elements[j]->DECES)< (R->elements[j+1]->DECES))
            {permuter(R->elements[j],R->elements[j+1]);}
              else {if((R->elements[j]->DECES)==(R->elements[j+1]->DECES))
                      {if((R->elements[j]->NB_VACCINES)< (R->elements[j+1]->NB_VACCINES))
                          { permuter(R->elements[j],R->elements[j+1]);}
                            else {if ((R->elements[j]->NB_VACCINES)== (R->elements[j+1]->NB_VACCINES))
                                    {if((R->elements[j]->GUERISONS)< (R->elements[j+1]->GUERISONS))
                                                       permuter(R->elements[j],R->elements[j+1]);
                                                        }}
                           }}
    }}}
}

}
 else { if ((prior_1==1)&&(prior_2==4)&&(prior_3==2)&&(prior_4==3))

{for(i=1;i<R->LONG;i++)
{for(j=1;j<R->LONG;j++){
if((R->elements[j]->CAS_POS)< (R->elements[j+1]->CAS_POS))

{permuter(R->elements[j],R->elements[j+1]);}
else {if((R->elements[j]->CAS_POS)== (R->elements[j+1]->CAS_POS))
        {if((R->elements[j]->GUERISONS)< (R->elements[j+1]->GUERISONS))
            {permuter(R->elements[j],R->elements[j+1]);}
              else {if((R->elements[j]->GUERISONS)==(R->elements[j+1]->GUERISONS))
                      {if((R->elements[j]->NB_VACCINES)< (R->elements[j+1]->NB_VACCINES))
                          { permuter(R->elements[j],R->elements[j+1]);}
                            else {if ((R->elements[j]->NB_VACCINES)== (R->elements[j+1]->NB_VACCINES))
                                    {if((R->elements[j]->DECES)< (R->elements[j+1]->DECES))
                                                       permuter(R->elements[j],R->elements[j+1]);
                                                        }}
                           }}
    }}}
}

}
else{
    if ((prior_1==1)&&(prior_2==4)&&(prior_3==3)&&(prior_4==2))

{for(i=1;i<R->LONG;i++)
{for(j=1;j<R->LONG;j++){
if((R->elements[j]->CAS_POS)< (R->elements[j+1]->CAS_POS))

{permuter(R->elements[j],R->elements[j+1]);}
else {if((R->elements[j]->CAS_POS)== (R->elements[j+1]->CAS_POS))
        {if((R->elements[j]->NB_VACCINES)< (R->elements[j+1]->NB_VACCINES))
            {permuter(R->elements[j],R->elements[j+1]);}
              else {if((R->elements[j]->NB_VACCINES)==(R->elements[j+1]->NB_VACCINES))
                      {if((R->elements[j]->GUERISONS)< (R->elements[j+1]->GUERISONS))
                          { permuter(R->elements[j],R->elements[j+1]);}
                            else {if ((R->elements[j]->GUERISONS)== (R->elements[j+1]->GUERISONS))
                                    {if((R->elements[j]->DECES)< (R->elements[j+1]->DECES))
                                                       permuter(R->elements[j],R->elements[j+1]);
                                                        }}
                           }}
    }}}
}

}

else{
if ((prior_1==2)&&(prior_2==1)&&(prior_3==3)&&(prior_4==4))

{for(i=1;i<R->LONG;i++)
{for(j=1;j<R->LONG;j++){
if((R->elements[j]->DECES)< (R->elements[j+1]->DECES))

{permuter(R->elements[j],R->elements[j+1]);}
else {if((R->elements[j]->DECES)== (R->elements[j+1]->DECES))
        {if((R->elements[j]->CAS_POS)< (R->elements[j+1]->CAS_POS))
            {permuter(R->elements[j],R->elements[j+1]);}
              else {if((R->elements[j]->CAS_POS)==(R->elements[j+1]->CAS_POS))
                      {if((R->elements[j]->GUERISONS)< (R->elements[j+1]->GUERISONS))
                          { permuter(R->elements[j],R->elements[j+1]);}
                            else {if ((R->elements[j]->GUERISONS)== (R->elements[j+1]->GUERISONS))
                                    {if((R->elements[j]->NB_VACCINES)< (R->elements[j+1]->NB_VACCINES))
                                                       permuter(R->elements[j],R->elements[j+1]);
                                                        }}
                           }}
    }}}
}

}
else { if ((prior_1==2)&&(prior_2==1)&&(prior_3==4)&&(prior_4==3))

{for(i=1;i<R->LONG;i++)
{for(j=1;j<R->LONG;j++){
if((R->elements[j]->DECES)< (R->elements[j+1]->DECES))

{permuter(R->elements[j],R->elements[j+1]);}
else {if((R->elements[j]->DECES)== (R->elements[j+1]->DECES))
        {if((R->elements[j]->CAS_POS)< (R->elements[j+1]->CAS_POS))
            {permuter(R->elements[j],R->elements[j+1]);}
              else {if((R->elements[j]->CAS_POS)==(R->elements[j+1]->CAS_POS))
                      {if((R->elements[j]->NB_VACCINES)< (R->elements[j+1]->NB_VACCINES))
                          { permuter(R->elements[j],R->elements[j+1]);}
                            else {if ((R->elements[j]->NB_VACCINES)== (R->elements[j+1]->NB_VACCINES))
                                    {if((R->elements[j]->GUERISONS)< (R->elements[j+1]->GUERISONS))
                                                       permuter(R->elements[j],R->elements[j+1]);
                                                        }}
                           }}
    }}}
}

}
else{
        if ((prior_1==3)&&(prior_2==1)&&(prior_3==2)&&(prior_4==4))

{for(i=1;i<R->LONG;i++)
{for(j=1;j<R->LONG;j++){
if((R->elements[j]->DECES)< (R->elements[j+1]->DECES))

{permuter(R->elements[j],R->elements[j+1]);}
else {if((R->elements[j]->DECES)== (R->elements[j+1]->DECES))
        {if((R->elements[j]->GUERISONS)< (R->elements[j+1]->GUERISONS))
            {permuter(R->elements[j],R->elements[j+1]);}
              else {if((R->elements[j]->GUERISONS)==(R->elements[j+1]->GUERISONS))
                      {if((R->elements[j]->CAS_POS)< (R->elements[j+1]->CAS_POS))
                          { permuter(R->elements[j],R->elements[j+1]);}
                            else {if ((R->elements[j]->CAS_POS)== (R->elements[j+1]->CAS_POS))
                                    {if((R->elements[j]->NB_VACCINES)< (R->elements[j+1]->NB_VACCINES))
                                                       permuter(R->elements[j],R->elements[j+1]);
                                                        }}
                           }}
    }}}
}

}
 else { if ((prior_1==4)&&(prior_2==1)&&(prior_3==2)&&(prior_4==3))

{for(i=1;i<R->LONG;i++)
{for(j=1;j<R->LONG;j++){
if((R->elements[j]->DECES)< (R->elements[j+1]->DECES))

{permuter(R->elements[j],R->elements[j+1]);}
else {if((R->elements[j]->DECES)== (R->elements[j+1]->DECES))
        {if((R->elements[j]->GUERISONS)< (R->elements[j+1]->GUERISONS))
            {permuter(R->elements[j],R->elements[j+1]);}
              else {if((R->elements[j]->GUERISONS)==(R->elements[j+1]->GUERISONS))
                      {if((R->elements[j]->NB_VACCINES)< (R->elements[j+1]->NB_VACCINES))
                          { permuter(R->elements[j],R->elements[j+1]);}
                            else {if ((R->elements[j]->NB_VACCINES)== (R->elements[j+1]->NB_VACCINES))
                                    {if((R->elements[j]->CAS_POS)< (R->elements[j+1]->CAS_POS))
                                                       permuter(R->elements[j],R->elements[j+1]);
                                                        }}
                           }}
    }}}
}

}
else{
    if ((prior_1==3)&&(prior_2==1)&&(prior_3==4)&&(prior_4==2))

{for(i=1;i<R->LONG;i++)
{for(j=1;j<R->LONG;j++){
if((R->elements[j]->DECES)< (R->elements[j+1]->DECES))

{permuter(R->elements[j],R->elements[j+1]);}
else {if((R->elements[j]->DECES)== (R->elements[j+1]->DECES))
        {if((R->elements[j]->NB_VACCINES)< (R->elements[j+1]->NB_VACCINES))
            {permuter(R->elements[j],R->elements[j+1]);}
              else {if((R->elements[j]->NB_VACCINES)==(R->elements[j+1]->NB_VACCINES))
                      {if((R->elements[j]->CAS_POS)< (R->elements[j+1]->CAS_POS))
                          { permuter(R->elements[j],R->elements[j+1]);}
                            else {if ((R->elements[j]->CAS_POS)== (R->elements[j+1]->CAS_POS))
                                    {if((R->elements[j]->GUERISONS)< (R->elements[j+1]->GUERISONS))
                                                       permuter(R->elements[j],R->elements[j+1]);
                                                        }}
                           }}
    }}}
}

}
else{
    if ((prior_1==4)&&(prior_2==1)&&(prior_3==3)&&(prior_4==2))

{for(i=1;i<R->LONG;i++)
{for(j=1;j<R->LONG;j++){
if((R->elements[j]->DECES)< (R->elements[j+1]->DECES))

{permuter(R->elements[j],R->elements[j+1]);}
else {if((R->elements[j]->DECES)== (R->elements[j+1]->DECES))
        {if((R->elements[j]->NB_VACCINES)< (R->elements[j+1]->NB_VACCINES))
            {permuter(R->elements[j],R->elements[j+1]);}
              else {if((R->elements[j]->NB_VACCINES)==(R->elements[j+1]->NB_VACCINES))
                      {if((R->elements[j]->GUERISONS)< (R->elements[j+1]->GUERISONS))
                          { permuter(R->elements[j],R->elements[j+1]);}
                            else {if ((R->elements[j]->GUERISONS)== (R->elements[j+1]->GUERISONS))
                                    {if((R->elements[j]->CAS_POS)< (R->elements[j+1]->CAS_POS))
                                                       permuter(R->elements[j],R->elements[j+1]);
                                                        }}
                           }}
    }}}
}

}
else{
if ((prior_1==2)&&(prior_2==3)&&(prior_3==1)&&(prior_4==4))

{for(i=1;i<R->LONG;i++)
{for(j=1;j<R->LONG;j++){
if((R->elements[j]->GUERISONS)< (R->elements[j+1]->GUERISONS))

{permuter(R->elements[j],R->elements[j+1]);}
else {if((R->elements[j]->GUERISONS)== (R->elements[j+1]->GUERISONS))
        {if((R->elements[j]->CAS_POS)< (R->elements[j+1]->CAS_POS))
            {permuter(R->elements[j],R->elements[j+1]);}
              else {if((R->elements[j]->CAS_POS)==(R->elements[j+1]->CAS_POS))
                      {if((R->elements[j]->DECES)< (R->elements[j+1]->DECES))
                          { permuter(R->elements[j],R->elements[j+1]);}
                            else {if ((R->elements[j]->DECES)== (R->elements[j+1]->DECES))
                                    {if((R->elements[j]->NB_VACCINES)< (R->elements[j+1]->NB_VACCINES))
                                                       permuter(R->elements[j],R->elements[j+1]);
                                                        }}
                           }}
    }}}
}

}
else { if ((prior_1==2)&&(prior_2==4)&&(prior_3==1)&&(prior_4==3))

{for(i=1;i<R->LONG;i++)
{for(j=1;j<R->LONG;j++){
if((R->elements[j]->GUERISONS)< (R->elements[j+1]->GUERISONS))

{permuter(R->elements[j],R->elements[j+1]);}
else {if((R->elements[j]->GUERISONS)== (R->elements[j+1]->GUERISONS))
        {if((R->elements[j]->CAS_POS)< (R->elements[j+1]->CAS_POS))
            {permuter(R->elements[j],R->elements[j+1]);}
              else {if((R->elements[j]->CAS_POS)==(R->elements[j+1]->CAS_POS))
                      {if((R->elements[j]->NB_VACCINES)< (R->elements[j+1]->NB_VACCINES))
                          { permuter(R->elements[j],R->elements[j+1]);}
                            else {if ((R->elements[j]->NB_VACCINES)== (R->elements[j+1]->NB_VACCINES))
                                    {if((R->elements[j]->DECES)< (R->elements[j+1]->DECES))
                                                       permuter(R->elements[j],R->elements[j+1]);
                                                        }}
                           }}
    }}}
}

}
else{
        if ((prior_1==3)&&(prior_2==2)&&(prior_3==1)&&(prior_4==4))

{for(i=1;i<R->LONG;i++)
{for(j=1;j<R->LONG;j++){
if((R->elements[j]->GUERISONS)< (R->elements[j+1]->GUERISONS))

{permuter(R->elements[j],R->elements[j+1]);}
else {if((R->elements[j]->GUERISONS)== (R->elements[j+1]->GUERISONS))
        {if((R->elements[j]->DECES)< (R->elements[j+1]->DECES))
            {permuter(R->elements[j],R->elements[j+1]);}
              else {if((R->elements[j]->DECES)==(R->elements[j+1]->DECES))
                      {if((R->elements[j]->CAS_POS)< (R->elements[j+1]->CAS_POS))
                          { permuter(R->elements[j],R->elements[j+1]);}
                            else {if ((R->elements[j]->CAS_POS)== (R->elements[j+1]->CAS_POS))
                                    {if((R->elements[j]->NB_VACCINES)< (R->elements[j+1]->NB_VACCINES))
                                                       permuter(R->elements[j],R->elements[j+1]);
                                                        }}
                           }}
    }}}
}

}
 else { if ((prior_1==4)&&(prior_2==2)&&(prior_3==1)&&(prior_4==3))

{for(i=1;i<R->LONG;i++)
{for(j=1;j<R->LONG;j++){
if((R->elements[j]->GUERISONS)< (R->elements[j+1]->GUERISONS))

{permuter(R->elements[j],R->elements[j+1]);}
else {if((R->elements[j]->GUERISONS)== (R->elements[j+1]->GUERISONS))
        {if((R->elements[j]->DECES)< (R->elements[j+1]->DECES))
            {permuter(R->elements[j],R->elements[j+1]);}
              else {if((R->elements[j]->DECES)==(R->elements[j+1]->DECES))
                      {if((R->elements[j]->NB_VACCINES)< (R->elements[j+1]->NB_VACCINES))
                          { permuter(R->elements[j],R->elements[j+1]);}
                            else {if ((R->elements[j]->NB_VACCINES)== (R->elements[j+1]->NB_VACCINES))
                                    {if((R->elements[j]->CAS_POS)< (R->elements[j+1]->CAS_POS))
                                                       permuter(R->elements[j],R->elements[j+1]);
                                                        }}
                           }}
    }}}
}

}
else{
    if ((prior_1==3)&&(prior_2==4)&&(prior_3==1)&&(prior_4==2))

{for(i=1;i<R->LONG;i++)
{for(j=1;j<R->LONG;j++){
if((R->elements[j]->GUERISONS)< (R->elements[j+1]->GUERISONS))

{permuter(R->elements[j],R->elements[j+1]);}
else {if((R->elements[j]->GUERISONS)== (R->elements[j+1]->GUERISONS))
        {if((R->elements[j]->NB_VACCINES)< (R->elements[j+1]->NB_VACCINES))
            {permuter(R->elements[j],R->elements[j+1]);}
              else {if((R->elements[j]->NB_VACCINES)==(R->elements[j+1]->NB_VACCINES))
                      {if((R->elements[j]->CAS_POS)< (R->elements[j+1]->CAS_POS))
                          { permuter(R->elements[j],R->elements[j+1]);}
                            else {if ((R->elements[j]->CAS_POS)== (R->elements[j+1]->CAS_POS))
                                    {if((R->elements[j]->DECES)< (R->elements[j+1]->DECES))
                                                       permuter(R->elements[j],R->elements[j+1]);
                                                        }}
                           }}
    }}}
}

}
else{
    if ((prior_1==4)&&(prior_2==3)&&(prior_3==1)&&(prior_4==2))

{for(i=1;i<R->LONG;i++)
{for(j=1;j<R->LONG;j++){
if((R->elements[j]->GUERISONS)< (R->elements[j+1]->GUERISONS))

{permuter(R->elements[j],R->elements[j+1]);}
else {if((R->elements[j]->GUERISONS)== (R->elements[j+1]->GUERISONS))
        {if((R->elements[j]->NB_VACCINES)< (R->elements[j+1]->NB_VACCINES))
            {permuter(R->elements[j],R->elements[j+1]);}
              else {if((R->elements[j]->NB_VACCINES)==(R->elements[j+1]->NB_VACCINES))
                      {if((R->elements[j]->DECES)< (R->elements[j+1]->DECES))
                          { permuter(R->elements[j],R->elements[j+1]);}
                            else {if ((R->elements[j]->DECES)== (R->elements[j+1]->DECES))
                                    {if((R->elements[j]->CAS_POS)< (R->elements[j+1]->CAS_POS))
                                                       permuter(R->elements[j],R->elements[j+1]);
                                                        }}
                           }}
    }}}
}

}
else{
if ((prior_1==2)&&(prior_2==3)&&(prior_3==4)&&(prior_4==1))

{for(i=1;i<R->LONG;i++)
{for(j=1;j<R->LONG;j++){
if((R->elements[j]->NB_VACCINES)< (R->elements[j+1]->NB_VACCINES))

{permuter(R->elements[j],R->elements[j+1]);}
else {if((R->elements[j]->NB_VACCINES)== (R->elements[j+1]->NB_VACCINES))
        {if((R->elements[j]->CAS_POS)< (R->elements[j+1]->CAS_POS))
            {permuter(R->elements[j],R->elements[j+1]);}
              else {if((R->elements[j]->CAS_POS)==(R->elements[j+1]->CAS_POS))
                      {if((R->elements[j]->DECES)< (R->elements[j+1]->DECES))
                          { permuter(R->elements[j],R->elements[j+1]);}
                            else {if ((R->elements[j]->DECES)== (R->elements[j+1]->DECES))
                                    {if((R->elements[j]->GUERISONS)< (R->elements[j+1]->GUERISONS))
                                                       permuter(R->elements[j],R->elements[j+1]);
                                                        }}
                           }}
    }}}
}

}
else { if ((prior_1==3)&&(prior_2==2)&&(prior_3==4)&&(prior_4==1))

{for(i=1;i<R->LONG;i++)
{for(j=1;j<R->LONG;j++){
if((R->elements[j]->NB_VACCINES)< (R->elements[j+1]->NB_VACCINES))

{permuter(R->elements[j],R->elements[j+1]);}
else {if((R->elements[j]->NB_VACCINES)== (R->elements[j+1]->NB_VACCINES))
        {if((R->elements[j]->DECES)< (R->elements[j+1]->DECES))
            {permuter(R->elements[j],R->elements[j+1]);}
              else {if((R->elements[j]->DECES)==(R->elements[j+1]->DECES))
                      {if((R->elements[j]->CAS_POS)< (R->elements[j+1]->CAS_POS))
                          { permuter(R->elements[j],R->elements[j+1]);}
                            else {if ((R->elements[j]->CAS_POS)== (R->elements[j+1]->CAS_POS))
                                    {if((R->elements[j]->GUERISONS)< (R->elements[j+1]->GUERISONS))
                                                       permuter(R->elements[j],R->elements[j+1]);
                                                        }}
                           }}
    }}}
}

}
else{
        if ((prior_1==4)&&(prior_2==2)&&(prior_3==3)&&(prior_4==1))

{for(i=1;i<R->LONG;i++)
{for(j=1;j<R->LONG;j++){
if((R->elements[j]->NB_VACCINES)< (R->elements[j+1]->NB_VACCINES))

{permuter(R->elements[j],R->elements[j+1]);}
else {if((R->elements[j]->NB_VACCINES)== (R->elements[j+1]->NB_VACCINES))
        {if((R->elements[j]->DECES)< (R->elements[j+1]->DECES))
            {permuter(R->elements[j],R->elements[j+1]);}
              else {if((R->elements[j]->DECES)==(R->elements[j+1]->DECES))
                      {if((R->elements[j]->GUERISONS)< (R->elements[j+1]->GUERISONS))
                          { permuter(R->elements[j],R->elements[j+1]);}
                            else {if ((R->elements[j]->GUERISONS)== (R->elements[j+1]->GUERISONS))
                                    {if((R->elements[j]->CAS_POS)< (R->elements[j+1]->CAS_POS))
                                                       permuter(R->elements[j],R->elements[j+1]);
                                                        }}
                           }}
    }}}
}

}
 else { if ((prior_1==3)&&(prior_2==4)&&(prior_3==2)&&(prior_4==1))

{for(i=1;i<R->LONG;i++)
{for(j=1;j<R->LONG;j++){
if((R->elements[j]->NB_VACCINES)< (R->elements[j+1]->NB_VACCINES))

{permuter(R->elements[j],R->elements[j+1]);}
else {if((R->elements[j]->NB_VACCINES)== (R->elements[j+1]->NB_VACCINES))
        {if((R->elements[j]->GUERISONS)< (R->elements[j+1]->GUERISONS))
            {permuter(R->elements[j],R->elements[j+1]);}
              else {if((R->elements[j]->GUERISONS)==(R->elements[j+1]->GUERISONS))
                      {if((R->elements[j]->CAS_POS)< (R->elements[j+1]->CAS_POS))
                          { permuter(R->elements[j],R->elements[j+1]);}
                            else {if ((R->elements[j]->CAS_POS)== (R->elements[j+1]->CAS_POS))
                                    {if((R->elements[j]->DECES)< (R->elements[j+1]->DECES))
                                                       permuter(R->elements[j],R->elements[j+1]);
                                                        }}
                           }}
    }}}
}

}
else{
    if ((prior_1==4)&&(prior_2==3)&&(prior_3==2)&&(prior_4==1))

{for(i=1;i<R->LONG;i++)
{for(j=1;j<R->LONG;j++){
if((R->elements[j]->NB_VACCINES)< (R->elements[j+1]->NB_VACCINES))

{permuter(R->elements[j],R->elements[j+1]);}
else {if((R->elements[j]->NB_VACCINES)== (R->elements[j+1]->NB_VACCINES))
        {if((R->elements[j]->GUERISONS)< (R->elements[j+1]->GUERISONS))
            {permuter(R->elements[j],R->elements[j+1]);}
              else {if((R->elements[j]->GUERISONS)==(R->elements[j+1]->GUERISONS))
                      {if((R->elements[j]->DECES)< (R->elements[j+1]->DECES))
                          { permuter(R->elements[j],R->elements[j+1]);}
                            else {if ((R->elements[j]->DECES)== (R->elements[j+1]->DECES))
                                    {if((R->elements[j]->CAS_POS)< (R->elements[j+1]->CAS_POS))
                                                       permuter(R->elements[j],R->elements[j+1]);
                                                        }}
                           }}
    }}}
}

}
else{
    if ((prior_1==2)&&(prior_2==4)&&(prior_3==3)&&(prior_4==1))

{for(i=1;i<R->LONG;i++)
{for(j=1;j<R->LONG;j++){
if((R->elements[j]->NB_VACCINES)< (R->elements[j+1]->NB_VACCINES))

{permuter(R->elements[j],R->elements[j+1]);}
else {if((R->elements[j]->NB_VACCINES)== (R->elements[j+1]->NB_VACCINES))
        {if((R->elements[j]->CAS_POS)< (R->elements[j+1]->CAS_POS))
            {permuter(R->elements[j],R->elements[j+1]);}
              else {if((R->elements[j]->CAS_POS)==(R->elements[j+1]->CAS_POS))
                      {if((R->elements[j]->GUERISONS)< (R->elements[j+1]->GUERISONS))
                          { permuter(R->elements[j],R->elements[j+1]);}
                            else {if ((R->elements[j]->GUERISONS)== (R->elements[j+1]->GUERISONS))
                                    {if((R->elements[j]->DECES)< (R->elements[j+1]->DECES))
                                                       permuter(R->elements[j],R->elements[j+1]);
                                                        }}
                           }}
    }}}
}

}
}}}}}}}}}}}}}}}}}}}}}}} // elseeeet



} // brace for [if (x==1)]
else {if(x==0){
if ((prior_1==1)&&(prior_2==2)&&(prior_3==3)&&(prior_4==4))

{for(i=1;i<R->LONG;i++)
{for(j=1;j<R->LONG;j++){
if((R->elements[j]->CAS_POS)> (R->elements[j+1]->CAS_POS))

{permuter(R->elements[j],R->elements[j+1]);}
else {if((R->elements[j]->CAS_POS)== (R->elements[j+1]->CAS_POS))
        {if((R->elements[j]->DECES)> (R->elements[j+1]->DECES))
            {permuter(R->elements[j],R->elements[j+1]);}
              else {if((R->elements[j]->DECES)==(R->elements[j+1]->DECES))
                      {if((R->elements[j]->GUERISONS)> (R->elements[j+1]->GUERISONS))
                          { permuter(R->elements[j],R->elements[j+1]);}
                            else {if ((R->elements[j]->GUERISONS)== (R->elements[j+1]->GUERISONS))
                                    {if((R->elements[j]->NB_VACCINES)> (R->elements[j+1]->NB_VACCINES))
                                                       permuter(R->elements[j],R->elements[j+1]);
                                                        }}
                           }}
    }}}
}

}
else{
if ((prior_1==1)&&(prior_2==3)&&(prior_3==2)&&(prior_4==4))

{for(i=1;i<R->LONG;i++)
{for(j=1;j<R->LONG;j++){
if((R->elements[j]->CAS_POS)> (R->elements[j+1]->CAS_POS))

{permuter(R->elements[j],R->elements[j+1]);}
else {if((R->elements[j]->CAS_POS)== (R->elements[j+1]->CAS_POS))
        {if((R->elements[j]->GUERISONS)> (R->elements[j+1]->GUERISONS))
            {permuter(R->elements[j],R->elements[j+1]);}
              else {if((R->elements[j]->GUERISONS)==(R->elements[j+1]->GUERISONS))
                      {if((R->elements[j]->DECES)> (R->elements[j+1]->DECES))
                          { permuter(R->elements[j],R->elements[j+1]);}
                            else {if ((R->elements[j]->DECES)== (R->elements[j+1]->DECES))
                                    {if((R->elements[j]->NB_VACCINES)> (R->elements[j+1]->NB_VACCINES))
                                                       permuter(R->elements[j],R->elements[j+1]);
                                                        }}
                           }}
    }}}
}

}
else { if ((prior_1==1)&&(prior_2==3)&&(prior_3==4)&&(prior_4==2))

{for(i=1;i<R->LONG;i++)
{for(j=1;j<R->LONG;j++){
if((R->elements[j]->CAS_POS)> (R->elements[j+1]->CAS_POS))

{permuter(R->elements[j],R->elements[j+1]);}
else {if((R->elements[j]->CAS_POS)== (R->elements[j+1]->CAS_POS))
        {if((R->elements[j]->NB_VACCINES)> (R->elements[j+1]->NB_VACCINES))
            {permuter(R->elements[j],R->elements[j+1]);}
              else {if((R->elements[j]->NB_VACCINES)==(R->elements[j+1]->NB_VACCINES))
                      {if((R->elements[j]->DECES)> (R->elements[j+1]->DECES))
                          { permuter(R->elements[j],R->elements[j+1]);}
                            else {if ((R->elements[j]->DECES)== (R->elements[j+1]->DECES))
                                    {if((R->elements[j]->GUERISONS)> (R->elements[j+1]->GUERISONS))
                                                       permuter(R->elements[j],R->elements[j+1]);
                                                        }}
                           }}
    }}}
}

}
else{
        if ((prior_1==1)&&(prior_2==2)&&(prior_3==4)&&(prior_4==3))

{for(i=1;i<R->LONG;i++)
{for(j=1;j<R->LONG;j++){
if((R->elements[j]->CAS_POS)> (R->elements[j+1]->CAS_POS))

{permuter(R->elements[j],R->elements[j+1]);}
else {if((R->elements[j]->CAS_POS)== (R->elements[j+1]->CAS_POS))
        {if((R->elements[j]->DECES)> (R->elements[j+1]->DECES))
            {permuter(R->elements[j],R->elements[j+1]);}
              else {if((R->elements[j]->DECES)==(R->elements[j+1]->DECES))
                      {if((R->elements[j]->NB_VACCINES)> (R->elements[j+1]->NB_VACCINES))
                          { permuter(R->elements[j],R->elements[j+1]);}
                            else {if ((R->elements[j]->NB_VACCINES)== (R->elements[j+1]->NB_VACCINES))
                                    {if((R->elements[j]->GUERISONS)> (R->elements[j+1]->GUERISONS))
                                                       permuter(R->elements[j],R->elements[j+1]);
                                                        }}
                           }}
    }}}
}

}
 else { if ((prior_1==1)&&(prior_2==4)&&(prior_3==2)&&(prior_4==3))

{for(i=1;i<R->LONG;i++)
{for(j=1;j<R->LONG;j++){
if((R->elements[j]->CAS_POS)> (R->elements[j+1]->CAS_POS))

{permuter(R->elements[j],R->elements[j+1]);}
else {if((R->elements[j]->CAS_POS)== (R->elements[j+1]->CAS_POS))
        {if((R->elements[j]->GUERISONS)> (R->elements[j+1]->GUERISONS))
            {permuter(R->elements[j],R->elements[j+1]);}
              else {if((R->elements[j]->GUERISONS)==(R->elements[j+1]->GUERISONS))
                      {if((R->elements[j]->NB_VACCINES)> (R->elements[j+1]->NB_VACCINES))
                          { permuter(R->elements[j],R->elements[j+1]);}
                            else {if ((R->elements[j]->NB_VACCINES)== (R->elements[j+1]->NB_VACCINES))
                                    {if((R->elements[j]->DECES)> (R->elements[j+1]->DECES))
                                                       permuter(R->elements[j],R->elements[j+1]);
                                                        }}
                           }}
    }}}
}

}
else{
    if ((prior_1==1)&&(prior_2==4)&&(prior_3==3)&&(prior_4==2))

{for(i=1;i<R->LONG;i++)
{for(j=1;j<R->LONG;j++){
if((R->elements[j]->CAS_POS)> (R->elements[j+1]->CAS_POS))

{permuter(R->elements[j],R->elements[j+1]);}
else {if((R->elements[j]->CAS_POS)== (R->elements[j+1]->CAS_POS))
        {if((R->elements[j]->NB_VACCINES)> (R->elements[j+1]->NB_VACCINES))
            {permuter(R->elements[j],R->elements[j+1]);}
              else {if((R->elements[j]->NB_VACCINES)==(R->elements[j+1]->NB_VACCINES))
                      {if((R->elements[j]->GUERISONS)> (R->elements[j+1]->GUERISONS))
                          { permuter(R->elements[j],R->elements[j+1]);}
                            else {if ((R->elements[j]->GUERISONS)== (R->elements[j+1]->GUERISONS))
                                    {if((R->elements[j]->DECES)> (R->elements[j+1]->DECES))
                                                       permuter(R->elements[j],R->elements[j+1]);
                                                        }}
                           }}
    }}}
}

}

else{
if ((prior_1==2)&&(prior_2==1)&&(prior_3==3)&&(prior_4==4))

{for(i=1;i<R->LONG;i++)
{for(j=1;j<R->LONG;j++){
if((R->elements[j]->DECES)> (R->elements[j+1]->DECES))

{permuter(R->elements[j],R->elements[j+1]);}
else {if((R->elements[j]->DECES)== (R->elements[j+1]->DECES))
        {if((R->elements[j]->CAS_POS)> (R->elements[j+1]->CAS_POS))
            {permuter(R->elements[j],R->elements[j+1]);}
              else {if((R->elements[j]->CAS_POS)==(R->elements[j+1]->CAS_POS))
                      {if((R->elements[j]->GUERISONS)> (R->elements[j+1]->GUERISONS))
                          { permuter(R->elements[j],R->elements[j+1]);}
                            else {if ((R->elements[j]->GUERISONS)== (R->elements[j+1]->GUERISONS))
                                    {if((R->elements[j]->NB_VACCINES)> (R->elements[j+1]->NB_VACCINES))
                                                       permuter(R->elements[j],R->elements[j+1]);
                                                        }}
                           }}
    }}}
}

}
else { if ((prior_1==2)&&(prior_2==1)&&(prior_3==4)&&(prior_4==3))

{for(i=1;i<R->LONG;i++)
{for(j=1;j<R->LONG;j++){
if((R->elements[j]->DECES)> (R->elements[j+1]->DECES))

{permuter(R->elements[j],R->elements[j+1]);}
else {if((R->elements[j]->DECES)== (R->elements[j+1]->DECES))
        {if((R->elements[j]->CAS_POS)> (R->elements[j+1]->CAS_POS))
            {permuter(R->elements[j],R->elements[j+1]);}
              else {if((R->elements[j]->CAS_POS)==(R->elements[j+1]->CAS_POS))
                      {if((R->elements[j]->NB_VACCINES)> (R->elements[j+1]->NB_VACCINES))
                          { permuter(R->elements[j],R->elements[j+1]);}
                            else {if ((R->elements[j]->NB_VACCINES)== (R->elements[j+1]->NB_VACCINES))
                                    {if((R->elements[j]->GUERISONS)> (R->elements[j+1]->GUERISONS))
                                                       permuter(R->elements[j],R->elements[j+1]);
                                                        }}
                           }}
    }}}
}

}
else{
        if ((prior_1==3)&&(prior_2==1)&&(prior_3==2)&&(prior_4==4))

{for(i=1;i<R->LONG;i++)
{for(j=1;j<R->LONG;j++){
if((R->elements[j]->DECES)> (R->elements[j+1]->DECES))

{permuter(R->elements[j],R->elements[j+1]);}
else {if((R->elements[j]->DECES)== (R->elements[j+1]->DECES))
        {if((R->elements[j]->GUERISONS)> (R->elements[j+1]->GUERISONS))
            {permuter(R->elements[j],R->elements[j+1]);}
              else {if((R->elements[j]->GUERISONS)==(R->elements[j+1]->GUERISONS))
                      {if((R->elements[j]->CAS_POS)> (R->elements[j+1]->CAS_POS))
                          { permuter(R->elements[j],R->elements[j+1]);}
                            else {if ((R->elements[j]->CAS_POS)== (R->elements[j+1]->CAS_POS))
                                    {if((R->elements[j]->NB_VACCINES)> (R->elements[j+1]->NB_VACCINES))
                                                       permuter(R->elements[j],R->elements[j+1]);
                                                        }}
                           }}
    }}}
}

}
 else { if ((prior_1==4)&&(prior_2==1)&&(prior_3==2)&&(prior_4==3))

{for(i=1;i<R->LONG;i++)
{for(j=1;j<R->LONG;j++){
if((R->elements[j]->DECES)> (R->elements[j+1]->DECES))

{permuter(R->elements[j],R->elements[j+1]);}
else {if((R->elements[j]->DECES)== (R->elements[j+1]->DECES))
        {if((R->elements[j]->GUERISONS)> (R->elements[j+1]->GUERISONS))
            {permuter(R->elements[j],R->elements[j+1]);}
              else {if((R->elements[j]->GUERISONS)==(R->elements[j+1]->GUERISONS))
                      {if((R->elements[j]->NB_VACCINES)> (R->elements[j+1]->NB_VACCINES))
                          { permuter(R->elements[j],R->elements[j+1]);}
                            else {if ((R->elements[j]->NB_VACCINES)== (R->elements[j+1]->NB_VACCINES))
                                    {if((R->elements[j]->CAS_POS)> (R->elements[j+1]->CAS_POS))
                                                       permuter(R->elements[j],R->elements[j+1]);
                                                        }}
                           }}
    }}}
}

}
else{
    if ((prior_1==3)&&(prior_2==1)&&(prior_3==4)&&(prior_4==2))

{for(i=1;i<R->LONG;i++)
{for(j=1;j<R->LONG;j++){
if((R->elements[j]->DECES)>(R->elements[j+1]->DECES))

{permuter(R->elements[j],R->elements[j+1]);}
else {if((R->elements[j]->DECES)== (R->elements[j+1]->DECES))
        {if((R->elements[j]->NB_VACCINES)> (R->elements[j+1]->NB_VACCINES))
            {permuter(R->elements[j],R->elements[j+1]);}
              else {if((R->elements[j]->NB_VACCINES)==(R->elements[j+1]->NB_VACCINES))
                      {if((R->elements[j]->CAS_POS)> (R->elements[j+1]->CAS_POS))
                          { permuter(R->elements[j],R->elements[j+1]);}
                            else {if ((R->elements[j]->CAS_POS)== (R->elements[j+1]->CAS_POS))
                                    {if((R->elements[j]->GUERISONS)> (R->elements[j+1]->GUERISONS))
                                                       permuter(R->elements[j],R->elements[j+1]);
                                                        }}
                           }}
    }}}
}

}
else{
    if ((prior_1==4)&&(prior_2==1)&&(prior_3==3)&&(prior_4==2))

{for(i=1;i<R->LONG;i++)
{for(j=1;j<R->LONG;j++){
if((R->elements[j]->DECES)> (R->elements[j+1]->DECES))

{permuter(R->elements[j],R->elements[j+1]);}
else {if((R->elements[j]->DECES)== (R->elements[j+1]->DECES))
        {if((R->elements[j]->NB_VACCINES)> (R->elements[j+1]->NB_VACCINES))
            {permuter(R->elements[j],R->elements[j+1]);}
              else {if((R->elements[j]->NB_VACCINES)==(R->elements[j+1]->NB_VACCINES))
                      {if((R->elements[j]->GUERISONS)> (R->elements[j+1]->GUERISONS))
                          { permuter(R->elements[j],R->elements[j+1]);}
                            else {if ((R->elements[j]->GUERISONS)== (R->elements[j+1]->GUERISONS))
                                    {if((R->elements[j]->CAS_POS)> (R->elements[j+1]->CAS_POS))
                                                       permuter(R->elements[j],R->elements[j+1]);
                                                        }}
                           }}
    }}}
}

}
else{
if ((prior_1==2)&&(prior_2==3)&&(prior_3==1)&&(prior_4==4))

{for(i=1;i<R->LONG;i++)
{for(j=1;j<R->LONG;j++){
if((R->elements[j]->GUERISONS)> (R->elements[j+1]->GUERISONS))

{permuter(R->elements[j],R->elements[j+1]);}
else {if((R->elements[j]->GUERISONS)== (R->elements[j+1]->GUERISONS))
        {if((R->elements[j]->CAS_POS)> (R->elements[j+1]->CAS_POS))
            {permuter(R->elements[j],R->elements[j+1]);}
              else {if((R->elements[j]->CAS_POS)==(R->elements[j+1]->CAS_POS))
                      {if((R->elements[j]->DECES)> (R->elements[j+1]->DECES))
                          { permuter(R->elements[j],R->elements[j+1]);}
                            else {if ((R->elements[j]->DECES)== (R->elements[j+1]->DECES))
                                    {if((R->elements[j]->NB_VACCINES)> (R->elements[j+1]->NB_VACCINES))
                                                       permuter(R->elements[j],R->elements[j+1]);
                                                        }}
                           }}
    }}}
}

}
else { if ((prior_1==2)&&(prior_2==4)&&(prior_3==1)&&(prior_4==3))

{for(i=1;i<R->LONG;i++)
{for(j=1;j<R->LONG;j++){
if((R->elements[j]->GUERISONS)> (R->elements[j+1]->GUERISONS))

{permuter(R->elements[j],R->elements[j+1]);}
else {if((R->elements[j]->GUERISONS)== (R->elements[j+1]->GUERISONS))
        {if((R->elements[j]->CAS_POS)> (R->elements[j+1]->CAS_POS))
            {permuter(R->elements[j],R->elements[j+1]);}
              else {if((R->elements[j]->CAS_POS)==(R->elements[j+1]->CAS_POS))
                      {if((R->elements[j]->NB_VACCINES)> (R->elements[j+1]->NB_VACCINES))
                          { permuter(R->elements[j],R->elements[j+1]);}
                            else {if ((R->elements[j]->NB_VACCINES)== (R->elements[j+1]->NB_VACCINES))
                                    {if((R->elements[j]->DECES)> (R->elements[j+1]->DECES))
                                                       permuter(R->elements[j],R->elements[j+1]);
                                                        }}
                           }}
    }}}
}

}
else{
        if ((prior_1==3)&&(prior_2==2)&&(prior_3==1)&&(prior_4==4))

{for(i=1;i<R->LONG;i++)
{for(j=1;j<R->LONG;j++){
if((R->elements[j]->GUERISONS)> (R->elements[j+1]->GUERISONS))

{permuter(R->elements[j],R->elements[j+1]);}
else {if((R->elements[j]->GUERISONS)== (R->elements[j+1]->GUERISONS))
        {if((R->elements[j]->DECES)> (R->elements[j+1]->DECES))
            {permuter(R->elements[j],R->elements[j+1]);}
              else {if((R->elements[j]->DECES)==(R->elements[j+1]->DECES))
                      {if((R->elements[j]->CAS_POS)> (R->elements[j+1]->CAS_POS))
                          { permuter(R->elements[j],R->elements[j+1]);}
                            else {if ((R->elements[j]->CAS_POS)== (R->elements[j+1]->CAS_POS))
                                    {if((R->elements[j]->NB_VACCINES)> (R->elements[j+1]->NB_VACCINES))
                                                       permuter(R->elements[j],R->elements[j+1]);
                                                        }}
                           }}
    }}}
}

}
 else { if ((prior_1==4)&&(prior_2==2)&&(prior_3==1)&&(prior_4==3))

{for(i=1;i<R->LONG;i++)
{for(j=1;j<R->LONG;j++){
if((R->elements[j]->GUERISONS)> (R->elements[j+1]->GUERISONS))

{permuter(R->elements[j],R->elements[j+1]);}
else {if((R->elements[j]->GUERISONS)== (R->elements[j+1]->GUERISONS))
        {if((R->elements[j]->DECES)> (R->elements[j+1]->DECES))
            {permuter(R->elements[j],R->elements[j+1]);}
              else {if((R->elements[j]->DECES)==(R->elements[j+1]->DECES))
                      {if((R->elements[j]->NB_VACCINES)> (R->elements[j+1]->NB_VACCINES))
                          { permuter(R->elements[j],R->elements[j+1]);}
                            else {if ((R->elements[j]->NB_VACCINES)== (R->elements[j+1]->NB_VACCINES))
                                    {if((R->elements[j]->CAS_POS)> (R->elements[j+1]->CAS_POS))
                                                       permuter(R->elements[j],R->elements[j+1]);
                                                        }}
                           }}
    }}}
}

}
else{
    if ((prior_1==3)&&(prior_2==4)&&(prior_3==1)&&(prior_4==2))

{for(i=1;i<R->LONG;i++)
{for(j=1;j<R->LONG;j++){
if((R->elements[j]->GUERISONS)> (R->elements[j+1]->GUERISONS))

{permuter(R->elements[j],R->elements[j+1]);}
else {if((R->elements[j]->GUERISONS)== (R->elements[j+1]->GUERISONS))
        {if((R->elements[j]->NB_VACCINES)> (R->elements[j+1]->NB_VACCINES))
            {permuter(R->elements[j],R->elements[j+1]);}
              else {if((R->elements[j]->NB_VACCINES)==(R->elements[j+1]->NB_VACCINES))
                      {if((R->elements[j]->CAS_POS)> (R->elements[j+1]->CAS_POS))
                          { permuter(R->elements[j],R->elements[j+1]);}
                            else {if ((R->elements[j]->CAS_POS)== (R->elements[j+1]->CAS_POS))
                                    {if((R->elements[j]->DECES)> (R->elements[j+1]->DECES))
                                                       permuter(R->elements[j],R->elements[j+1]);
                                                        }}
                           }}
    }}}
}

}
else{
    if ((prior_1==4)&&(prior_2==3)&&(prior_3==1)&&(prior_4==2))

{for(i=1;i<R->LONG;i++)
{for(j=1;j<R->LONG;j++){
if((R->elements[j]->GUERISONS)> (R->elements[j+1]->GUERISONS))

{permuter(R->elements[j],R->elements[j+1]);}
else {if((R->elements[j]->GUERISONS)== (R->elements[j+1]->GUERISONS))
        {if((R->elements[j]->NB_VACCINES)> (R->elements[j+1]->NB_VACCINES))
            {permuter(R->elements[j],R->elements[j+1]);}
              else {if((R->elements[j]->NB_VACCINES)==(R->elements[j+1]->NB_VACCINES))
                      {if((R->elements[j]->DECES)> (R->elements[j+1]->DECES))
                          { permuter(R->elements[j],R->elements[j+1]);}
                            else {if ((R->elements[j]->DECES)== (R->elements[j+1]->DECES))
                                    {if((R->elements[j]->CAS_POS)> (R->elements[j+1]->CAS_POS))
                                                       permuter(R->elements[j],R->elements[j+1]);
                                                        }}
                           }}
    }}}
}

}
else{
if ((prior_1==2)&&(prior_2==3)&&(prior_3==4)&&(prior_4==1))

{for(i=1;i<R->LONG;i++)
{for(j=1;j<R->LONG;j++){
if((R->elements[j]->NB_VACCINES)> (R->elements[j+1]->NB_VACCINES))

{permuter(R->elements[j],R->elements[j+1]);}
else {if((R->elements[j]->NB_VACCINES)== (R->elements[j+1]->NB_VACCINES))
        {if((R->elements[j]->CAS_POS)> (R->elements[j+1]->CAS_POS))
            {permuter(R->elements[j],R->elements[j+1]);}
              else {if((R->elements[j]->CAS_POS)==(R->elements[j+1]->CAS_POS))
                      {if((R->elements[j]->DECES)> (R->elements[j+1]->DECES))
                          { permuter(R->elements[j],R->elements[j+1]);}
                            else {if ((R->elements[j]->DECES)== (R->elements[j+1]->DECES))
                                    {if((R->elements[j]->GUERISONS)> (R->elements[j+1]->GUERISONS))
                                                       permuter(R->elements[j],R->elements[j+1]);
                                                        }}
                           }}
    }}}
}

}
else { if ((prior_1==3)&&(prior_2==2)&&(prior_3==4)&&(prior_4==1))

{for(i=1;i<R->LONG;i++)
{for(j=1;j<R->LONG;j++){
if((R->elements[j]->NB_VACCINES)> (R->elements[j+1]->NB_VACCINES))

{permuter(R->elements[j],R->elements[j+1]);}
else {if((R->elements[j]->NB_VACCINES)== (R->elements[j+1]->NB_VACCINES))
        {if((R->elements[j]->DECES)> (R->elements[j+1]->DECES))
            {permuter(R->elements[j],R->elements[j+1]);}
              else {if((R->elements[j]->DECES)==(R->elements[j+1]->DECES))
                      {if((R->elements[j]->CAS_POS)> (R->elements[j+1]->CAS_POS))
                          { permuter(R->elements[j],R->elements[j+1]);}
                            else {if ((R->elements[j]->CAS_POS)== (R->elements[j+1]->CAS_POS))
                                    {if((R->elements[j]->GUERISONS)> (R->elements[j+1]->GUERISONS))
                                                       permuter(R->elements[j],R->elements[j+1]);
                                                        }}
                           }}
    }}}
}

}
else{
        if ((prior_1==4)&&(prior_2==2)&&(prior_3==3)&&(prior_4==1))

{for(i=1;i<R->LONG;i++)
{for(j=1;j<R->LONG;j++){
if((R->elements[j]->NB_VACCINES)> (R->elements[j+1]->NB_VACCINES))

{permuter(R->elements[j],R->elements[j+1]);}
else {if((R->elements[j]->NB_VACCINES)== (R->elements[j+1]->NB_VACCINES))
        {if((R->elements[j]->DECES)> (R->elements[j+1]->DECES))
            {permuter(R->elements[j],R->elements[j+1]);}
              else {if((R->elements[j]->DECES)==(R->elements[j+1]->DECES))
                      {if((R->elements[j]->GUERISONS)> (R->elements[j+1]->GUERISONS))
                          { permuter(R->elements[j],R->elements[j+1]);}
                            else {if ((R->elements[j]->GUERISONS)== (R->elements[j+1]->GUERISONS))
                                    {if((R->elements[j]->CAS_POS)> (R->elements[j+1]->CAS_POS))
                                                       permuter(R->elements[j],R->elements[j+1]);
                                                        }}
                           }}
    }}}
}

}
 else { if ((prior_1==3)&&(prior_2==4)&&(prior_3==2)&&(prior_4==1))

{for(i=1;i<R->LONG;i++)
{for(j=1;j<R->LONG;j++){
if((R->elements[j]->NB_VACCINES)> (R->elements[j+1]->NB_VACCINES))

{permuter(R->elements[j],R->elements[j+1]);}
else {if((R->elements[j]->NB_VACCINES)== (R->elements[j+1]->NB_VACCINES))
        {if((R->elements[j]->GUERISONS)> (R->elements[j+1]->GUERISONS))
            {permuter(R->elements[j],R->elements[j+1]);}
              else {if((R->elements[j]->GUERISONS)==(R->elements[j+1]->GUERISONS))
                      {if((R->elements[j]->CAS_POS)> (R->elements[j+1]->CAS_POS))
                          { permuter(R->elements[j],R->elements[j+1]);}
                            else {if ((R->elements[j]->CAS_POS)== (R->elements[j+1]->CAS_POS))
                                    {if((R->elements[j]->DECES)> (R->elements[j+1]->DECES))
                                                       permuter(R->elements[j],R->elements[j+1]);
                                                        }}
                           }}
    }}}
}

}
else{
    if ((prior_1==4)&&(prior_2==3)&&(prior_3==2)&&(prior_4==1))

{for(i=1;i<R->LONG;i++)
{for(j=1;j<R->LONG;j++){
if((R->elements[j]->NB_VACCINES)> (R->elements[j+1]->NB_VACCINES))

{permuter(R->elements[j],R->elements[j+1]);}
else {if((R->elements[j]->NB_VACCINES)== (R->elements[j+1]->NB_VACCINES))
        {if((R->elements[j]->GUERISONS)> (R->elements[j+1]->GUERISONS))
            {permuter(R->elements[j],R->elements[j+1]);}
              else {if((R->elements[j]->GUERISONS)==(R->elements[j+1]->GUERISONS))
                      {if((R->elements[j]->DECES)> (R->elements[j+1]->DECES))
                          { permuter(R->elements[j],R->elements[j+1]);}
                            else {if ((R->elements[j]->DECES)== (R->elements[j+1]->DECES))
                                    {if((R->elements[j]->CAS_POS)> (R->elements[j+1]->CAS_POS))
                                                       permuter(R->elements[j],R->elements[j+1]);
                                                        }}
                           }}
    }}}
}

}
else{
    if ((prior_1==2)&&(prior_2==4)&&(prior_3==3)&&(prior_4==1))

{for(i=1;i<R->LONG;i++)
{for(j=1;j<R->LONG;j++){
if((R->elements[j]->NB_VACCINES)> (R->elements[j+1]->NB_VACCINES))

{permuter(R->elements[j],R->elements[j+1]);}
else {if((R->elements[j]->NB_VACCINES)== (R->elements[j+1]->NB_VACCINES))
        {if((R->elements[j]->CAS_POS)> (R->elements[j+1]->CAS_POS))
            {permuter(R->elements[j],R->elements[j+1]);}
              else {if((R->elements[j]->CAS_POS)==(R->elements[j+1]->CAS_POS))
                      {if((R->elements[j]->GUERISONS)> (R->elements[j+1]->GUERISONS))
                          { permuter(R->elements[j],R->elements[j+1]);}
                            else {if ((R->elements[j]->GUERISONS)== (R->elements[j+1]->GUERISONS))
                                    {if((R->elements[j]->DECES)> (R->elements[j+1]->DECES))
                                                       permuter(R->elements[j],R->elements[j+1]);
                                                        }}
                           }}
    }}}
}

}
}}}}}}}}}}}}}}}}}}}}}}} // elseeeet



}
}



printf("  GOUVERNORAT      DATE     CAS POSITIFS  GUERISONS  DECES  VACCINES \n");
for(i=1;i<=(R->LONG);i++)
{
    AfficherElement(R->elements[i]);

}

}
int dateComparer(DATE d1, DATE d2)
{
   if((( d2.annee) - (d1.annee)==0)&&((d2.mois) - (d1.mois) ==0)&&((d2.jour) - (d1.jour) ==0)) return( 0 );
else return(-1);
}
void permuter (ELEMENT x,ELEMENT y)
{ ELEMENT e= elementCreer();
elementCopier(&e,x);
elementCopier(&x,y);
elementCopier(&y,e);

}
