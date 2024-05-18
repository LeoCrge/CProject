#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #include "Union.h"
#include "Union.c"

#define REALLOC_SIZE 256


void menu() {
    printf("1 - Create a Column\n");
    printf("2 - Insert a value\n");
    printf("3 - Delete a column\n");
    printf("4 - Convert a value\n");
    printf("5 - Print a column\n");
    printf("6 - Number of occurrences of x\n");
    printf("7 - Value present at position x\n");
    printf("8 - Number of values greater than x\n");
    printf("9 - Number of values lower than x\n");
    printf("10 - Number of values equal to x\n");
    printf("11 - Exit\n");
}

int main() {
    COLUMN *mycol = NULL;
    int choice, col_type, int_val;
    char char_val, str_val[256];
    float float_val;
    double double_val;
    char title[256];

    while (1) {
        menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter column type (0: NULL, 1: UINT, 2: INT, 3: CHAR, 4: FLOAT, 5: DOUBLE, 6: STRING, 7: STRUCTURE): ");
                scanf("%d", &col_type);
                printf("Enter column title: ");
                scanf("%s", title);
                mycol = create_column1((ENUM_TYPE)col_type, title);
                printf("Column created successfully!\n");
                break;

            case 2:
                if (mycol == NULL) {
                    printf("Create a column first!\n");
                    break;
                }

                switch (mycol->column_type) {
                    case UINT:
                        printf("Enter unsigned int value: ");
                        scanf("%u", &int_val);
                        insert_value1(mycol, &int_val);
                        break;
                    case INT:
                        printf("Enter int value: ");
                        scanf("%d", &int_val);
                        insert_value1(mycol, &int_val);
                        break;
                    case CHAR:
                        printf("Enter char value: ");
                        scanf(" %c", &char_val);
                        insert_value1(mycol, &char_val);
                        break;
                    case FLOAT:
                        printf("Enter float value: ");
                        scanf("%f", &float_val);
                        insert_value1(mycol, &float_val);
                        break;
                    case DOUBLE:
                        printf("Enter double value: ");
                        scanf("%lf", &double_val);
                        insert_value1(mycol, &double_val);
                        break;
                    case STRING:
                        printf("Enter string value: ");
                        scanf("%s", str_val);
                        insert_value1(mycol, str_val);
                        break;
                    default:
                        printf("Invalid column type!\n");
                }
                break;

            case 3:
                if (mycol != NULL) {
                    delete_column1(mycol);
                    mycol = NULL;
                    printf("Column deleted successfully!\n");
                } else {
                    printf("No column to delete!\n");
                }
                break;

            case 4:
                printf("Conversion not implemented!\n");
                break;

            case 5:
                if (mycol != NULL) {
                    print_column(mycol);
                } else {
                    printf("No column to print!\n");
                }
                break;

            case 11:
                if (mycol != NULL) {
                    delete_column1(mycol);
                }
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}