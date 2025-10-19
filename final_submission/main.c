#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utils.h"

// 生成测试数据
void generate_random_data(int arr[], int n, const char* filename) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000000;  // 生成0-999999的随机数
    }
    
    FILE* file = fopen(filename, "w");
    if (file) {
        for (int i = 0; i < n; i++) {
            fprintf(file, "%d\n", arr[i]);
        }
        fclose(file);
        printf("生成 %d 条测试数据到 %s\n", n, filename);
    }
}

// 从文件读取数据
void read_data_from_file(int arr[], int n, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file) {
        for (int i = 0; i < n; i++) {
            fscanf(file, "%d", &arr[i]);
        }
        fclose(file);
        printf("从 %s 读取 %d 条数据\n", filename, n);
    } else {
        printf("无法打开文件 %s\n", filename);
    }
}

// 检查数组是否已排序
int is_sorted(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return 0;
        }
    }
    return 1;
}

// 打印数组（用于调试）
void print_array(int arr[], int n) {
    for (int i = 0; i < n && i < 20; i++) {
        printf("%d ", arr[i]);
    }
    if (n > 20) printf("...");
    printf("\n");
}

// 复制数组
void copy_array(int dest[], int src[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

int main() {
    const int DATA_SIZE = 100000;  // 10万条数据
    const char* FILENAME = "test_data.txt";
    
    int* original_data = malloc(DATA_SIZE * sizeof(int));
    int* test_data = malloc(DATA_SIZE * sizeof(int));
    
    printf("=== 排序算法测试 ===\n");
    
    // 1. 生成测试数据
    printf("\n1. 生成测试数据...\n");
    generate_random_data(original_data, DATA_SIZE, FILENAME);
    
    // 2. 测试快速排序（递归版本）
    printf("\n2. 测试快速排序（递归版本）...\n");
    read_data_from_file(test_data, DATA_SIZE, FILENAME);
    
    clock_t start = clock();
    quick_sort_recursive(test_data, 0, DATA_SIZE - 1, 2);  // 使用三数取中
    clock_t end = clock();
    
    printf("快速排序（递归）耗时: %.3f 秒\n", (double)(end - start) / CLOCKS_PER_SEC);
    printf("排序结果: %s\n", is_sorted(test_data, DATA_SIZE) ? "正确" : "错误");
    
    // 3. 测试快速排序（非递归版本）
    printf("\n3. 测试快速排序（非递归版本）...\n");
    read_data_from_file(test_data, DATA_SIZE, FILENAME);
    
    start = clock();
    quick_sort_iterative(test_data, 0, DATA_SIZE - 1, 1);  // 使用随机pivot
    end = clock();
    
    printf("快速排序（非递归）耗时: %.3f 秒\n", (double)(end - start) / CLOCKS_PER_SEC);
    printf("排序结果: %s\n", is_sorted(test_data, DATA_SIZE) ? "正确" : "错误");
    
    // 4. 测试并行归并排序
    printf("\n4. 测试并行归并排序...\n");
    read_data_from_file(test_data, DATA_SIZE, FILENAME);
    
    start = clock();
    merge_sort_parallel(test_data, 0, DATA_SIZE - 1, 1000);  // 阈值设为1000
    end = clock();
    
    printf("并行归并排序耗时: %.3f 秒\n", (double)(end - start) / CLOCKS_PER_SEC);
    printf("排序结果: %s\n", is_sorted(test_data, DATA_SIZE) ? "正确" : "错误");
    
    // 5. 测试串行归并排序（对比）
    printf("\n5. 测试串行归并排序（对比）...\n");
    read_data_from_file(test_data, DATA_SIZE, FILENAME);
    
    start = clock();
    merge_sort_serial(test_data, 0, DATA_SIZE - 1);
    end = clock();
    
    printf("串行归并排序耗时: %.3f 秒\n", (double)(end - start) / CLOCKS_PER_SEC);
    printf("排序结果: %s\n", is_sorted(test_data, DATA_SIZE) ? "正确" : "错误");
    
    free(original_data);
    free(test_data);
    
    return 0;
}
