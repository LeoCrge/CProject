//
// Created by Carouge on 29/03/2024.
//

#define REALOC_SIZE 256


typedef struct {
    char *title;
    int *data;
    int physical_size;
    int logical_size;
} COLUMN;