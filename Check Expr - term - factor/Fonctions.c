

#include "Fonctions.h"
#include <ctype.h>

/*
 * An Expression is a  term | term + term
 * A Term is a factor | factor * factor
 * A Factor is a lettre | ( expr )
 *
 * @Parametrs : char * str : l'expression Algebraic sous forme de chaine de caracteres
 *
 *              int * ppos : position actuelle en parcourant la chaine pour vérifier les caractéres
 *
 * @Return : 1 for valid expression, term and factor ? 0 else
 */


int expr(char *str, int *ppos) {
    if (term(str, ppos) == 0) {
        return 0;
    }
    char c = str[*ppos];
    if (c != '+')
        return 1;
    (*ppos)++;
    return term(str, ppos);
}


int term(char *str, int *ppos) {

    if (factor(str, ppos) == 0) {
        return 0;
    }
    char c = str[*ppos];
    if (c != '*')
        return 1;
    (*ppos)++;
    return factor(str, ppos);
}


int factor(char *str, int *ppos) {
    char c = str[*ppos];
    if (c == 0)
        return 0;
    (*ppos)++;

    if (isalpha(c)) // lettre
        return 1;
    if (c == '(') { // (expr)
        if (expr(str, ppos)) {
            if (str[*ppos] == ')') {
                (*ppos)++;
                return 1;
            }
        } else { return 0; }
    }
    return 0;
}