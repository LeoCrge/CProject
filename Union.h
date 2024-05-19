#ifndef UNION_H
#define UNION_H

enum enum_type {
    NULLVAL = 1 , UINT, INT, CHAR, FLOAT, DOUBLE, STRING, STRUCTURE
};
typedef enum enum_type ENUM_TYPE;

union column_type{
    unsigned int uint_value;
    signed int int_value;
    char char_value;
    float float_value;
    double double_value;
    char* string_value;
    void* struct_value;
};
typedef union column_type COL_TYPE ;

struct column {
    char *title;
    unsigned int size; //logical size
    unsigned int max_size; //physical size
    ENUM_TYPE column_type;
    COL_TYPE **data; // array of pointers to stored data
    unsigned long long int *index; // array of integers
};
typedef struct column COLUMN;

COLUMN *create_column(char *title);
COLUMN *create_column1(ENUM_TYPE type, char *title);
int insert_value1(COLUMN *col, void *value);
void delete_column1(COLUMN *col);
void convert_value(COLUMN *col, unsigned long long int i, char *str, int size);
void print_column(COLUMN *col);
unsigned int count_occurrences(COLUMN *col, void *value);
char *value_at_position(COLUMN *col, unsigned int position);
unsigned int count_greater_than(COLUMN *col, void *value);
unsigned int count_lower_than(COLUMN *col, void *value);
unsigned int count_equal_to(COLUMN *col, void *value);



#endif
