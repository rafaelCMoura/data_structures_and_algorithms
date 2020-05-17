#include <stdio.h>
#include "src/sorts.h"
#include "src/unit_tests.h"

void test_bubble_sort(){
    int array [5] = {3, 4, 2, 5, 1}; 
    int expected_output [5] = {1, 2, 3, 4, 5};

    int *array_pointer = array;
    int *expected_output_pointer = expected_output;

    bubble_sort(array_pointer, 5);

    printf("\nBubble Sort\t");
    assert_array(array_pointer, expected_output_pointer, 5);
}

void test_insertion_sort(){
    int array [5] = {3, 4, 2, 5, 1}; 
    int expected_output [5] = {1, 2, 3, 4, 5};

    int *array_pointer = array;
    int *expected_output_pointer = expected_output;

    insertion_sort(array_pointer, 5);

    printf("\nInsertion Sort\t");
    assert_array(array_pointer, expected_output_pointer, 5);
}

void test_merge_sort(){
    int array [5] = {3, 4, 2, 5, 1}; 
    int expected_output [5] = {1, 2, 3, 4, 5};

    int *array_pointer = array;
    int *expected_output_pointer = expected_output;

    merge_sort(array_pointer, 0, 4);

    printf("\nMerge Sort\t");
    assert_array(array_pointer, expected_output_pointer, 5);
}


int main(void) {
    
    printf("\nRunning Tests ...\n");
    test_bubble_sort();
    test_insertion_sort();
    test_merge_sort();
    printf("\n");

    return 0;
}
