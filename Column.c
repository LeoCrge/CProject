#include "Column.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REALLOC_SIZE 256

COLUMN *create_column(char *title) {
    COLUMN *col = malloc(sizeof(COLUMN));
    if (col == NULL) {
        printf("Memory allocation failed \n");
        exit(EXIT_FAILURE);
    }
    col->title = strdup(title);
    col->data = NULL;
    col->physical_size = 0;
    col->logical_size = 0;
    return col;
}

// Function 4.1.2
int insert_value(COLUMN *col, int value){
    if (!col) return 0;
    if (col->physical_size <= col->logical_size){
        int* loc = realloc(col->data, (col->physical_size + REALLOC_SIZE) * sizeof(int));
        if (loc == NULL){
            printf("Memory allocation failed \n");
            return 0;
        }
        col->data =loc;
        col->physical_size +=REALLOC_SIZE;
    }
    col->data[col->logical_size++] = value;
    return 1;
}

// Function 4.1.3
void delete_column(COLUMN **col){
    if (col==NULL || *col==NULL){
        return;
    }
    free((*col)->title);
    free((*col)->data);
    free(*col);
    *col=NULL;
}

// Function 4.1.4
void print_col(COLUMN *col){
    if (col==NULL){
        return;
    }
    printf("Column: %s \n", col->title);
    for (int i=0; i<col->logical_size; i++){
        printf("[%d] %d \n", i, col->data[i]);
    }
}

// Other functions 4.1.5:

// Number of occurrences
int num_occurrences(COLUMN*col, int x){
    int occurrences = 0;
    if (col==NULL){
        return 0;
    }
    for (int i=0; i<col->logical_size;i++){
        if (x==col->data[i]){
            occurrences++;
        }
    }
    return occurrences;
}

// Value present at position x
int value_at_x(COLUMN*col, int x){
    if (col==NULL||x<0||x>=col->logical_size){
        printf("Invalid position");
        exit(EXIT_FAILURE);
    }
    return col->data[x];
}

// Number of values greater than x
int val_greater_x(COLUMN*col, int x){
    int count = 0;
    if (!col) return 0;
    for (int i=0; i<col->logical_size; i++){
        if (x<col->data[i]){
            count++;
        }

    }
    return count;
}

// Number of values smaller than x
int val_smaller_than(COLUMN*col, int x){
    int count=0;
    if (col==NULL){
        return 0;
    }
    for (int i=0; i<col->logical_size; i++){
        if (x>col->data[i]){
            count++;
        }
    }
    return count;
}

// Number of values equal to x
int values_equal_to(COLUMN*col, int x){
    int count=0;
    if (col==NULL){
        return 0;
    }
    for (int i=0; i<col->logical_size; i++){
        if (x==col->data[i]){
            count++;
        }
    }
    return count;
}

