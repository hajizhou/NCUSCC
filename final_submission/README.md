# 排序算法性能分析实验

## 最终提交包

包含所有源代码、测试脚本、实验结果和实验报告。

## 文件清单
- main.c, quick_sort.c, merge_sort.c, utils.h - 源代码
- detailed_performance_test.sh - 性能测试脚本
- visualize_performance_en.py - 可视化脚本
- performance_analysis_en.png/.pdf - 性能图表
- *.csv - 性能数据文件
- EXPERIMENT_REPORT.md - 实验报告

## 使用方法
gcc -fopenmp -O2 main.c quick_sort.c merge_sort.c -o sorting_test
./sorting_test
