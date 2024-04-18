//
// Created by Carouge on 29/03/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REALLOC_SIZE 256


typedef struct {
    char *title;
    int *data;
    int physical_size;
    int logical_size;
} COLUMN;


// Function 4.1.1
COLUMN *create_column(char *title){
    COLUMN *col = (COLUMN *)malloc(sizeof(COLUMN));
    if (col == NULL) {
        fprintf(stderr, "Memory allocation failed \n");
        exit(EXIT_FAILURE);
    }
    col->title = strdup(title);
    col-> data =NULL;
    col-> physical_size =0;
    col-> logical_size = 0 ;
    return col;
}

// Function 4.1.2
int insert_value (COLUMN *col, int value){
    if (col == NULL){
        return 0;
    }
    if (col->physical_size <= col->logical_size){
        int* loc = realloc(col->data, (col->physical_size + REALLOC_SIZE) * sizeof(int));
        if (loc == NULL){
            fprintf(stderr, "Memory allocation failed \n");
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
int num_occurrences (COLUMN*col, int x){
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
