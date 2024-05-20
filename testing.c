#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Include the header file containing function prototypes for COLUMN and CDATAFRAME
#include "column/column.h"
#include "cDataFrame/cDataFrame.h"



// int main() {
//     COLUMN *temperature = create_column("Temperature");

//     insert_value(temperature, 25);
//     insert_value(temperature, 28);
//     insert_value(temperature, 30);
//     insert_value(temperature, 27);
//     insert_value(temperature, 22);

//     printf("Temperature column:\n");
//     print_col(temperature);

//     printf("\nNumber of occurrences of 28: %d\n", num_occurrences(temperature, 28));
//     printf("Value at position 3: %d\n", value_at_x(temperature, 3));
//     printf("Number of values greater than 25: %d\n", val_greater_x(temperature, 25));
//     printf("Number of values smaller than 25: %d\n", val_smaller_than(temperature, 25));
//     printf("Number of values equal to 25: %d\n", values_equal_to(temperature, 25));

//     CDATAFRAME *dataframe = create_dataframe(1, 5);

//     dataframe->columns[0] = temperature;

//     printf("\nDisplaying the dataframe:\n");
//     display_dataframe(dataframe);

//     int search_result = search_value(dataframe, 30);
//     printf("\nNumber of occurrences of value 30 in the dataframe: %d\n", search_result);

//     delete_column(&temperature);
//     free(dataframe->columns);
//     free(dataframe);

//     return 0;
// }
