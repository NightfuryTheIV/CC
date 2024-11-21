//
// Created by moind on 21/11/2024.
//

#ifndef CC_LIST_H
#define CC_LIST_H

#include "cell.h"


typedef struct s_std_list
{
    p_cell head;
} LIST;

// Ajouter une cellule en fin de liste
void addTailList(LIST* list, int val);

// Fonction d'affichage de la liste
void displayHList(LIST list);

// Supprimer un éléments de la liste
void Deleteelt(LIST* list, int val);

// Créer une nouvelle liste sans un élément donné
LIST* removeElt(LIST list, int val);

// Création d'une liste vide
LIST* createListEmpty();

// Fonction qui compte le nombre d'élément dans une liste
int countEltHList(LIST list);

// Trouver un élément en fonction de sa place dans la liste
int findElt(LIST list, int nb);

int isEltInList(LIST list, int val);

#endif //CC_LIST_H
