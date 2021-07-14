#include <stdio.h>
#include <ctype.h>


int nbProduction; // nombre de régles
char production[25][25]; // matrice de productions ( [25] : 26 éléments : les alphabets )

// Fonction qui parcourt un tableau et met le caractére dedans s'il n'existe pas
void parcours_tableau(char tab[], char car) {
    int i;
    for (i = 0; tab[i] != '\0'; i++) {
        if (tab[i] == car)
            return;
    }
    tab[i] = car;
    tab[i + 1] = '\0';
}

// Axiome = production

// On va mettre l'ensemble des premiers de l'axiome passé en paramétres dans le tableau
void premier(char *tab, char car) {
    int cmpt, j, i;
    char temp[25];
    int x; // flag
    // Non terminaux
    if (!(isupper(car))) {
        parcours_tableau(tab, car);
        return;
    }
    // Boucle sur le nb de régles qu'on a
    for (cmpt = 0; cmpt < nbProduction; cmpt++) {
        if (production[cmpt][0] == car) {
            // Cas d'epsilon
            if (production[cmpt][3] == '$') {
                parcours_tableau(tab, '$');
            } else {
                j = 3;
                while (production[cmpt][j] != '\0') {
                    x = 0;
                    // Appel recursif pour le chercher le premier du non-terminal suivant dans la production
                    premier(temp, production[cmpt][j]);
                    for (i = 0; temp[i] != '\0'; i++) {
                        parcours_tableau(tab, temp[i]);
                    }
                    for (i = 0; temp[i] != '\0'; i++) {
                        if (temp[i] == '$') {
                            x = 1;
                            break;
                        }
                    }
                    if (!x) {
                        break;
                    }
                    j++;
                }
            }
        }

    }
}