#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

#include "src/sorts.h"
#include "src/unit_tests.h"
#include "src/utils.h"

int comparation_function (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void mock_sort_random_array(int *unsorted, int *sorted, int size, int min, int max ){
    srand(time(0));
    
    for (int i = 0; i < size; i++) {
        unsorted[i] = (rand() % (max - min + 1)) + min;
        sorted[i] = unsorted[i];
    }

    qsort(sorted, size, sizeof(int), comparation_function);
}

void test_bubble_sort(){
    int size = 10;
    int min_value = 1;
    int max_value = 10;

    int *input;
    int *output;

    input = malloc(size*sizeof(int));
    output = malloc(size*sizeof(int));

    mock_sort_random_array(input, output, size, min_value, max_value);

    printf("\nBubble Sort\t");
    bubble_sort(input, size);
    assert_array(input, output, size);

    free(input);
    free(output);
}

void test_insertion_sort(){
    int size = 10;
    int min_value = 1;
    int max_value = 10;

    int *input;
    int *output;

    input = malloc(size*sizeof(int));
    output = malloc(size*sizeof(int));

    mock_sort_random_array(input, output, size, min_value, max_value);

    printf("\nInsertion Sort\t");
    insertion_sort(input, size);
    assert_array(input, output, size);

    free(input);
    free(output);
}

void test_merge_sort(){
    int size = 10;
    int min_value = 1;
    int max_value = 10;

    int *input;
    int *output;

    input = malloc(size*sizeof(int));
    output = malloc(size*sizeof(int));

    mock_sort_random_array(input, output, size, min_value, max_value);

    printf("\nMerge Sort\t");
    merge_sort(input, 0, size-1);
    assert_array(input, output, size);

    free(input);
    free(output);
}

void test_selection_sort(){
    int size = 10;
    int min_value = 1;
    int max_value = 10;

    int *input;
    int *output;

    input = malloc(size*sizeof(int));
    output = malloc(size*sizeof(int));

    mock_sort_random_array(input, output, size, min_value, max_value);

    printf("\nSelection Sort\t");
    selection_sort(input, size);
    assert_array(input, output, size);

    free(input);
    free(output);
}

int main(void) {
    
    printf("\nRunning Tests ...\n");
    test_bubble_sort();
    test_insertion_sort();
    test_merge_sort();
    test_selection_sort();
    printf("\n");

    return 0;
}
