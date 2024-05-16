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
COLUMN *create_column(ENUM_TYPE type, char *title) {
    COLUMN *col = malloc(sizeof(COLUMN));

    if (col == NULL) {
        printf("Memory allocation failed \n");
        exit(EXIT_FAILURE);
    }

    col->title = strdup(title);
    col->data = NULL;
    col->size = 0;
    col->max_size = 0;
    col->column_type = 0;
    col->index = 0;
    return col;
}


int main() {
    COLUMN *mycol = create_column(CHAR, "caca");
}