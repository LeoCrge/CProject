//
// Created by Carouge on 29/03/2024.
//
#include "main.h"

#define REALLOC_SIZE 256



COLUMN *create_column(char *title);
int insert_value (COLUMN *col, int value);
void delete_column(COLUMN **col);
void print_col(COLUMN *col);
int num_occurrences (COLUMN*col, int x);
int value_at_x (COLUMN*col, int x);
int val_greater_x (COLUMN*col, int x);
int val_smaller_than (COLUMN*col, int x);
int values_equal_to (COLUMN*col, int x);