#ifndef ELTINF_H_INCLUDED
#define ELTINF_H_INCLUDED
typedef struct {
int jour ;
int mois ;
int annee ;
} DATE;

typedef struct {
char Nom [20];
DATE dat ;
int CAS_POS;
int GUERISONS ;
int DECES ;
int NB_VACCINES ;

} information ,*ELEMENT ;


#endif // ELTINF_H_INCLUDED
