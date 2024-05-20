#ifndef CDATAFRAME_H
#define CDATAFRAME_H

#include "../column/column.h"

typedef struct {
    COLUMN **columns;
    int num_columns;
    int max_rows;
    int num_rows;
} CDATAFRAME;

CDATAFRAME *create_dataframe(int num_columns, int max_rows);
void fill_dataframe_user_input(CDATAFRAME *dataframe);
void hard_fill_dataframe(CDATAFRAME *dataframe);
void display_dataframe(CDATAFRAME *dataframe);
void display_partial_rows(CDATAFRAME *dataframe, int limit);
void display_partial_columns(CDATAFRAME *dataframe, int limit);
void add_row(CDATAFRAME *dataframe, int *values);
void delete_row(CDATAFRAME *dataframe, int num_row);
void add_column(CDATAFRAME *dataframe, char *title);
void delete_columns(CDATAFRAME *dataframe, int num_col);
void rename_column(CDATAFRAME *dataframe, int num_col, char *new_title);
int search_value(CDATAFRAME *dataframe, int value);
int value_at_cell(CDATAFRAME *dataframe, int num_row, int num_col);
void display_column_names(CDATAFRAME *dataframe);
int number_rows(CDATAFRAME *dataframe);
int number_columns(CDATAFRAME *dataframe);
int cells_equal_to(CDATAFRAME *dataframe, int x);
int cells_greater_than(CDATAFRAME *dataframe, int x);
int cells_smaller_than(CDATAFRAME *dataframe, int x);

#endif // CDATAFRAME_H
