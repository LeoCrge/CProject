#include "CDataframe.h"
#include <stdio.h>
#include <stdlib.h>

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

void fill_dataframe_user_input(CDATAFRAME *dataframe) {
    if (!dataframe)
        return;
    for (int i = 0; i < dataframe->num_columns; i++) {
        COLUMN *col = dataframe->columns[i];
        printf("Enter values for column %s:\n", col->title);
        for (int j = 0; j < col->physical_size; j++) {
            int value;
            printf("Enter value %d: ", j + 1);
            scanf("%d", &value);
            insert_value(col, value);
        }
    }
}

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

void display_partial_rows(CDATAFRAME *dataframe, int limit) {
    if (!dataframe || limit <= 0)
        return;

    printf("Partial CDATAFRAME (first %d rows):\n", limit);
    for (int i = 0; i < dataframe->num_columns; i++) {
        COLUMN *col = dataframe->columns[i];
        printf("[%s]\n", col->title);
        for (int j = 0; j < limit && j < col->logical_size; j++) {
            printf("[%d] %d\n", j, col->data[j]);
        }
    }
}

void display_partial_columns(CDATAFRAME *dataframe, int limit) {
    if (!dataframe || limit <= 0)
        return;

    printf("Partial CDATAFRAME (first %d columns):\n", limit);
    for (int i = 0; i < limit && i < dataframe->num_columns; i++) {
        COLUMN *col = dataframe->columns[i];
        print_col(col);
    }
}

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

void delete_row(CDATAFRAME *dataframe, int num_row) {
    if (dataframe == NULL || num_row < 0 || num_row > dataframe->num_rows) {
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

void add_column(CDATAFRAME *dataframe, char *title) {
    if (dataframe == NULL || title == NULL) {
        return;
    }
    dataframe->columns[dataframe->num_columns++] = create_column(title);
}

void delete_columns(CDATAFRAME *dataframe, int num_col) {
    if (dataframe == NULL || num_col < 0 || num_col >= dataframe->num_columns) {
        return;
    }
    for (int i = num_col; i < dataframe->num_columns - 1; i++) {
        dataframe->columns[i] = dataframe->columns[i + 1];
    }
    dataframe->num_columns--;
}

void rename_column(CDATAFRAME *dataframe, int num_col, char *new_title) {
    if (dataframe == NULL || num_col < 0 || num_col >= dataframe->num_columns || new_title == NULL) {
        printf("Invalid parameters! \n");
        return;
    }
    free(dataframe->columns[num_col]->title);
    dataframe->columns[num_col]->title = strdup(new_title);
}

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

int value_at_cell(CDATAFRAME *dataframe, int num_row, int num_col) {
    if (dataframe == NULL || num_row < 0 || num_row >= dataframe->num_rows || num_col < 0 || num_col >= dataframe->num_columns) {
        exit(EXIT_FAILURE);
    }
    return dataframe->columns[num_col]->data[num_row];
}

void display_column_names(CDATAFRAME *dataframe) {
    if (dataframe == NULL) {
        return;
    }
    printf("Column names \n");
    for (int i = 0; i < dataframe->num_columns; i++) {
        printf("%s\n", dataframe->columns[i]->title);
    }
}

int number_rows(CDATAFRAME *dataframe) {
    if (dataframe == NULL) {
        return 0;
    }
    return dataframe->num_rows;
}

int number_columns(CDATAFRAME *dataframe) {
    if (dataframe == NULL) {
        return 0;
    }
    return dataframe->num_columns;
}

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
