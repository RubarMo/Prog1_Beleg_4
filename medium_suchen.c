/*
Name            :   Rubar Mohammad
Studiengruppe   :   23/041/01
Matrikelnummer  :   55195
Bib.nummer      :   s87453
*/

#include "medium.h"
#include <stdio.h>
#include <string.h>

void mediumSuchen(struct Medium *medien, int anzahlMedien) {
    char suche[100];
    printf("Suchbegriff eingeben: ");
    fgets(suche, 100, stdin);
    suche[strcspn(suche, "\n")] = 0;  // remove newline at the end

    printf("\nSuchergebnisse:\n");
    printf("------------------------------------------------\n");

    for (int i = 0; i < anzahlMedien; i++) {
        if (strstr(medien[i].name, suche) || strstr(medien[i].autor, suche) ||
            strstr(medien[i].leihendePerson, suche)) {
            printf("%-20s %s\n", "Name:", medien[i].name);
            printf("%-20s %s\n", "Autor:", medien[i].autor);
            printf("%-20s %s\n", "Leihende Person:", medien[i].leihendePerson);
            printf("------------------------------------------------\n");
        }
    }
}
