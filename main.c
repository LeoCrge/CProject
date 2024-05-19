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
    int choice, col_type, int_val, position;
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

            case 6:
                if (mycol == NULL) {
                    printf("Create a column first!\n");
                    break;
                }

                printf("Enter value to count occurrences: ");
                switch (mycol->column_type) {
                    case UINT:
                        scanf("%u", &int_val);
                        printf("Occurrences: %u\n", count_occurrences(mycol, &int_val));
                        break;
                    case INT:
                        scanf("%d", &int_val);
                        printf("Occurrences: %u\n", count_occurrences(mycol, &int_val));
                        break;
                    case CHAR:
                        scanf(" %c", &char_val);
                        printf("Occurrences: %u\n", count_occurrences(mycol, &char_val));
                        break;
                    case FLOAT:
                        scanf("%f", &float_val);
                        printf("Occurrences: %u\n", count_occurrences(mycol, &float_val));
                        break;
                    case DOUBLE:
                        scanf("%lf", &double_val);
                        printf("Occurrences: %u\n", count_occurrences(mycol, &double_val));
                        break;
                    case STRING:
                        scanf("%s", str_val);
                        printf("Occurrences: %u\n", count_occurrences(mycol, str_val));
                        break;
                    default:
                        printf("Invalid column type!\n");
                }
                break;

            case 7:
                if (mycol == NULL) {
                    printf("Create a column first!\n");
                    break;
                }

                printf("Enter position: ");
                scanf("%d", &position);
                char *value = value_at_position(mycol, position);
                if (value) {
                    printf("Value at position %d: %s\n", position, value);
                } else {
                    printf("Invalid position!\n");
                }
                break;

            case 8:
                if (mycol == NULL) {
                    printf("Create a column first!\n");
                    break;
                }

                printf("Enter value to count greater values: ");
                switch (mycol->column_type) {
                    case UINT:
                        scanf("%u", &int_val);
                        printf("Greater values: %u\n", count_greater_than(mycol, &int_val));
                        break;
                    case INT:
                        scanf("%d", &int_val);
                        printf("Greater values: %u\n", count_greater_than(mycol, &int_val));
                        break;
                    case FLOAT:
                        scanf("%f", &float_val);
                        printf("Greater values: %u\n", count_greater_than(mycol, &float_val));
                        break;
                    case DOUBLE:
                        scanf("%lf", &double_val);
                        printf("Greater values: %u\n", count_greater_than(mycol, &double_val));
                        break;
                    default:
                        printf("Invalid column type for comparison!\n");
                }
                break;

            case 9:
                if (mycol == NULL) {
                    printf("Create a column first!\n");
                    break;
                }

                printf("Enter value to count lower values: ");
                switch (mycol->column_type) {
                    case UINT:
                        scanf("%u", &int_val);
                        printf("Lower values: %u\n", count_lower_than(mycol, &int_val));
                        break;
                    case INT:
                        scanf("%d", &int_val);
                        printf("Lower values: %u\n", count_lower_than(mycol, &int_val));
                        break;
                    case FLOAT:
                        scanf("%f", &float_val);
                        printf("Lower values: %u\n", count_lower_than(mycol, &float_val));
                        break;
                    case DOUBLE:
                        scanf("%lf", &double_val);
                        printf("Lower values: %u\n", count_lower_than(mycol, &double_val));
                        break;
                    default:
                        printf("Invalid column type for comparison!\n");
                }
                break;

            case 10:
                if (mycol == NULL) {
                    printf("Create a column first!\n");
                    break;
                }

                printf("Enter value to count equal values: ");
                switch (mycol->column_type) {
                    case UINT:
                        scanf("%u", &int_val);
                        printf("Equal values: %u\n", count_equal_to(mycol, &int_val));
                        break;
                    case INT:
                        scanf("%d", &int_val);
                        printf("Equal values: %u\n", count_equal_to(mycol, &int_val));
                        break;
                    case CHAR:
                        scanf(" %c", &char_val);
                        printf("Equal values: %u\n", count_equal_to(mycol, &char_val));
                        break;
                    case FLOAT:
                        scanf("%f", &float_val);
                        printf("Equal values: %u\n", count_equal_to(mycol, &float_val));
                        break;
                    case DOUBLE:
                        scanf("%lf", &double_val);
                        printf("Equal values: %u\n", count_equal_to(mycol, &double_val));
                        break;
                    case STRING:
                        scanf("%s", str_val);
                        printf("Equal values: %u\n", count_equal_to(mycol, str_val));
                        break;
                    default:
                        printf("Invalid column type!\n");
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
        sleep(3);
        printf("\n\n\n\n\n\n\n");
    }

    return 0;
}