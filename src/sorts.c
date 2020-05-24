#include <stdlib.h>
#include <stdio.h>
#include "sorts.h"
#include "utils.h"

void swap (int *array, int i, int j) {
    int aux = array[i];
    array[i] = array[j];
    array[j] = aux;
}


void selection_sort (int *array, int size) {
    int min_index;
    for (int i = 0; i < size - 1; i++) {
        min_index = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[min_index]) {
                min_index = j;
            }
        }
        swap(array, i, min_index);
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


void insertion_sort (int *array, int size) {
    for (int i = 1; i < size; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if(array[j] > array[j + 1]) {
                swap(array, j, j + 1);
            }
        }
    }
}


void increment_insertion_sort(int *array, int size, int increment) {
    for (int i = increment; i < size; i++) {
        for (int j = i - increment; j >= 0; j--) {
            if(array[j] > array[j + increment]) {
                swap(array, j, j + increment);
            }
        }
    }
}

// The Art of Computer Programing Vol 3 page 95
int knuth_increment(int s) {
    int h;
    if (s > 1) {
        h = 3*knuth_increment(s - 1) + 1;
    } else {
        h = 1;
    }
    return h;
}

// The Art of Computer Programing Vol 3 page 93
int sedgewick_increment(int s) {
    int h;
    if(s % 2 == 0) {
        h = 9*(2^s - 2^(s/2)) + 1;
    } else {
        h = 8*(2^s - 2^((s+1)/2)) + 1;
    }
    return h;
}

// Original Donald L. Shell's suggestion. The Art of Computer Programing Vol 3 page 93
int shell_increment(int s) {
    int h;
    if(s / 2 > 1) {
        h = s / 2;
    } else {
        h = 1;
    }
    return h;
}

int get_increment_sequence_size(int size, int type) {

    int sequence_size = 0;
    int increment = size;

    while (increment > 1) {
        if (type == 1){
            increment = shell_increment(increment);
        } else if ( type == 2) {
            increment = knuth_increment(increment);
        } else if ( type == 3) {
            increment = sedgewick_increment(increment);
        }

        sequence_size = sequence_size + 1;
    }

    return sequence_size;
}

void create_increment_sequence(int size, int type, int *sequence) {

    int increment = size;
    int i = 0;

    while (increment > 1) {
        if (type == 1){
            increment = shell_increment(increment);
        } else if ( type == 2) {
            increment = knuth_increment(increment);
        } else {
            increment = sedgewick_increment(increment);
        }

        sequence[i] = increment;
        i = i + 1;
    }
}

void shell_sort(int *array, int size, int type) {
    
    int increment_sequence_size = get_increment_sequence_size(size, type);
    
    int *increment_sequence;
    increment_sequence = malloc(increment_sequence_size*sizeof(int));

    create_increment_sequence(size, type, increment_sequence);

    //print(increment_sequence, increment_sequence_size);

    for (int i = (increment_sequence_size-1); i >=0; i--) {
        increment_insertion_sort(array, size, increment_sequence[i]);
    }

    free(increment_sequence);
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
    
    const int INF = 1000000000;

    left[left_size] = INF;
    right[right_size] = INF;

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


void merge_sort (int *array, int left_start, int right_end) {
    if (left_start < right_end) {
        int left_end = (left_start + right_end)/2;

        merge_sort(array, left_start, left_end);
        merge_sort(array, left_end + 1, right_end);
        merge(array, left_start, left_end, right_end);
    }
}
