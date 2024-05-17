#include "Union.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REALLOC_SIZE 256


/*
    - Create a new column
    - @param1 : Column type
    - @param2 : Column title
    - @return : Pointer to the created column
*/
COLUMN *create_column1(ENUM_TYPE type, char *title) {
    COLUMN *new_column = (COLUMN *)malloc(sizeof(COLUMN));

    if (new_column == NULL) {
        printf("Memory allocation failed \n");
        exit(EXIT_FAILURE);
    }

    new_column->title = strdup(title);
    new_column->size = 0;
    new_column->max_size = 0;
    new_column->column_type = type;

    new_column->data = NULL;
    new_column->index = NULL;

    return new_column;
}

/**
* @brief: Insert a new value into a column
* @param1: Pointer to the column
* @param2: Pointer to the value to insert
* @return: 1 if the value is correctly inserted 0 otherwise
*/
int insert_value(COLUMN *col, void *value) {
    if (!col) return 0;
    if (col->size <= col->max_size){
        int* loc = realloc(col->data, (col->size + REALLOC_SIZE) * sizeof(int));
        if (loc == NULL){
            printf("Memory allocation failed \n");
            return 0;
        }
        col->data = loc;
        col->size += REALLOC_SIZE;
    }
    col->data[col->max_size++] = value;
    return 1;
}


int main() {
    COLUMN *mycol = create_column1(CHAR, "caca");
    if (mycol != NULL) {
        printf("Column created successfully!\n");
        printf("Title: %s\n", mycol->title);
        printf("Type: %d\n", mycol->column_type);

        char a = 'A', c = 'C';
        insert_value(mycol, &a);
        insert_value(mycol, NULL);
        insert_value(mycol, &c);

        free(mycol->title);
        free(mycol);
    } else {
        printf("Failed to create column!\n");
    }

    return 0;
}

