#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cDataFrame.h"


// Functions from part 4.2

// Creation of a free dataframe
CDATAFRAME *create_dataframe(int num_columns, int max_rows) {
    CDATAFRAME *dataframe = (CDATAFRAME *)malloc(sizeof(CDATAFRAME));
    if (dataframe == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    dataframe->columns = (COLUMN **)malloc(num_columns * sizeof(COLUMN *));
    if (dataframe->columns == NULL) {
        printf("Memory allocation failed\n");
        free(dataframe);
        exit(EXIT_FAILURE);
    }
    dataframe->num_columns = num_columns;
    dataframe->max_rows = max_rows;
    dataframe->num_rows = 0;
    return dataframe;
}

// Function to fill the CDATAFRAME with user input
void fill_dataframe_user_input(CDATAFRAME *dataframe) {
    if (dataframe == NULL) return;
    for (int i = 0; i < dataframe->num_columns; i++) {
        char title[100];
        printf("Enter title for column %d: ", i+1);
        scanf("%s", title);
        dataframe->columns[i] = create_column(title);
        for (int j = 0; j < dataframe->max_rows; j++) {
            int value;
            printf("Enter value for column %d, row %d: ", i+1, j+1);
            scanf("%d", &value);
            insert_value(dataframe->columns[i], value);
        }
    }
}

// Hard filling of the created dataframe
void hard_fill_dataframe(CDATAFRAME *dataframe) {
    int val;
    if (!dataframe)
        return;
    for (int i = 0; i < dataframe->num_columns; i++) {
        for (int j = 0; j < dataframe->max_rows; j++) {
            printf("Enter the value at column %d and row %d \n", i + 1, j + 1);
            scanf("%d", &val);
            insert_value(dataframe->columns[i], val);
        }
    }
}

// Display of the dataframe
void display_dataframe(CDATAFRAME *dataframe) {
    if (!dataframe)
        return;
    printf("CDATAFRAME:\n");
    for (int i = 0; i < dataframe->num_columns; i++) {
        for (int j = 0; j < dataframe->max_rows; j++) {
            printf("[%d] [%d] %d\n", i + 1, j + 1, dataframe->columns[i]->data[j]);
        }
    }
}

// Function to display a part of the CDATAFRAME rows according to a user-provided limit
void display_partial_rows(CDATAFRAME *dataframe, int limit) {
    if (!dataframe || limit <= 0)
        return;

    printf("Partial CDATAFRAME (first %d rows):\n", limit);
    for (int i = 0; i < dataframe->num_columns; i++) {
        COLUMN *col = dataframe->columns[i];
        // printf("[%s]\n", col->title);
        for (int j = 0; j < limit && j < col->logical_size; j++) {
            printf("[%d] %d\n", j, col->data[j]);
        }
    }
}

// Function to display a part of the columns of the CDATAFRAME according to a limit supplied by the user
void display_partial_columns(CDATAFRAME *dataframe, int limit) {
    if (!dataframe || limit <= 0)
        return;

    printf("Partial CDATAFRAME (first %d columns):\n", limit);
    for (int i = 0; i < limit && i < dataframe->num_columns; i++) {
        COLUMN *col = dataframe->columns[i];
        print_col(col);
    }
}

// Function to add a row
void add_row(CDATAFRAME *dataframe, int *values) {
    if (dataframe == NULL || values == NULL) {
        return;
    }
    if (dataframe->num_rows >= dataframe->max_rows) {
        printf("Maximum number of rows reached \n");
        return;
    }
    for (int i = 0; i < dataframe->num_columns; i++) {
        insert_value(dataframe->columns[i], values[i]);
    }
    dataframe->num_columns++;
}

// Function to delete a row
void delete_row(CDATAFRAME *dataframe, int num_row) {
    if (dataframe == NULL || num_row < 0 || num_row >= dataframe->num_rows) {
        return;
    }
    for (int i = 0; i < dataframe->num_columns; i++) {
        for (int j = num_row; j < dataframe->num_rows - 1; j++) {
            dataframe->columns[i]->data[j] = dataframe->columns[i]->data[j + 1];
        }
        dataframe->columns[i]->logical_size--;
    }
    dataframe->num_rows--;
}



// Function to add a column
void add_column(CDATAFRAME *dataframe, char *title) {
    if (dataframe == NULL || title == NULL) {
        return;
    }
    dataframe->columns[dataframe->num_columns++] = create_column(title);
}

// Function to delete a column
void delete_columns(CDATAFRAME *dataframe, int num_col) {
    if (dataframe == NULL || num_col < 0 || num_col >= dataframe->num_columns) {
        return;
    }

    for (int i = 0; i < dataframe->num_rows; i++) {
        free(dataframe->columns[num_col]->data[i]);
    }
    free(dataframe->columns[num_col]->data);
    free(dataframe->columns[num_col]);

    for (int i = num_col; i < dataframe->num_columns - 1; i++) {
        dataframe->columns[i] = dataframe->columns[i + 1];
    }

    dataframe->num_columns--;
}

// Function to rename a column
void rename_column(CDATAFRAME *dataframe, int num_col, char *new_title) {
    if (dataframe == NULL || num_col < 0 || num_col >= dataframe->num_columns || new_title == NULL) {
        printf("Invalid parameters! \n");
        return;
    }
    free(dataframe->columns[num_col]->title);
    dataframe->columns[num_col]->title = strdup(new_title);
}

// Function to search for a value in the CDATAFRAME
int search_value(CDATAFRAME *dataframe, int value) {
    if (!dataframe)
        return 0;

    int count = 0;
    for (int i = 0; i < dataframe->num_columns; i++) {
        COLUMN *col = dataframe->columns[i];
        for (int j = 0; j < col->logical_size; j++) {
            if (col->data[j] == value) {
                count++;
            }
        }
    }
    return count;
}

// Function to find the value at a certain cell
int value_at_cell(CDATAFRAME *dataframe, int num_row, int num_col) {
    if (dataframe == NULL || num_row < 0 || num_row >= dataframe->num_rows || num_col < 0 || num_col >= dataframe->num_columns) {
        exit(EXIT_FAILURE);
    }
    return dataframe->columns[num_col]->data[num_row];
}

// Function to display the names of the column
void display_column_names(CDATAFRAME *dataframe) {
    if (dataframe == NULL) {
        return;
    }
    printf("Column names \n");
    for (int i = 0; i < dataframe->num_columns; i++) {
        printf("%s\n", dataframe->columns[i]->title);
    }
}

// Function to display the number of rows
int number_rows(CDATAFRAME *dataframe) {
    if (dataframe == NULL) {
        return 0;
    }
    return dataframe->max_rows;
}

// Function to display the number of column
int number_columns(CDATAFRAME *dataframe) {
    if (dataframe == NULL) {
        return 0;
    }
    return dataframe->num_columns;
}

// Function to give the number of cells that are equal to a given value
int cells_equal_to(CDATAFRAME *dataframe, int x) {
    if (dataframe == NULL) {
        return 0;
    }
    int count = 0;
    for (int i = 0; i < dataframe->num_columns; i++) {
        count += values_equal_to(dataframe->columns[i], x);
    }
    return count;
}

// Function to give the number of cells that are greater than a given value
int cells_greater_than(CDATAFRAME *dataframe, int x) {
    if (dataframe == NULL) {
        return 0;
    }
    int count = 0;
    for (int i = 0; i < dataframe->num_columns; i++) {
        count += val_greater_x(dataframe->columns[i], x);
    }
    return count;
}

// Function to give the number of cells that are smaller than a given value
int cells_smaller_than(CDATAFRAME *dataframe, int x) {
    if (dataframe == NULL) {
        return 0;
    }
    int count = 0;
    for (int i = 0; i < dataframe->num_columns; i++) {
        count += val_smaller_than(dataframe->columns[i], x);
    }
    return count;
}
