#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur für ein Medium
struct Medium {
    char name[100];
    char autor[100];
    char leihendePerson[100];
};

// Funktion zum Hinzufügen eines Mediums
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
}

// Funktion zum Suchen nach einem Medium oder einer leihenden Person
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

// Funktion zum Entfernen eines Mediums nach Rückgabe
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
            return;
        }
    }

    printf("Medium '%s' wurde nicht gefunden.\n", mediumName);
}

int main() {
    struct Medium medien[100];  // Annahme: maximal 100 Medien
    int anzahlMedien = 0;
    int auswahl;
    char auswahlStr[3];

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
