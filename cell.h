//
// Created by moind on 21/11/2024.
//

#ifndef CC_CELL_H
#define CC_CELL_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// structure pour les cellules d'une liste
struct s_cell
{
    struct s_cell *prec;
    int val;
    struct s_cell *next;
};
typedef struct s_cell t_cell, *p_cell;

/***
 * @brief display a t_cell struct
 * @param t_cell : cell to display
 * @return : void
 */
void displayCell(t_cell);

/***
 * @brief create a cell, and return a pointer to
 * @param int value
 * @return pointer to cell, whit a value, and next is NULL
 */
p_cell createCell(int);

// Supprime une cellule
void deleteCell(p_cell);

#endif //CC_CELL_H
