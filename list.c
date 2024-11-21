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

// Retire un élement de la liste
int removeValFromList(LIST* std, int val)
{
    int remove = 0;
    if (std->head == NULL) {
        return 0;
    }


    if (std->head->value == val) {
        if (std->head->next != NULL) {
            std->head = std->head->next;
        }
        else {
            std->head = NULL;
        }
        return 0;
    }
    
    p_cell tmp = std->head;
    p_cell pre_tmp;
    pre_tmp = tmp;
    tmp = tmp->next;
    while (tmp != NULL) {
        if (tmp->value == val) {
            pre_tmp->next = tmp->next;
            free(tmp);
            return 1;
        }
        pre_tmp = tmp;
        tmp = tmp->next;
    }
    return 0;
    
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

int isEmptyStdList(LIST list) {
    int res = 0;
    if (list.head == NULL) {
        res = 1;
    }
    return res;
}


// --------------------------------------------------------------------------------------------------



int isValInHtList(HTLIST list, int value) {
    t_cell* temp = list.head;
    int found = 0;
    while ((temp != NULL) && found == 0) {
        if (temp->value == value) {
            found = 1;
        }
        temp = temp->next;
    }
    return found;
}

void removeValFromHtList(HTLIST* list, int value) {
    t_cell* temp = list->head;
    t_cell* prev = NULL;

    if (list->head->value == value) {
        list->head = list->head->next;
    } else {
        int done = 0;
        while ((temp != NULL) && (done == 0)) {
            if (temp->value == value) {
                prev->next = temp->next;
                done = 1;
            }
            prev = temp;
            temp = temp->next;
        }
    }
}

void addTailHt(HTLIST* list, int value) {
    t_cell* newcell = createCell(value);
    if (list->head == NULL) {
        list->head = newcell;
        list->tail = newcell;
    } else {
        list->tail->next = newcell;
        list->tail = newcell;
    }
}




// ------------------------------------------------------------------------------------

CIRCLIST createEmptyCircList()
{
    CIRCLIST cl;
    cl.head = NULL;
    cl.tail = NULL;

    return cl;
}

void addHeadCircList(CIRCLIST * list, int value) {
    t_cell* newcell = createCell(value);
    if (list->head == NULL) {
        list->head = newcell;
        list->tail = newcell;
        list->tail->next = list->head;
    } else {
        newcell->next = list->head;
        list->tail->next = newcell;
        list->tail = newcell;
    }
}