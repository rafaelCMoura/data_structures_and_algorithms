#include <stdio.h>

#include "utils.h"

void print(int *array, int size){
    printf("[");
    for (int i = 0; i < size; i++) {
        if(i < size-1){
            printf("%d", array[i]);
            printf(", ");
        } else {
            printf("%d", array[i]);
            printf("]\n");
        }
    }
}
