#include "sorts.h"

/*
void merge (int *array, int size, int left_start, int left_end, int right_end){
    const int left_size = left_end - left_start + 1;
    const int right_size = right_end - left_end;

    int left[left_size];
    int right[right_size];

    // Alocar memoria e criar vetor left
    for (int i = 0; i < left_size; i++) {
        left[i] = array[left_start + i - 1];
    }
    
    // Alocar memoria e criar vetor right
    for (int j = 0; j < right_size; j++) {
        left[j] = array[left_end + j];
    }
    
    left[left_size] = INFINITY;
    right[right_size] = INFINITY;

    int i = 0;
    int j = 0;

    for (int k = left_start; k < right_end; k++) {
        if (left[i] <= right[j]) {
            array[k] = left[i];
            i = i + 1;
        } else {
            array[k] = right[j];
            j = j + 1;
        }
    }

}

void merge_sort(int *array, int size){
    
}
*/

void insertion_sort (int *array, int size) {
    int i, key;

    for (int j = 1; j < size; j++) {
        key = array[j];
        i = j - 1;

        while (i >= 0 && array[i] > key) {
            array[i + 1] = array[i];
            i = i - 1;
        }
        array[i + 1] = key;
    }
}


void bubble_sort (int *array, int size) {
    int aux;

    for (int i = 1; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (array[j] > array[j + 1]) {
                aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
            }
        }
    }
}

