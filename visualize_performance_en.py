import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# 设置字体为系统默认，避免中文问题
plt.rcParams['font.sans-serif'] = ['DejaVu Sans']
plt.rcParams['axes.unicode_minus'] = False

# 使用你的实际测试数据
data = {
    'Optimization': ['-O0', '-O1', '-O2', '-O3', '-Ofast'],
    'QuickSort Recursive': [0.004, 0.004, 0.005, 0.005, 0.005],
    'QuickSort Iterative': [0.091, 0.091, 0.091, 0.089, 0.089],
    'MergeSort Parallel': [0.015, 0.014, 0.017, 0.017, 0.012],
    'MergeSort Serial': [0.010, 0.009, 0.010, 0.009, 0.009]
}

df = pd.DataFrame(data)

# 创建性能对比图
plt.figure(figsize=(14, 10))

# 子图1：所有算法在不同优化级别的性能
plt.subplot(2, 2, 1)
x = np.arange(len(df['Optimization']))
width = 0.2

plt.bar(x - 1.5*width, df['QuickSort Recursive'], width, label='QuickSort Recursive', alpha=0.8, color='skyblue')
plt.bar(x - 0.5*width, df['QuickSort Iterative'], width, label='QuickSort Iterative', alpha=0.8, color='lightcoral')
plt.bar(x + 0.5*width, df['MergeSort Parallel'], width, label='MergeSort Parallel', alpha=0.8, color='lightgreen')
plt.bar(x + 1.5*width, df['MergeSort Serial'], width, label='MergeSort Serial', alpha=0.8, color='gold')

plt.xlabel('Optimization Level')
plt.ylabel('Execution Time (seconds)')
plt.title('Sorting Algorithms Performance Comparison')
plt.xticks(x, df['Optimization'])
plt.legend()
plt.grid(True, alpha=0.3)

# 子图2：递归快速排序在不同优化级别的表现
plt.subplot(2, 2, 2)
plt.plot(df['Optimization'], df['QuickSort Recursive'], 'o-', linewidth=2, markersize=8, 
         label='QuickSort Recursive', color='skyblue')
plt.xlabel('Optimization Level')
plt.ylabel('Execution Time (seconds)')
plt.title('QuickSort Recursive Performance')
plt.grid(True, alpha=0.3)
plt.legend()

# 子图3：归并排序算法对比
plt.subplot(2, 2, 3)
plt.plot(df['Optimization'], df['MergeSort Parallel'], 's-', linewidth=2, markersize=8, 
         label='MergeSort Parallel', color='lightgreen')
plt.plot(df['Optimization'], df['MergeSort Serial'], '^-', linewidth=2, markersize=8, 
         label='MergeSort Serial', color='gold')
plt.xlabel('Optimization Level')
plt.ylabel('Execution Time (seconds)')
plt.title('MergeSort Algorithms Comparison')
plt.grid(True, alpha=0.3)
plt.legend()

# 子图4：优化级别对性能的影响程度
plt.subplot(2, 2, 4)
improvement = (df.iloc[0, 1:] - df.iloc[-1, 1:]) / df.iloc[0, 1:] * 100
colors = ['skyblue', 'lightcoral', 'lightgreen', 'gold']
plt.bar(range(len(improvement)), improvement.values, color=colors)
plt.xlabel('Algorithms')
plt.ylabel('Performance Improvement (%)')
plt.title('Performance Improvement: Ofast vs O0')
plt.xticks(range(len(improvement)), improvement.index, rotation=45)
plt.grid(True, alpha=0.3)

# 在图表上添加数值标签
for i, v in enumerate(improvement.values):
    plt.text(i, v + 0.5, f'{v:.1f}%', ha='center', va='bottom')

plt.tight_layout()
plt.savefig('performance_analysis_en.png', dpi=300, bbox_inches='tight')
plt.savefig('performance_analysis_en.pdf', bbox_inches='tight')
plt.show()

# 输出数据分析
print("\n=== Performance Analysis ===")
print(f"Data Size: 100,000 random integers")
print(f"Test Environment: Ubuntu 22.04, GCC 13.1.0")
print("\nKey Findings:")
print("1. Recursive QuickSort performs best across all optimization levels")
print("2. Iterative QuickSort has higher overhead due to stack operations")
print("3. For 100K data size, serial MergeSort outperforms parallel version")
print("4. Higher optimization levels (Ofast) significantly improve MergeSort")

# 保存详细数据表格
print("\nDetailed Performance Data:")
print(df.to_string(index=False))

# 保存到CSV
df.to_csv('detailed_performance_data_en.csv', index=False)
print("\nDetailed data saved to: detailed_performance_data_en.csv")
print("Charts saved as: performance_analysis_en.png and performance_analysis_en.pdf")

# 创建性能总结表
print("\n" + "="*50)
print("PERFORMANCE SUMMARY")
print("="*50)
print(f"{'Algorithm':<25} {'Best Time (s)':<15} {'Optimization Level':<20}")
print("-"*50)
for col in df.columns[1:]:
    best_time = df[col].min()
    best_level = df['Optimization'][df[col].idxmin()]
    print(f"{col:<25} {best_time:<15.3f} {best_level:<20}")
print("="*50)
