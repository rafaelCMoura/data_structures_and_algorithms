#ifndef SORTS_H_
#define SORTS_H_

// O(n²)
void bubble_sort (int *array, int size);
void insertion_sort (int *array, int size);
void selection_sort (int *array, int size);

// O(n (lg(n))²), but it depends of the diminishing increment sequence used
void shell_sort (int *array, int size, int type);

// O(n lg(n))
void merge_sort (int *array, int left_start, int right_end);
//void quick_sort (int *array, int size);
//void heap_sort (int *array, int size);
// Binary insertion (John Mauchly 1946) Knuth vol 3 pag 82
// Teo way insertion sort Knuth vol 3 pag 83

#endif
