#include "Column.h"
#include "CDataframe.h"

#define REALLOC_SIZE 256


// Structure definition for a column
typedef struct COLUMN;
// Structure definition for a CDataframe
typedef struct CDataframe ;

// Function prototypes for column operations
COLUMN *create_column(char *title);
int insert_value (COLUMN *col, int value);
void delete_column(COLUMN **col);
void print_col(COLUMN *col);


// Function prototypes for CDataframe operations
CDATAFRAME *create_dataframe();
int num_occurrences (COLUMN*col, int x);
int value_at_x (COLUMN*col, int x);
int val_greater_x (COLUMN*col, int x);
int val_smaller_than (COLUMN*col, int x);
int values_equal_to (COLUMN*col, int x);