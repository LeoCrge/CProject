#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REALLOC_SIZE 256

typedef struct {
    char *title;
    int *data;
    int physical_size;
    int logical_size;
} COLUMN;

COLUMN *create_column(char *title){
    COLUMN *col = (COLUMN *)malloc(sizeof(COLUMN));
    if (col == NULL) {
        printf("Memory allocation failed \n");
        exit(EXIT_FAILURE);
    }
    col->title = strdup(title);
    col-> data =NULL;
    col-> physical_size =0;
    col-> logical_size = 0 ;
    return col;
}

int insert_value(COLUMN *col, int value){
    if (!col) return 0;
    if (col->physical_size <= col->logical_size){
        int* loc = realloc(col->data, (col->physical_size + REALLOC_SIZE) * sizeof(int));
        if (loc == NULL){
            printf("Memory allocation failed \n");
            return 0;
        }
        col->data =loc;
        col->physical_size +=REALLOC_SIZE;
    }
    col->data[col->logical_size++] = value;
    return 1;
}

void delete_column(COLUMN **col){
    if (col==NULL || *col==NULL){
        return;
    }
    free((*col)->title);
    free((*col)->data);
    free(*col);
    *col=NULL;
}

void print_col(COLUMN *col){
    if (col==NULL){
        return;
    }
    printf("Column: %s \n", col->title);
    for (int i=0; i<col->logical_size; i++){
        printf("[%d] %d \n", i, col->data[i]);
    }
}

int num_occurrences(COLUMN*col, int x){
    int occurrences = 0;
    if (col==NULL){
        return 0;
    }
    for (int i=0; i<col->logical_size;i++){
        if (x==col->data[i]){
            occurrences++;
        }
    }
    return occurrences;
}

int value_at_x(COLUMN*col, int x){
    if (col==NULL||x<0||x>=col->logical_size){
        printf("Invalid position");
        exit(EXIT_FAILURE);
    }
    return col->data[x];
}

int val_greater_x(COLUMN*col, int x){
    int count = 0;
    if (!col) return 0;
    for (int i=0; i<col->logical_size; i++){
        if (x<col->data[i]){
            count++;
        }

    }
    return count;
}

int val_smaller_than(COLUMN*col, int x){
    int count=0;
    if (col==NULL){
        return 0;
    }
    for (int i=0; i<col->logical_size; i++){
        if (x>col->data[i]){
            count++;
        }
    }
    return count;
}

int values_equal_to(COLUMN*col, int x){
    int count=0;
    if (col==NULL){
        return 0;
    }
    for (int i=0; i<col->logical_size; i++){
        if (x==col->data[i]){
            count++;
        }
    }
    return count;
}
