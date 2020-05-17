#include <stdlib.h>
#include <math.h>

#include "sorts.h"

void swap(int *array, int i, int j){
    int aux = array[i];
    array[i] = array[j];
    array[j] = aux;
}


void merge (int *array, int left_start, int left_end, int right_end) {
    const int right_start = left_end + 1;
    const int left_size = left_end - left_start + 1;
    const int right_size = right_end - right_start + 1;

    int *left;
    int *right;

    left = malloc((left_size + 1)*sizeof(int));
    right = malloc((right_size + 1)*sizeof(int));
    
    for (int i = 0; i < left_size; i++) {
        left[i] = array[left_start + i];
    }
    
    for (int j = 0; j < right_size; j++) {
        right[j] = array[right_start + j];
    }
    
    left[left_size] = (int) INFINITY;
    right[right_size] = (int) INFINITY;

    int i = 0;
    int j = 0;

    for (int k = left_start; k <= right_end; k++) {
        if (left[i] <= right[j]) {
            array[k] = left[i];
            i = i + 1;
        } else {
            array[k] = right[j];
            j = j + 1;
        }
    }

    free(left);
    free(right);
}


void merge_sort(int *array, int left_start, int right_end) {
    if (left_start < right_end) {
        int left_end = (left_start + right_end)/2;

        merge_sort(array, left_start, left_end);
        merge_sort(array, left_end + 1, right_end);
        merge(array, left_start, left_end, right_end);
    }
}


void insertion_sort (int *array, int size) {
    for (int i = 1; i < size; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if(array[j] > array[j + 1]) {
                swap(array, j, j + 1);
            }
        }
    }
}


void bubble_sort (int *array, int size) {
    for (int i = 1; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(array, j, j + 1);
            }
        }
    }
}


void selection_sort(int *array, int size){
    int min_index = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[min_index]) {
                min_index = j;
            }
        }
        swap(array, i, min_index);
    }
}

