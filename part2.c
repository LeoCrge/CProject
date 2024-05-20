#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "union/union.c"

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

int part2() {
    COLUMN1 *mycol = NULL;
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
                printf("Column type: %d\n", mycol->column_type);
                break;

            case 2:
                if (mycol == NULL) {
                    printf("Create a column first!\n");
                    break;
                }

                switch (mycol->column_type) {
                    case 1:
                        printf("Enter unsigned int value: ");
                        scanf("%u", &int_val);
                        insert_value1(mycol, &int_val);
                        break;
                    case 2:
                        printf("Enter int value: ");
                        scanf("%d", &int_val);
                        insert_value1(mycol, &int_val);
                        break;
                    case 3:
                        printf("Enter char value: ");
                        while ((getchar()) != '\n'); // Clear the input buffer
                        scanf(" %c", &char_val); // Note the space before %c
                        insert_value1(mycol, &char_val);
                        break;
                    case 4:
                        printf("Enter float value: ");
                        scanf("%f", &float_val);
                        insert_value1(mycol, &float_val);
                        break;
                    case 5:
                        printf("Enter double value: ");
                        scanf("%lf", &double_val);
                        insert_value1(mycol, &double_val);
                        break;
                    case 6:
                        printf("Enter string value: \n");
                        scanf("%s", str_val);
                        // gets(str_val);
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
                if (mycol!=NULL){
                    int index;
                    char string[256];
                    printf("Which index's value do you want to convert?");
                    scanf("%d", &index);
                    convert_value(mycol, index,string, sizeof(string));
                }
                else {
                    printf("No value in the column");
                }
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
                    case 1:
                        scanf("%u", &int_val);
                        printf("Occurrences: %u\n", count_occurrences(mycol, &int_val));
                        break;
                    case 2:
                        scanf("%d", &int_val);
                        printf("Occurrences: %u\n", count_occurrences(mycol, &int_val));
                        break;
                    case 3:
                        scanf(" %c", &char_val);
                        printf("Occurrences: %u\n", count_occurrences(mycol, &char_val));
                        break;
                    case 4:
                        scanf("%f", &float_val);
                        printf("Occurrences: %u\n", count_occurrences(mycol, &float_val));
                        break;
                    case 5:
                        scanf("%lf", &double_val);
                        printf("Occurrences: %u\n", count_occurrences(mycol, &double_val));
                        break;
                    case 6:
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
                    case 1:
                        scanf("%u", &int_val);
                        printf("Greater values: %u\n", count_greater_than(mycol, &int_val));
                        break;
                    case 2:
                        scanf("%d", &int_val);
                        printf("Greater values: %u\n", count_greater_than(mycol, &int_val));
                        break;
                    case 4:
                        scanf("%f", &float_val);
                        printf("Greater values: %u\n", count_greater_than(mycol, &float_val));
                        break;
                    case 5:
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
                    case 1:
                        scanf("%u", &int_val);
                        printf("Lower values: %u\n", count_lower_than(mycol, &int_val));
                        break;
                    case 2:
                        scanf("%d", &int_val);
                        printf("Lower values: %u\n", count_lower_than(mycol, &int_val));
                        break;
                    case 4:
                        scanf("%f", &float_val);
                        printf("Lower values: %u\n", count_lower_than(mycol, &float_val));
                        break;
                    case 5:
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
                    case 1:
                        scanf("%u", &int_val);
                        printf("Equal values: %u\n", count_equal_to(mycol, &int_val));
                        break;
                    case 2:
                        scanf("%d", &int_val);
                        printf("Equal values: %u\n", count_equal_to(mycol, &int_val));
                        break;
                    case 3:
                        scanf(" %c", &char_val);
                        printf("Equal values: %u\n", count_equal_to(mycol, &char_val));
                        break;
                    case 4:
                        scanf("%f", &float_val);
                        printf("Equal values: %u\n", count_equal_to(mycol, &float_val));
                        break;
                    case 5:
                        scanf("%lf", &double_val);
                        printf("Equal values: %u\n", count_equal_to(mycol, &double_val));
                        break;
                    case 6:
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

    }

    return 0;
}