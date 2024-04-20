#ifndef CPROJECT_MAIN_H
#define CPROJECT_MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Column.h"

#define REALLOC_SIZE 256

// Functions from part 4.2


typedef struct {
    COLUMN **columns;
    int num_columns;
    int max_rows;
    int num_rows;
} CDATAFRAME;

// Creation of a free dataframe
CDATAFRAME *create_dataframe(int num_columns, int max_rows){
    CDATAFRAME *dataframe = (CDATAFRAME *)malloc(sizeof(CDATAFRAME));
    if (dataframe == NULL){
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    dataframe->columns = (COLUMN **)malloc (num_columns * sizeof(COLUMN*));
    if (dataframe->columns == NULL){
        printf("Memory allocations failed\n");
        exit(EXIT_FAILURE);
    }
    dataframe-> num_columns = num_columns;
    dataframe-> max_rows = max_rows;
    dataframe-> num_rows = 0;
    return dataframe;
}

// Function to fill the CDATAFRAME with user input
void fill_dataframe_user_input(CDATAFRAME*dataframe) {
    if (!dataframe) return;
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

// Hard filling of the created dataframe
void hard_fill_dataframe(CDATAFRAME *dataframe){
    int val;
    if (!dataframe) return;
    for (int i=0; i<dataframe->num_columns; i++){
        for (int j=0; j<dataframe->max_rows; j++) {
            printf("Enter the value at column %d and row %d \n", i+1, j+1);
            scanf("%d", &val);
            insert_value(dataframe->columns[i], val);
        }
    }
}

// Display of the dataframe
void display_dataframe(CDATAFRAME *dataframe){
    if (!dataframe) return;
    printf("CDATAFRAME:\n");
    for (int i=0; i<dataframe->num_columns; i++){
        for (int j=0; j<dataframe->max_rows; j++){
            printf("[%d] [%d] %d\n",i+1, j+1, dataframe->columns[i]->data[j]);
        }
    }
}

// Function to display a part of the CDATAFRAME rows according to a user-provided limit
void display_partial_rows(CDATAFRAME *dataframe, int limit) {
    if (!dataframe || limit <= 0) return;

    printf("Partial CDATAFRAME (first %d rows):\n", limit);
    for (int i = 0; i < dataframe->num_columns; i++) {
        COLUMN *col = dataframe->columns[i];
        printf("[%s]\n", col->title);
        for (int j = 0; j < limit && j < col->logical_size; j++) {
            printf("[%d] %d\n", j, col->data[j]);
        }
    }
}

// Function to display a part of the columns of the CDATAFRAME according to a limit supplied by the user
void display_partial_columns(CDATAFRAME *dataframe, int limit) {
    if (!dataframe || limit <= 0) return;

    printf("Partial CDATAFRAME (first %d columns):\n", limit);
    for (int i = 0; i < limit && i < dataframe->num_columns; i++) {
        COLUMN *col = dataframe->columns[i];
        print_col(col);
    }
}

// Function to search for a value in the CDATAFRAME
int search_value(CDATAFRAME *dataframe, int value) {
    if (!dataframe) return 0;

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


#endif //CPROJECT_MAIN_H
