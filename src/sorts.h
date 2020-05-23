#ifndef SORTS_H_
#define SORTS_H_

// O(n²)
void bubble_sort (int *array, int size);
void insertion_sort (int *array, int size);
void selection_sort (int *array, int size);

// O(n (lg(n))²)
void shell_sort (int *array, int size);

// O(n lg(n))
void merge_sort (int *array, int left_start, int right_end);
//void quick_sort (int *array, int size);
//void heap_sort (int *array, int size);

#endif
