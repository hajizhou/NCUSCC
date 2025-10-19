#!/bin/bash

echo "=== 创建最终提交包 ==="

# 创建提交目录
mkdir -p final_submission

# 复制所有必需文件
echo "复制源代码..."
cp main.c quick_sort.c merge_sort.c utils.h final_submission/

echo "复制测试脚本..."
cp detailed_performance_test.sh visualize_performance_en.py final_submission/

echo "复制实验结果..."
cp performance_analysis_en.png performance_analysis_en.pdf final_submission/
cp detailed_performance_data_en.csv text_performance_report.txt final_submission/

echo "复制实验报告..."
cp EXPERIMENT_REPORT.md final_submission/

# 创建项目说明文件
cat > final_submission/README.md << 'README_EOF'
# 排序算法性能分析实验 - 最终提交

## 项目信息
- **课程**: [填写课程名称]
- **学生**: [填写你的姓名]
- **学号**: [填写学号]
- **日期**: 2024年10月

## 项目结构
- **源代码**: main.c, quick_sort.c, merge_sort.c, utils.h
- **测试脚本**: detailed_performance_test.sh, visualize_performance_en.py
- **实验结果**: performance_analysis_en.png, performance_analysis_en.pdf
- **数据文件**: detailed_performance_data_en.csv, text_performance_report.txt
- **实验报告**: EXPERIMENT_REPORT.md

## 使用方法
```bash
# 编译
gcc -fopenmp -O2 main.c quick_sort.c merge_sort.c -o sorting_test

# 运行
./sorting_test

# 性能测试
./detailed_performance_test.sh

# 生成图表
python3 visualize_performance_en.py
README_EOF

echo "✅ 最终提交包创建完成: final_submission/"
echo""
echo"包含文件:"
ls-la final_submission/
