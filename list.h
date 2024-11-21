//
// Created by moind on 21/11/2024.
//

#ifndef CC_LIST_H
#define CC_LIST_H

#include "cell.h"


typedef struct s_std_list
{
    p_cell head;
} h_std_list;

// Ajouter une cellule en fin de liste
void addTailList(h_std_list* list, int val);

// Fonction d'affichage de la liste
void displayHList(h_std_list list);

// Supprimer un éléments de la liste
void Deleteelt(h_std_list* list, int val);

// Créer une nouvelle liste sans un élément donné
h_std_list* removeElt(h_std_list list, int val);

// Création d'une liste vide
h_std_list* createListEmpty();

// Fonction qui compte le nombre d'élément dans une liste
int countEltHList(h_std_list list);

// Ajouter une cellule au début de la liste
void addHeadStd(t_std_list *, int);

// Trouver un élément en fonction de sa place dans la liste
int findElt(h_std_list list, int nb);

int isEltInList(h_std_list list, int val);

#endif //CC_LIST_H
