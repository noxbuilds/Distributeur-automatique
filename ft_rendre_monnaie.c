#include <unistd.h>
#include "distributeur.h"

void ft_rendre_monnaie(int montant)
{
    const int pieces[8] = {200, 100, 50, 20, 10, 5, 2, 1};
    int i;
    int nombre;

    if (montant == 0)
    {
        write(1, "Rien a rendre\n", sizeof("Rien a rendre\n") - 1);
        return;
    }
    i = 0;
    while (i < 8)
    {
        nombre = montant / pieces[i];
        if (nombre > 0)
        {
            write(1, "  ", 2);
            afficher_entier(nombre);
            write(1, " x ", 3);
            afficher_entier(pieces[i]);
            write(1, "c\n", 2);
            montant = montant % pieces[i];
        }
        i++;
    }
}

