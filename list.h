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

void addTailList(LIST* list, int val);

void displayHList(LIST list);

// Supprimer un éléments de la liste
void Deleteelt(LIST* list, int val);

// Créer une nouvelle liste sans un élément donné
LIST* removeElt(LIST list, int val);

// Retire une valeur de la liste
int removeValFromList(LIST*, int);

// Création d'une liste vide
LIST* createListEmpty();

int countVal(LIST, int);

void addHeadStd(LIST *, int);

int findElt(LIST list, int nb);

int isEltInList(LIST list, int val);

int isEmptyStdList(LIST list);



// --------------------------------------------------------------


typedef struct s_ht_list
{
    t_cell *head;
    t_cell *tail;
} HTLIST;

int isValInHtList(HTLIST list, int value);

void removeValFromHtList(HTLIST* list, int value);

void addTailHt(HTLIST* list, int value);



// ----------------------------------------------------------------

typedef HTLIST CIRCLIST;

CIRCLIST createEmptyCircList();

void addHeadCircList(CIRCLIST * list, int value);

#endif //CC_LIST_H
