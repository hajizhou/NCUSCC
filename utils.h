#ifndef UTILS_H
#define UTILS_H

// 函数声明
void generate_random_data(int arr[], int n, const char* filename);
void read_data_from_file(int arr[], int n, const char* filename);
int is_sorted(int arr[], int n);
void print_array(int arr[], int n);
void copy_array(int dest[], int src[], int n);

// 快速排序函数声明
void quick_sort_recursive(int arr[], int low, int high, int pivot_type);
void quick_sort_iterative(int arr[], int low, int high, int pivot_type);

// 归并排序函数声明
void merge_sort_serial(int arr[], int left, int right);
void merge_sort_parallel(int arr[], int left, int right, int threshold);

#endif
