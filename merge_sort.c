#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "utils.h"

// 合并两个有序数组
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // 创建临时数组
    int* L = malloc(n1 * sizeof(int));
    int* R = malloc(n2 * sizeof(int));
    
    // 拷贝数据到临时数组
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    // 合并临时数组
    i = 0; j = 0; k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // 拷贝剩余元素
    while (i < n1) {
        arr[k] = L[i];
        i++; k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++; k++;
    }
    
    free(L);
    free(R);
}

// 串行归并排序
void merge_sort_serial(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        merge_sort_serial(arr, left, mid);
        merge_sort_serial(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// 并行归并排序
void merge_sort_parallel(int arr[], int left, int right, int threshold) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        if (right - left > threshold) {
            #pragma omp parallel sections
            {
                #pragma omp section
                merge_sort_parallel(arr, left, mid, threshold);
                
                #pragma omp section  
                merge_sort_parallel(arr, mid + 1, right, threshold);
            }
        } else {
            // 数据量小，使用串行版本
            merge_sort_serial(arr, left, mid);
            merge_sort_serial(arr, mid + 1, right);
        }
        
        merge(arr, left, mid, right);
    }
}
