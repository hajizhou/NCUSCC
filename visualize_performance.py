import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# 设置中文字体（如果需要显示中文）
plt.rcParams['font.sans-serif'] = ['DejaVu Sans']
plt.rcParams['axes.unicode_minus'] = False

# 读取数据
data = {
    '优化级别': ['-O0', '-O1', '-O2', '-O3', '-Ofast'],
    '递归快速排序': [0.004, 0.004, 0.005, 0.005, 0.005],
    '非递归快速排序': [0.091, 0.091, 0.091, 0.089, 0.089],
    '并行归并排序': [0.015, 0.014, 0.017, 0.017, 0.012],
    '串行归并排序': [0.010, 0.009, 0.010, 0.009, 0.009]
}

df = pd.DataFrame(data)

# 创建性能对比图
plt.figure(figsize=(12, 8))

# 子图1：所有算法在不同优化级别的性能
plt.subplot(2, 2, 1)
x = np.arange(len(df['优化级别']))
width = 0.2

plt.bar(x - 1.5*width, df['递归快速排序'], width, label='递归快速排序', alpha=0.8)
plt.bar(x - 0.5*width, df['非递归快速排序'], width, label='非递归快速排序', alpha=0.8)
plt.bar(x + 0.5*width, df['并行归并排序'], width, label='并行归并排序', alpha=0.8)
plt.bar(x + 1.5*width, df['串行归并排序'], width, label='串行归并排序', alpha=0.8)

plt.xlabel('优化级别')
plt.ylabel('执行时间 (秒)')
plt.title('不同优化级别下排序算法性能对比')
plt.xticks(x, df['优化级别'])
plt.legend()
plt.grid(True, alpha=0.3)

# 子图2：递归快速排序在不同优化级别的表现
plt.subplot(2, 2, 2)
plt.plot(df['优化级别'], df['递归快速排序'], 'o-', linewidth=2, markersize=8, label='递归快速排序')
plt.xlabel('优化级别')
plt.ylabel('执行时间 (秒)')
plt.title('递归快速排序性能变化')
plt.grid(True, alpha=0.3)
plt.legend()

# 子图3：归并排序算法对比
plt.subplot(2, 2, 3)
plt.plot(df['优化级别'], df['并行归并排序'], 's-', linewidth=2, markersize=8, label='并行归并排序')
plt.plot(df['优化级别'], df['串行归并排序'], '^-', linewidth=2, markersize=8, label='串行归并排序')
plt.xlabel('优化级别')
plt.ylabel('执行时间 (秒)')
plt.title('归并排序算法性能对比')
plt.grid(True, alpha=0.3)
plt.legend()

# 子图4：优化级别对性能的影响程度
plt.subplot(2, 2, 4)
improvement = (df.iloc[0, 1:] - df.iloc[-1, 1:]) / df.iloc[0, 1:] * 100
plt.bar(improvement.index, improvement.values, color=['skyblue', 'lightcoral', 'lightgreen', 'gold'])
plt.xlabel('算法类型')
plt.ylabel('性能提升百分比 (%)')
plt.title('Ofast 相比 O0 的性能提升')
plt.xticks(rotation=45)
plt.grid(True, alpha=0.3)

plt.tight_layout()
plt.savefig('performance_analysis.png', dpi=300, bbox_inches='tight')
plt.savefig('performance_analysis.pdf', bbox_inches='tight')
plt.show()

# 输出数据分析
print("\n=== 性能数据分析 ===")
print(f"数据量: 100,000 条随机整数")
print(f"测试环境: Ubuntu 22.04, GCC 13.1.0")
print("\n关键发现:")
print("1. 递归快速排序在所有优化级别中表现最佳")
print("2. 非递归快速排序由于栈操作开销，性能较差")
print("3. 对于10万数据量，串行归并排序优于并行版本")
print("4. 高级优化级别(Ofast)对归并排序有显著提升")

# 保存详细数据表格
print("\n详细性能数据:")
print(df.to_string(index=False))

# 保存到CSV
df.to_csv('detailed_performance_data.csv', index=False)
print("\n详细数据已保存到: detailed_performance_data.csv")
print("图表已保存为: performance_analysis.png 和 performance_analysis.pdf")
