#include <stdio.h>
#include "unit_tests.h"
#include "utils.h"

void assert_array(int *array, int *expected_array, int size){

    for (int i = 0; i < size; i++) {
        if(array[i]!=expected_array[i]){
            printf("\t[\033[0;31mfailed\033[0m]");
            printf("\nProvided array: ");
            print(array, size);
            printf("\nExpected array: ");
            print(expected_array, size);
            return;
        }
    }
    printf("\t[\033[0;32mpassed\033[0m]");
}
