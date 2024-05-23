#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "part1.h"
#include "part2.h"

int main() {
    int choice;

    printf("\nMain Menu:\n");
    printf("1. Execute Project Part 1\n");
    printf("2. Execute Project Part 2\n");
    printf("0. Exit\n");
    printf("Enter your choice: \n");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            part1();
        case 2:
            part2();
        case 0:
            exit(EXIT_SUCCESS);
    }
}