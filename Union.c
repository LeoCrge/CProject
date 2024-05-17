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
int insert_value1(COLUMN *col, void *value) {
    if (col == NULL || value == NULL) {
        return 0;
    }

    if (col->size >= col->max_size) {
        col->max_size += 256;
        COL_TYPE **temp_data = realloc(col->data, col->max_size * sizeof(COL_TYPE *));
        if (temp_data == NULL) {
            return 0;
        }
        col->data = temp_data;
    }

    switch (col->column_type) {
        case INT:
            col->data[col->size] = (COL_TYPE *)malloc(sizeof(int));
            if (col->data[col->size] == NULL) {
                return 0;
            }
            *((int *)col->data[col->size]) = *((int *)value);
            break;
        default:
            return 0;
    }

    col->size++;

    return 1;
}


/**
* @brief: Free the space allocated by a column
* @param1: Pointer to the column
*/
void delete_column1(COLUMN **col) {
    printf("1");
    //free((*col)->title);
    printf("2 %d", (*col)->size);
    for (unsigned int i = 0; i < (*col)->size; ++i) {
        free((*col)->data[i]);

        printf("2");
    }

    printf("3");
    free((*col)->data);

    printf("4");
    free((*col));
}


void menu() {
    printf("1 - Create a Column");
    printf("2 - Insert a value");
    printf("3 - Delete a column");
    printf("4 - Convert a value");
    printf("5 - Print a value");
    printf("6 - Number of occurrences of x");
    printf("7 - Value present at position x");
    printf("8 - Number of values grater than x");
    printf("9 - Number of values lower than x");
    printf("10 - Number of values equal to x");
}

int main() {
    COLUMN *mycol = create_column1(CHAR, "test");
    if (mycol != NULL) {
        printf("Column created successfully!\n");
        printf("Title: %s\n", mycol->title);
        printf("Type: %d\n", mycol->column_type);

        char a = 'A', c = 'C';
        insert_value1(mycol, &a);
        insert_value1(mycol, NULL);
        insert_value1(mycol, &c);

        printf("Logical size: %u\n", mycol->size);

        delete_column1(mycol);
        printf("testing");
        printf("Title: %s\n", mycol->title);
    } else {
        printf("Failed to create column!\n");
    }

    return 0;
}

