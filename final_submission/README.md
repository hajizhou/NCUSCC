```
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int arr[10];
    printf("请输入10个整数：\n");
    for (int i = 0; i < 10; i++) {
        printf("元素 %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int maxVal = arr[0], minVal = arr[0];
    int maxIndex = 0, minIndex = 0;
    for (int i = 1; i < 10; i++) {
        if (arr[i] > maxVal) { maxVal = arr[i]; maxIndex = i + 1; }
        if (arr[i] < minVal) { minVal = arr[i]; minIndex = i; }
    }

    printf("原始数组：");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("最大值是 %d，位于第 %d个元素\n", maxVal, maxIndex);
    printf("最小值是 %d，位于第 %d个元素", minVal, minIndex + 1);

    int arr2[20];
    cout << "\n请输入20个整数：\n";
    for (int c = 0; c < 20; c++) {
        cout << "元素 " << c + 1 << ": ";
        cin >> arr2[c];
    }
    int max2 = arr2[0], min2 = arr2[0];
    int maxInd2 = 0, minInd2 = 0;
    for (int c = 1; c < 20; c++) {
        if (arr2[c] > max2) { max2 = arr2[c]; maxInd2 = c + 1; }
        if (arr2[c] < min2) { min2 = arr2[c]; minInd2 = c; }
    }
    cout << "原始数组：";
    for (int c = 0; c < 20; c++) {
        cout << arr2[c] << " ";
    }
    cout << "\n";
    cout << "最大值是 " << max2 << "，位于第 " << maxInd2 << "个元素\n";
    cout << "最小值是 " << min2 << "，位于第" << minInd2 + 1 << "个元素";

    return 0;
}
```
