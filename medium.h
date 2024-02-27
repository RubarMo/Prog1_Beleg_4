/*
Name            :   Rubar Mohammad
Studiengruppe   :   23/041/01
Matrikelnummer  :   55195
Bib.nummer      :   s87453
*/

#ifndef MEDIUM_H
#define MEDIUM_H

struct Medium {
    char name[100];
    char autor[100];
    char leihendePerson[100];
};

void mediumHinzufuegen(struct Medium *medien, int *anzahlMedien);
void mediumSuchen(struct Medium *medien, int anzahlMedien);
void mediumEntfernen(struct Medium *medien, int *anzahlMedien);
void speichernInCSV(struct Medium *medien, int anzahlMedien);
void ladenAusCSV(struct Medium *medien, int *anzahlMedien);

#endif
