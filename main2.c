#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Column.c"
#include "CDataframe.c"

#define REALLOC_SIZE 256

void menu1() {
    int x;
    printf("Menu for part 1");
    printf("Press 1 for our column part and 2 for our Cdataframe");
}

void case1(){
    printf("1 - Create a column");
    printf("2 - Insert a value");
    printf("3 - Delete a column");
    printf("4 - Print a column");
    printf("5 - Number of occurrences of x");
    printf("6 - Value at index x");
    printf("7 - Number of value greater than x");
    printf("8 - Number of value smaller than x");
    printf("9 - Number of values equal to x");
}

void case2(){
    printf("1 - Create a dataframe");
    printf("2 - Fill the dataframe");
    printf("3 - Hard fill the dataframe");
    printf("4 - Display the dataframe");
    printf("5 - Display partial rows");
    printf("6 - Display partial columns");
    printf("7 - Add a row");
    printf("8 - Delete a row");
    printf("9 - Add a column");
    printf("10 - Delete a column");
    printf("11 - Rename a column");
    printf("12 - Search value x");
    printf("13 - Value at cell x");
    printf("14 - Display the columns names");
    printf("15 - Display the number of rows");
    printf("16 - Display the number of columns");
    printf("17 - Number of cells equal to x");
    printf("18 - Number of cells greater than x");
    printf("19 - Number of cells smaller than x");
}

int main() {
    int choice, x, val;
    char name[256];
    COLUMN *col = NULL;
    while(1) {
        menu1();
        printf("Enter your choice");
        scanf("%d", &x);
        switch (x) {
            case(1):
                case1();
                printf("Enter your choice");
                scanf("%d",&choice);
                switch (choice) {
                    case(1):
                        printf("Enter the title of the column");
                        scanf("%s", name);
                        create_column(name);
                        break;
                    case(2):
                        if (col == NULL){
                            printf("Create a column first");
                            break;
                        }
                        else{
                            printf("Enter a value");
                            scanf("%d", &val);
                            insert_value(col, val);
                            break;
                        }


                }



        }


    }
}