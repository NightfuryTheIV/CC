//
// Created by moind on 21/11/2024.
//

#include "cell.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/***
 * @brief display a t_cell struct
 * @param t_cell : cell to display
 * @return : void
 */
void displayCell(t_cell cell) {
    printf("%d", cell.value);
}

/***
 * @brief create a cell, and return a pointer to
 * @param int value
 * @return pointer to cell, whit a value, and next is NULL
 */
p_cell createCell(int val) {
    p_cell cell = (p_cell) malloc(sizeof (t_cell));
    cell->value = val;
    cell->next = NULL;
    cell->prev = NULL;
    return cell;
}

// Supprime une cellule
void deleteCell(p_cell cell) {
    free(cell);
}
