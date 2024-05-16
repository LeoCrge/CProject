#include "Union.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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


int main() {
    COLUMN *mycol = create_column1(CHAR, "caca");
    if (mycol != NULL) {
        printf("Column created successfully!\n");
        printf("Title: %s\n", mycol->title);
        printf("Type: %d\n", mycol->column_type);

        free(mycol->title);
        free(mycol);
    } else {
        printf("Failed to create column!\n");
    }

    return 0;
}

