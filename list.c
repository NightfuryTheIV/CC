//
// Created by moind on 21/11/2024.
//

#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

// Ajouter une cellule en fin de liste
void addTailList(LIST* list, int val) {

    // Création de la nouvelle cellule
    p_cell new_cell = createCell(val);

    // Si la liste est vide ajout de la cellule en tête de liste
    if (list->head == NULL) {
        list->head = new_cell;
        return;
    } else {

        // Parcours de la liste jusqu'à la dernière cellule
        p_cell tmp = list->head;
        while(tmp->next != NULL) {
            tmp = tmp->next;
        }

        // Ajout de la cellule en fin de liste
        tmp->next = new_cell;
        new_cell->prev = tmp;
    }
}

// Ajouter une cellule en tête de liste
void addHeadStd(LIST * std, int val) {
    p_cell new_cell = createCell(val);
    new_cell->next = std->head;
    std->head = new_cell;
}

// Compte le nombre d'occurence d'une valeur dans la liste
int countVal(LIST list, int val) {
    int count = 0;
    p_cell tmp = list.head;
    while (tmp != NULL) {
        if (tmp->value == val) {
            count++;
        }
        tmp = tmp->next;
    }
    return count;
}

// Fonction d'affichage de la liste
void displayHList(LIST list) {

    p_cell tmp = list.head;
    printf("[");

    if (tmp != NULL) {

        // Parcours de la liste jusqu'à l'avant dernière cellule
        while(tmp->next != NULL) {

            // Affichage de la cellule
            displayCell(*tmp);
            printf(",");

            tmp = tmp->next;
        }

        // Affichage de la dernière cellule
        displayCell(*tmp);
    }
    printf("]");
}

// Supprimer un éléments de la liste
void Deleteelt(LIST* list, int val) {

    // Si la liste est vide
    if (list->head == NULL) {
        printf("Liste vide\n");
    } else {

        p_cell tmp = list->head;

        // Parcours de la liste jusqu'à la fin ou jusqu'à l'élément à supprimer
        while(tmp != NULL || tmp->value != val) {
            tmp = tmp->next;
        }

        // Suppression de l'élément
        tmp->prev->next = tmp->next;
        deleteCell(tmp);
        free(tmp);
    }
}

// Créer une nouvelle liste sans un élément donné
LIST* removeElt(LIST list, int val) {

    // Création de la nouvelle liste
    LIST* list2 = createListEmpty();

    int remove = 0;

    // Si la liste est vide
    if (list.head == NULL) {
        printf("Liste vide\n");
        return NULL;
    } else {
        p_cell tmp = list.head;

        // Parcours de la liste
        while(tmp != NULL) {

            // Ajout du mouvement si ce n'est pas celui donné
            if (tmp->value != val) {
                addTailList(list2, tmp->value);
            }

            // Ajout du mouvement si celui donné a déjà été supprimé
            if (remove == 1 && tmp->value == val) {
                addTailList(list2, tmp->value);
            }

            // N'ajoute pas le mouvement donné la première fois
            if (remove != 1 && tmp->value == val) {
                remove++;
            }

            tmp = tmp->next;
        }
    }

    // Renvoie la nouvelle liste sans l'élément donné
    return list2;
}

// Création d'une liste vide
LIST* createListEmpty() {

    // Allocation de la mémoire nécesaire à la création de la liste
    LIST* list = (LIST*)malloc(sizeof (LIST));
    list->head = NULL;
    return list;

}

// Fonction qui compte le nombre d'élément dans une liste
int countEltHList(LIST list) {

    p_cell tmp = list.head;
    int count = 0;

    // Parcours de la liste
    while(tmp != NULL) {

        // Augmentation du nombre d'élément
        count++;
        tmp = tmp->next;
    }

    return count;

}

// Trouver un élément en fonction de sa place dans la liste
int findElt(LIST list, int nb) {

    p_cell tmp = list.head;

    int count = 0;

    while(tmp != NULL && count < nb) {
        count++;
        tmp = tmp->next;
    }

    return tmp->value;

}

int isEltInList(LIST list, int val) {

    p_cell tmp = list.head;
    int is_elt_in_list = 0;

    // Parcours de la liste
    while(tmp != NULL && is_elt_in_list != 1) {

        if (tmp->value == val) {
            is_elt_in_list = 1;
        }

        tmp = tmp->next;
    }

    return is_elt_in_list;
}
