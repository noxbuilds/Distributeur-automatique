#include "distributeur.h"

void    afficher_texte(char *texte)
{
    int position;
    position = 0;
    while (texte[position] != '\0')
    {
        write (1, &texte[position], 1);
        position++;
    }
}
void    afficher_entier(int nombre)
{
    char chiffre;

    if (nombre >= 10)
        afficher_entier(nombre / 10);
    chiffre = nombre % 10 + '0';
    write(1, &chiffre, 1);
}
int convertir_texte_en_nombre(char *texte)
{
    int position;
    int nombre;

    if (texte[0] == '\0')
        return (-1);
    position =0;
    nombre = 0;
    while (texte[position] != '\0')
    {
    if (texte[position] < '0' || texte[position] > '9')
        return (-1);
    nombre = nombre * 10 + (texte[position] - '0');
    position++;
    }
    return (nombre);
}

int main(int nombre_arguments, char **arguments)
{
    produit catalogue[NOMBRE_PRODUITS] = {
        {"Cafe", 20, 2},
        {"The", 15, 0},
        {"Jus", 10, 10},
        {"Eau", 5, 18}
    };

   int montant;
   int choix;
   int i;

   if(nombre_arguments !=3 ){
    afficher_texte("Usage: ./distributeur.exe <montant> <choix>\n");
    return(1);
   }
   montant = convertir_texte_en_nombre(arguments[1]);
   choix = convertir_texte_en_nombre(arguments[2]);
   if(montant == -1 || choix == -1){
    afficher_texte("erreur: argument invalide\n");
    return(1);
   }
   afficher_texte("Catalogue\n");
   i = 0;
   while(i< NOMBRE_PRODUITS){
    afficher_entier(i + 1);
    afficher_texte(". ");
    afficher_texte(catalogue[i].nom);
    afficher_texte(" - ");
    afficher_entier(catalogue[i].prix);
    afficher_texte("c (stock: ");
    afficher_entier(catalogue[i].stock);
    afficher_texte(")\n");
    i++;
   }
   if(choix < 1 || choix > NOMBRE_PRODUITS){
    afficher_texte("Erreur: choix invalide\n");
    return(1);
   }
   if(catalogue[choix -1].stock == 0){
    afficher_texte("Erreur: produit epuiser\n");
    return(1);
   }
   if(montant < catalogue[choix -1].prix){
    afficher_texte("Erreur: montant insuffisant\n");
    return(1);
   }
   afficher_texte("Vous avez choisi: ");
   afficher_texte(catalogue[choix - 1].nom);
   afficher_texte("\nMonnaie rendu:\n");
   ft_rendre_monnaie(montant - catalogue[choix - 1].prix);
   return(0);
}
