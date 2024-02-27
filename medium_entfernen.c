/*
Name            :   Rubar Mohammad
Studiengruppe   :   23/041/01
Matrikelnummer  :   55195
Bib.nummer      :   s87453
*/

#include "medium.h"
#include <stdio.h>
#include <string.h>

void mediumEntfernen(struct Medium *medien, int *anzahlMedien) {
    char mediumName[100];
    printf("Name des zurückgegebenen Mediums: ");
    fgets(mediumName, 100, stdin);
    mediumName[strcspn(mediumName, "\n")] = 0;  // remove newline at the end

    for (int i = 0; i < *anzahlMedien; i++) {
        if (strcmp(medien[i].name, mediumName) == 0) {
            // Medium gefunden, entfernen, indem es mit dem letzten Medium getauscht wird
            *anzahlMedien -= 1;
            medien[i] = medien[*anzahlMedien];
            printf("Medium '%s' wurde entfernt.\n", mediumName);
            speichernInCSV(medien, *anzahlMedien); // Update CSV after deletion
            return;
        }
    }

    printf("Medium '%s' wurde nicht gefunden.\n", mediumName);
}

