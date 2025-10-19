#!/bin/bash

echo "=== 不同优化级别性能测试 ==="

# 编译不同优化级别的版本
echo "编译不同优化级别的程序..."
gcc -fopenmp -O0 main.c quick_sort.c merge_sort.c -o sorting_O0
gcc -fopenmp -O1 main.c quick_sort.c merge_sort.c -o sorting_O1
gcc -fopenmp -O2 main.c quick_sort.c merge_sort.c -o sorting_O2
gcc -fopenmp -O3 main.c quick_sort.c merge_sort.c -o sorting_O3
gcc -fopenmp -Ofast main.c quick_sort.c merge_sort.c -o sorting_Ofast

echo -e "\n=== 测试开始 ==="

# 测试每个版本
for level in O0 O1 O2 O3 Ofast; do
    echo -e "\n=== 优化级别 -$level ==="
    ./sorting_$level | grep "耗时"
done

# 清理
rm -f sorting_O0 sorting_O1 sorting_O2 sorting_O3 sorting_Ofast

echo -e "\n=== 性能测试完成 ==="
