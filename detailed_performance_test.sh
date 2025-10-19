#!/bin/bash

echo "=== 详细性能测试 ==="
echo "优化级别,递归快速排序,非递归快速排序,并行归并排序,串行归并排序" > performance_results.csv

# 编译不同优化级别的版本
echo "编译不同优化级别的程序..."
gcc -fopenmp -O0 main.c quick_sort.c merge_sort.c -o sorting_O0
gcc -fopenmp -O1 main.c quick_sort.c merge_sort.c -o sorting_O1
gcc -fopenmp -O2 main.c quick_sort.c merge_sort.c -o sorting_O2
gcc -fopenmp -O3 main.c quick_sort.c merge_sort.c -o sorting_O3
gcc -fopenmp -Ofast main.c quick_sort.c merge_sort.c -o sorting_Ofast

# 测试每个版本并记录数据
for level in O0 O1 O2 O3 Ofast; do
    echo "测试优化级别 -$level"
    
    # 运行程序并提取时间数据
    result=$(./sorting_$level | grep "耗时" | awk '{print $4}')
    
    # 将结果转换为数组
    times=($result)
    
    # 写入CSV文件
    echo "-$level,${times[0]},${times[1]},${times[2]},${times[3]}" >> performance_results.csv
done

# 清理
rm -f sorting_O0 sorting_O1 sorting_O2 sorting_O3 sorting_Ofast

echo "性能数据已保存到 performance_results.csv"
cat performance_results.csv
