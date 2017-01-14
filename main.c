#include <stdio.h>
#include <stdlib.h>

/* Krzysztof Kosecki, 18.01.2017, wersja C */

struct point {
    int row;
    int col;
    double value;
    struct point* next;
};

struct limits {
    struct point* minValue;
    struct point* maxValue;
};

struct point* rewrite(double tab[][5], int rows, int cols) {
    /* Funkcja bierze wskaznik na pierwszy element tablicy, tworzy liste i przepisuje ka¿dy niezerowy element tablicy
        jako nowy node z polami i,j,t[i][j] */
    /*double (*array)[rows] = tab; VLA, mamy tego nie uzywac */

    int i,j;
    struct point* head = NULL;
    struct point* newNode;

    for(i=0;i<rows;i++) {
        for(j=0;j<cols;j++) {

            if(tab[i][j] != 0) {
                    /* tutaj funkcja tworzy nowy node, wpisuje tam i,j i t[i][j] */
                    newNode = (struct point*)malloc(sizeof(struct point));
                    newNode->row = i;
                    newNode->col = j;
                    newNode->value = tab[i][j];
                    /* wpinanie tego nowego node'a: */
                    newNode->next = head;
                    head = newNode;
            }
        }
    }
    return head;
}

void displayList(struct point* head) {
    while(head != NULL) {

        printf("Wiersz: %d\n",head->row);
        printf("Kolumna: %d\n",head->col);
        printf("Wartosc: %f\n",head->value);
        printf("\n");
        head = head->next;
    }
}

struct limits findLimits(struct point* head) {
    struct limits listLimits;
    double minValue = 10000;
    double maxValue = 0;

    while(head != NULL) {
        if(head->value < minValue) {
            listLimits.minValue = head;
            minValue = head->value;
        }
        if(head->value > maxValue) {
            listLimits.maxValue = head;
            maxValue = head->value;
        }
        head = head->next;
    }
    return listLimits;
}

int main(void) {

    /* Przykladowa tablica do testow: */

    double tab[5][5] = {
        {2,0,0,0,5},
        {0,3,2,1,0},
        {1,3,0,0,4},
        {0,4,0,4,0},
        {0,1,0,0,0}
    };

    struct point* head; /* wskaznik na poczatek listy */
    struct limits listLimits;

    head = rewrite(tab,5,5);
    displayList(head);
    listLimits = findLimits(head);
    printf("Element minimalny: \n");
    printf("Wiersz: %d\n",listLimits.minValue->row);
    printf("Kolumna: %d\n",listLimits.minValue->col);
    printf("Wartosc: %f\n",listLimits.minValue->value);
    printf("Element maksymalny: \n");

    printf("Wiersz: %d\n",listLimits.maxValue->row);
    printf("Kolumna: %d\n",listLimits.maxValue->col);
    printf("Wartosc: %f\n",listLimits.maxValue->value);
    /* czy zwalniac pamiec przed wyjsciem z programu? */
    return 0;
}
