#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

// 交换两个元素
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 三数取中法选择pivot
int median_of_three(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;
    
    if (arr[low] > arr[mid])
        swap(&arr[low], &arr[mid]);
    if (arr[low] > arr[high])
        swap(&arr[low], &arr[high]);
    if (arr[mid] > arr[high])
        swap(&arr[mid], &arr[high]);
    
    return mid;
}

// 随机选择pivot
int random_pivot(int arr[], int low, int high) {
    srand(time(NULL));
    return low + rand() % (high - low + 1);
}

// 分区函数
int partition(int arr[], int low, int high, int pivot_type) {
    int pivot_index;
    
    switch(pivot_type) {
        case 1: // 随机pivot
            pivot_index = random_pivot(arr, low, high);
            break;
        case 2: // 三数取中
            pivot_index = median_of_three(arr, low, high);
            break;
        default: // 默认使用最后一个元素
            pivot_index = high;
    }
    
    swap(&arr[pivot_index], &arr[high]);
    int pivot = arr[high];
    
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// 递归快速排序
void quick_sort_recursive(int arr[], int low, int high, int pivot_type) {
    if (low < high) {
        int pi = partition(arr, low, high, pivot_type);
        quick_sort_recursive(arr, low, pi - 1, pivot_type);
        quick_sort_recursive(arr, pi + 1, high, pivot_type);
    }
}

// 栈结构用于非递归版本
typedef struct {
    int low;
    int high;
} StackItem;

// 非递归快速排序
void quick_sort_iterative(int arr[], int low, int high, int pivot_type) {
    // 创建栈
    StackItem* stack = malloc((high - low + 1) * sizeof(StackItem));
    int top = -1;
    
    // 初始范围入栈
    stack[++top].low = low;
    stack[top].high = high;
    
    while (top >= 0) {
        // 弹出当前范围
        low = stack[top].low;
        high = stack[top--].high;
        
        if (low < high) {
            int pi = partition(arr, low, high, pivot_type);
            
            // 将左半部分入栈
            if (pi - 1 > low) {
                stack[++top].low = low;
                stack[top].high = pi - 1;
            }
            
            // 将右半部分入栈
            if (pi + 1 < high) {
                stack[++top].low = pi + 1;
                stack[top].high = high;
            }
        }
    }
    
    free(stack);
}
