#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Column.c"
#include "CDataframe.c"

#define REALLOC_SIZE 256

void case1(){
    printf("1 - Create a column \n");
    printf("2 - Insert a value \n");
    printf("3 - Delete a column \n");
    printf("4 - Print a column \n");
    printf("5 - Number of occurrences of x \n");
    printf("6 - Value at index x \n");
    printf("7 - Number of value greater than x\n");
    printf("8 - Number of value smaller than x  \n");
    printf("9 - Number of values equal to  \n");
}

void case2(){
    printf("1 - Create a dataframe \n");
    printf("2 - Fill the dataframe \n");
    printf("3 - Hard fill the dataframe \n");
    printf("4 - Display the dataframe \n");
    printf("5 - Display partial rows \n");
    printf("6 - Display partial columns \n");
    printf("7 - Add a row \n");
    printf("8 - Delete a row \n");
    printf("9 - Add a column \n");
    printf("10 - Delete a column \n");
    printf("11 - Rename a column \n");
    printf("12 - Search value x \n");
    printf("13 - Value at cell x \n");
    printf("14 - Display the columns names \n");
    printf("15 - Display the number of rows \n");
    printf("16 - Display the number of columns \n");
    printf("17 - Number of cells equal to x \n");
    printf("18 - Number of cells greater than x \n");
    printf("19 - Number of cells smaller than x \n");
}

