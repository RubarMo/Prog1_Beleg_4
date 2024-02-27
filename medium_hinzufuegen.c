/*
Name            :   Rubar Mohammad
Studiengruppe   :   23/041/01
Matrikelnummer  :   55195
Bib.nummer      :   s87453
*/

#include "medium.h"
#include <stdio.h>
#include <string.h>

void mediumHinzufuegen(struct Medium *medien, int *anzahlMedien)
{
    printf("Name des Mediums: ");
    fgets(medien[*anzahlMedien].name, 100, stdin);
    medien[*anzahlMedien].name[strcspn(medien[*anzahlMedien].name, "\n")] = 0;  // remove newline at the end

    printf("Autor (leer lassen, wenn nicht zutreffend): ");
    fgets(medien[*anzahlMedien].autor, 100, stdin);
    medien[*anzahlMedien].autor[strcspn(medien[*anzahlMedien].autor, "\n")] = 0;  // remove newline at the end

    printf("Leihende Person: ");
    fgets(medien[*anzahlMedien].leihendePerson, 100, stdin);
    medien[*anzahlMedien].leihendePerson[strcspn(medien[*anzahlMedien].leihendePerson, "\n")] = 0;  // remove newline at the end

    (*anzahlMedien)++;

    speichernInCSV(medien, *anzahlMedien);
}
