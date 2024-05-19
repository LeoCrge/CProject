#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Union.h"

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
* @return: 1 if the value is correctly inserted, 0 otherwise
*/
int insert_value1(COLUMN *col, void *value) {
    if (col->size == col->max_size) {
        col->max_size += REALLOC_SIZE;
        col->data = (COL_TYPE **)realloc(col->data, col->max_size * sizeof(COL_TYPE *));
        if (col->data == NULL) {
            printf("Memory reallocation failed!\n");
            exit(EXIT_FAILURE);
        }
    }

    col->data[col->size] = (COL_TYPE *)malloc(sizeof(COL_TYPE));
    if (col->data[col->size] == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    switch (col->column_type) {
        case NULLVAL:
            break;
        case UINT:
            col->data[col->size]->string_value = (char *)malloc(20 * sizeof(char));
            snprintf(col->data[col->size]->string_value, 20, "%u", *((unsigned int *)value));
            break;
        case INT:
            col->data[col->size]->string_value = (char *)malloc(20 * sizeof(char));
            snprintf(col->data[col->size]->string_value, 20, "%d", *((int *)value));
            break;
        case CHAR:
            col->data[col->size]->string_value = (char *)malloc(2 * sizeof(char));
            snprintf(col->data[col->size]->string_value, 2, "%c", *((char *)value));
            break;
        case FLOAT:
            col->data[col->size]->string_value = (char *)malloc(20 * sizeof(char));
            snprintf(col->data[col->size]->string_value, 20, "%f", *((float *)value));
            break;
        case DOUBLE:
            col->data[col->size]->string_value = (char *)malloc(20 * sizeof(char));
            snprintf(col->data[col->size]->string_value, 20, "%lf", *((double *)value));
            break;
        case STRING:
            col->data[col->size]->string_value = strdup((char *)value);
            break;
        case STRUCTURE:
            // Assuming the size of the structure is not known
            break;
        default:
            printf("Invalid column type!\n");
            return 0;
    }

    col->size++;
    return 1;
}

void delete_column1(COLUMN *col) {
    free(col->title);
    for (unsigned int i = 0; i < col->size; i++) {
        free(col->data[i]->string_value);
        free(col->data[i]);
    }
    free(col->data);
    free(col);
}

void convert_value(COLUMN *col, unsigned long long int i, char *str, int size) {
    if (i >= col->size) {
        snprintf(str, size, "Index out of bounds");
        return;
    }

    switch (col->column_type) {
        case NULLVAL:
            break;
        case INT:
            snprintf(str, size, "%d", *((int*)col->data[i]));
            break;
        case CHAR:
            snprintf(str, size, "%c", *((char*)col->data[i]));
            break;
        case FLOAT:
            snprintf(str, size, "%f", *((float*)col->data[i]));
            break;
        case DOUBLE:
            snprintf(str, size, "%lf", *((double*)col->data[i]));
            break;
        case STRING:
            snprintf(str, size, "%s", (char*)col->data[i]);
            break;
        case STRUCTURE:
            break;
        default:
            printf("Invalid column type!\n");
            return;
    }

}

void print_column(COLUMN *col) {
    printf("Title: %s\n", col->title);
    printf("Values in the column:\n");
    for (unsigned int i = 0; i < col->size; i++) {
        switch (col->column_type) {
            case NULLVAL:
                printf("NULL\n");
                break;
            case UINT:
            case INT:
            case CHAR:
            case FLOAT:
            case DOUBLE:
            case STRING:
                printf("%s\n", col->data[i]->string_value);
                break;
            case STRUCTURE:
                break;
            default:
                printf("Invalid column type!\n");
        }
    }
}

unsigned int count_occurrences(COLUMN *col, void *value) {
    unsigned int count = 0;
    for (unsigned int i = 0; i < col->size; i++) {
        switch (col->column_type) {
            case UINT:
                if (atoi(col->data[i]->string_value) == *((unsigned int *)value)) count++;
                break;
            case INT:
                if (atoi(col->data[i]->string_value) == *((int *)value)) count++;
                break;
            case CHAR:
                if (col->data[i]->string_value[0] == *((char *)value)) count++;
                break;
            case FLOAT:
                if (atof(col->data[i]->string_value) == *((float *)value)) count++;
                break;
            case DOUBLE:
                if (atof(col->data[i]->string_value) == *((double *)value)) count++;
                break;
            case STRING:
                if (strcmp(col->data[i]->string_value, (char *)value) == 0) count++;
                break;
            default:
                printf("Invalid column type!\n");
        }
    }
    return count;
}

char *value_at_position(COLUMN *col, unsigned int position) {
    if (position < col->size) {
        return col->data[position]->string_value;
    }
    return NULL;
}

unsigned int count_greater_than(COLUMN *col, void *value) {
    unsigned int count = 0;
    for (unsigned int i = 0; i < col->size; i++) {
        switch (col->column_type) {
            case UINT:
                if (atoi(col->data[i]->string_value) > *((unsigned int *)value)) count++;
                break;
            case INT:
                if (atoi(col->data[i]->string_value) > *((int *)value)) count++;
                break;
            case FLOAT:
                if (atof(col->data[i]->string_value) > *((float *)value)) count++;
                break;
            case DOUBLE:
                if (atof(col->data[i]->string_value) > *((double *)value)) count++;
                break;
            default:
                printf("Invalid column type for comparison!\n");
        }
    }
    return count;
}

unsigned int count_lower_than(COLUMN *col, void *value) {
    unsigned int count = 0;
    for (unsigned int i = 0; i < col->size; i++) {
        switch (col->column_type) {
            case UINT:
                if (atoi(col->data[i]->string_value) < *((unsigned int *)value)) count++;
                break;
            case INT:
                if (atoi(col->data[i]->string_value) < *((int *)value)) count++;
                break;
            case FLOAT:
                if (atof(col->data[i]->string_value) < *((float *)value)) count++;
                break;
            case DOUBLE:
                if (atof(col->data[i]->string_value) < *((double *)value)) count++;
                break;
            default:
                printf("Invalid column type for comparison!\n");
        }
    }
    return count;
}

unsigned int count_equal_to(COLUMN *col, void *value) {
    return count_occurrences(col, value);
}