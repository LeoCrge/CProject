#ifndef COLUMN_H
#define COLUMN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REALLOC_SIZE 256

// Structure representing a column
typedef struct {
    char *title;
    int *data;
    int physical_size;
    int logical_size;
} COLUMN;

// Function prototypes for managing a column
COLUMN *create_column(char *title);
int insert_value(COLUMN *col, int value);
void delete_column(COLUMN **col);
void print_col(COLUMN *col);
int num_occurrences(COLUMN *col, int x);
int value_at_x(COLUMN *col, int x);
int val_greater_x(COLUMN *col, int x);
int val_smaller_than(COLUMN *col, int x);
int values_equal_to(COLUMN *col, int x);

#endif