int part1() {
    int choice, x, val, y, num_col, max_row, lim, num_row;
    char name[256], *new_title = NULL;
    COLUMN *column = NULL;
    CDATAFRAME *cdataframe = NULL;
    int *value = NULL;
        printf("\nMain Menu:\n");
        printf("1. COLUMN operations\n");
        printf("2. CDATAFRAME operations\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            while (1) {
                case1();
                printf("Enter your choice \n");
                scanf("%d", &choice);
                switch (choice) {
                    case 1:
                        printf("Enter the title of the column \n");
                        scanf("%s", name);
                        column = create_column(name);
                        break;
                    case 2:
                        if (column == NULL) {
                            printf("Create a column first \n");
                            break;
                        }
                        printf("Enter a value \n");
                        scanf("%d", &val);
                        if (insert_value(column, val)) {
                            printf("Value successfully inserted \n");
                        } else {
                            printf("Failed to insert the value \n");
                        }
                        break;
                    case 3:
                        if (column == NULL) {
                            printf("Create a column first \n");
                            break;
                        }
                        delete_column(&column);
                        printf("The column has been deleted \n");
                        break;
                    case 4:
                        if (column == NULL) {
                            printf("Create a column first \n");
                            break;
                        }
                        print_col(column);
                        break;
                    case 5:
                        if (column == NULL) {
                            printf("Create a column first \n");
                            break;
                        }
                        printf("Enter a value to count \n");
                        scanf("%d", &y);
                        printf("Number of occurrences of %d: %d \n", y, num_occurrences(column, y));
                        break;
                    case 6:
                        if (column == NULL) {
                            printf("Create a column first \n");
                            break;
                        }
                        printf("Enter position to get value \n");
                        scanf("%d", &y);
                        printf("Value at position %d : %d \n", y, value_at_x(column, y));
                        break;
                    case 7:
                        if (column == NULL) {
                            printf("Create a column first \n");
                            break;
                        }
                        printf("Enter a value to count greater values from \n");
                        scanf("%d", &y);
                        printf("Values greater than %d : %d", y, val_greater_x(column, y));
                        break;
                    case 8:
                        if (column == NULL) {
                            printf("Create a column first \n");
                            break;
                        }
                        printf("Enter a value to count smaller values from \n");
                        scanf("%d", &y);
                        printf("Values smaller than %d : %d", y, val_smaller_than(column, y));
                        break;
                    case 9:
                        if (column == NULL) {
                            printf("Create a column first \n");
                            break;
                        }
                        printf("Enter a value to count values equal to \n");
                        scanf("%d", &y);
                        printf("Values equal to %d : %d", y, values_equal_to(column, y));
                        break;
                    case 0:
                        if (column != NULL) {
                            delete_column(&column);
                        }
                        printf("Exciting program \n");
                        exit(EXIT_SUCCESS);
                    default:
                        printf("Invalid choice. Please try again \n");
                }
                if (choice == 0)
                    break;
            }
        }
        else if (choice == 2){

                while (1) {
                    case2();
                    printf("Enter your choice \n");
                    scanf("%d", &choice);
                    switch (choice) {
                        case 1:
                            printf("Enter the number of columns \n");
                            scanf("%d", &num_col);
                            printf("Enter the maximum number of rows \n");
                            scanf("%d", &max_row);
                            cdataframe = create_dataframe(num_col, max_row);
                            break;
                        case 2:
                            if (cdataframe == NULL) {
                                printf("Create a dataframe first.\n");
                                break;
                            }
                            fill_dataframe_user_input(cdataframe);
                            break;
                        case 3:
                            if (cdataframe == NULL) {
                                printf("Create a dataframe first.\n");
                                break;
                            }
                            hard_fill_dataframe(cdataframe);
                            break;
                        case 4:
                            if (cdataframe == NULL) {
                                printf("Create a dataframe first.\n");
                                break;
                            }
                            display_dataframe(cdataframe);
                            break;
                        case 5:
                            if (cdataframe == NULL) {
                                printf("Create a dataframe first.\n");
                                break;
                            }
                            printf("Enter the number of rows to display \n");
                            scanf("%d", &lim);
                            display_partial_rows(cdataframe, lim);
                            break;
                        case 6:
                            if (cdataframe == NULL) {
                                printf("Create a dataframe first.\n");
                                break;
                            }
                            printf("Enter the number of columns to display \n");
                            scanf("%d", &lim);
                            display_partial_columns(cdataframe, lim);
                            break;
                        case 7:
                            if (cdataframe == NULL) {
                                printf("Create a dataframe first.\n");
                                break;
                            }
                            value = (int *) malloc(cdataframe->num_columns * sizeof(int));
                            if (value == NULL) {
                                printf("Memory allocation failed \n");
                                break;
                            }
                            printf("Enter values to fill the new row \n");
                            for (int i = 0; i < cdataframe->num_columns; i++) {
                                printf("Value for column %d \n", i + 1);
                                scanf("%d", &value[i]);
                            }
                            add_row(cdataframe, value);
                            free(value);
                            break;
                        case 8:
                            if (cdataframe == NULL) {
                                printf("Create a dataframe first.\n");
                                break;
                            }
                            printf("Enter the row number to delete \n");
                            scanf("%d", &num_row);
                            delete_row(cdataframe, num_row);
                            break;
                        case 9:
                            if (cdataframe == NULL) {
                                printf("Create a dataframe first.\n");
                                break;
                            }
                            printf("Enter the title for the new column \n");
                            scanf("%s", name);
                            add_column(cdataframe, name);
                            break;
                        case 10:
                            if (cdataframe == NULL) {
                                printf("Create a dataframe first.\n");
                                break;
                            }
                            printf("Enter the number of column to delete \n");
                            scanf("%d", &num_col);
                            delete_columns(cdataframe, num_col);
                            break;
                        case 11:
                            if (cdataframe == NULL) {
                                printf("Create a dataframe first.\n");
                                break;
                            }
                            printf("Enter the column number to rename: ");
                            scanf("%d", &num_col);
                            printf("Enter new title for the column: ");
                            scanf("%s", new_title);
                            rename_column(cdataframe, num_col, new_title);
                            break;
                        case 12:
                            if (cdataframe == NULL) {
                                printf("Create a dataframe first.\n");
                                break;
                            }
                            printf("Enter value to search: ");
                            scanf("%d", &val);
                            printf("Value %d found %d times in the dataframe.\n", val, search_value(cdataframe, val));
                            break;
                        case 13:
                            if (cdataframe == NULL) {
                                printf("Create a dataframe first.\n");
                                break;
                            }
                            printf("Enter row number: ");
                            scanf("%d", &num_row);
                            printf("Enter column number: ");
                            scanf("%d", &num_col);
                            printf("Value at cell (%d, %d): %d\n", num_row, num_col,
                                   value_at_cell(cdataframe, num_row, num_col));
                            break;
                        case 14:
                            if (cdataframe == NULL) {
                                printf("Create a dataframe first.\n");
                                break;
                            }
                            display_column_names(cdataframe);
                            break;
                        case 15:
                            if (cdataframe == NULL) {
                                printf("Create a dataframe first.\n");
                                break;
                            }
                            printf("Number of rows: %d\n", number_rows(cdataframe));
                            break;
                        case 16:
                            if (cdataframe == NULL) {
                                printf("Create a dataframe first.\n");
                                break;
                            }
                            printf("Number of columns: %d\n", number_columns(cdataframe));
                            break;
                        case 17:
                            if (cdataframe == NULL) {
                                printf("Create a dataframe first.\n");
                                break;
                            }
                            printf("Enter value to count cells equal to: ");
                            scanf("%d", &val);
                            printf("Number of cells equal to %d: %d\n", value, cells_equal_to(cdataframe, val));
                            break;
                        case 18:
                            if (cdataframe == NULL) {
                                printf("Create a dataframe first.\n");
                                break;
                            }
                            printf("Enter value to count cells greater than: ");
                            scanf("%d", &val);
                            printf("Number of cells greater than %d: %d\n", value, cells_greater_than(cdataframe, val));
                            break;
                        case 19:
                            if (cdataframe == NULL) {
                                printf("Create a dataframe first.\n");
                                break;
                            }
                            printf("Enter value to count cells smaller than: ");
                            scanf("%d", &val);
                            printf("Number of cells smaller than %d: %d\n", value, cells_smaller_than(cdataframe, val));
                            break;
                        case 0:
                            if (cdataframe != NULL) {
                                for (int i = 0; i < cdataframe->num_columns; i++) {
                                    delete_column(&(cdataframe->columns[i]));
                                }
                                free(cdataframe->columns);
                                free(cdataframe);
                            }
                            printf("Exiting program.\n");
                            exit(EXIT_SUCCESS);
                        default:
                            printf("Invalid choice. Please try again.\n");
                    }
                    if (choice == 0)
                    break;
                }
        }
        else{
            printf("Enter either one or two");
        }
    return 0;
}
