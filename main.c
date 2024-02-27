/*
Name            :   Rubar Mohammad
Studiengruppe   :   23/041/01
Matrikelnummer  :   55195
Bib.nummer      :   s87453
*/

#include <stdio.h>
#include <stdlib.h>
#include "medium.h"

int main() {
    struct Medium medien[100];  // Annahme: maximal 100 Medien
    int anzahlMedien = 0;
    int auswahl;
    char auswahlStr[3];

    ladenAusCSV(medien, &anzahlMedien); // Daten aus der CSV-Datei laden

    do {
        // Menü anzeigen
        printf("\nMedienverwaltung:\n");
        printf("1. Medium hinzufuegen\n");
        printf("2. Medium oder leihende Person suchen\n");
        printf("3. Medium entfernen (nach Rueckgabe)\n");
        printf("4. Beenden\n");
        printf("Auswahl treffen (1-4): ");
        fgets(auswahlStr, 3, stdin);
        auswahl = atoi(auswahlStr);

        switch (auswahl) {
            case 1:
                // Medium hinzufügen
                mediumHinzufuegen(medien, &anzahlMedien);
                break;
            case 2:
                // Medium oder leihende Person suchen
                mediumSuchen(medien, anzahlMedien);
                break;
            case 3:
                // Medium entfernen (nach Rückgabe)
                mediumEntfernen(medien, &anzahlMedien);
                break;
            case 4:
                // Programm beenden
                printf("Programm wird beendet.\n");
                break;
            default:
                // Ungültige Eingabe
                printf("Ungueltige Eingabe. Bitte eine Zahl von 1 bis 4 eingeben.\n");
        }
    } while (auswahl != 4);

    return 0;
}
