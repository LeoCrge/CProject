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
typedef struct column COLUMN1;

COLUMN1 *create_column1(ENUM_TYPE type, char *title);
int insert_value1(COLUMN1 *col, void *value);
void delete_column1(COLUMN1 *col);
void convert_value(COLUMN1 *col, unsigned long long int i, char *str, int size);
void print_column(COLUMN1 *col);
unsigned int count_occurrences(COLUMN1 *col, void *value);
char *value_at_position(COLUMN1 *col, unsigned int position);
unsigned int count_greater_than(COLUMN1 *col, void *value);
unsigned int count_lower_than(COLUMN1 *col, void *value);
unsigned int count_equal_to(COLUMN1 *col, void *value);



#endif
