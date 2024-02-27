/*
Name            :   Rubar Mohammad
Studiengruppe   :   23/041/01
Matrikelnummer  :   55195
Bib.nummer      :   s87453
*/

#include "medium.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void speichernInCSV(struct Medium *medien, int anzahlMedien) {
    FILE *fp = fopen("data.csv", "w");
    if (fp == NULL) {
        printf("Fehler beim Öffnen der Datei zum Schreiben.\n");
        return;
    }

    for (int i = 0; i < anzahlMedien; i++) {
        fprintf(fp, "%s,%s,%s\n", medien[i].name, medien[i].autor, medien[i].leihendePerson);
    }

    fclose(fp);
}

void ladenAusCSV(struct Medium *medien, int *anzahlMedien) {
    FILE *fp = fopen("data.csv", "r");
    if (fp == NULL) {
        printf("Fehler beim Öffnen der Datei zum Lesen.\n");
        return;
    }

    *anzahlMedien = 0;
    while (fscanf(fp, "%99[^,],%99[^,],%99[^\n]\n", medien[*anzahlMedien].name, medien[*anzahlMedien].autor, medien[*anzahlMedien].leihendePerson) == 3) {
        (*anzahlMedien)++;
    }

    fclose(fp);
}
