#include <stdio.h>
#include "unit_tests.h"


void assert_array(int *array, int *expected_array, int size){

    for (int i = 0; i < size; i++) {
        if(array[i]!=expected_array[i]){
            printf("\t[\033[0;31mfailed\033[0m]");
            printf("\nProvided array: [");
            for (int j = 0; j < size; j++) {
                printf("%d", array[j]);
            }
            printf("]");
            printf("\nExpected array: [");
            for (int j = 0; j < size; j++) {
                printf("%d", expected_array[j]);
            }
            printf("]\n");
            return;
        }
    }
    printf("\t[\033[0;32mpassed\033[0m]");
}