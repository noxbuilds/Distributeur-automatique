#ifndef DISTRIBUTEUR_H
#define DISTRIBUTEUR_H

#include <unistd.h>

#define NOMBRE_PRODUITS 4
#define NOMBRE_PIECES 8

typedef struct produit
{
    char nom[16];
    int  prix;
    int  stock;
}   produit;

void  afficher_texte(char *texte);
void  afficher_entier(int nombre);
int   convertir_texte_en_nombre(char *texte);
void  ft_rendre_monnaie(int monnaie);



#endif // distributeur
