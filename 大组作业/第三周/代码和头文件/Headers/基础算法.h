#include <stdio.h>
#include <iostream>
#include <time.h>
#include <string.h>
using namespace std;

//////// 是否打印
void isPrint(int); 

//////// 交换函数
void swap(int*,int*); 

//////// 冒泡排序
void BubbleSort(int*,int); 

///////// 插入排序
void InsertSort(int*,int);

///////// 快速排序(递归版)
void QuickSort(int*,int,int);

///////// 计数排序
void CountSort(int*,int);

///////// 归并排序
void MergeSort(int*,int,int); 

void merge(int*,int,int,int);
////////  基数排序
void RadixCountSort(int*,int);

////////   选择排序
void ChooseSort(int*,int);

///////  颜色排序 (以7个为例子)
void ColorSort(int* arr,int n);

///////  快排划分法寻找无序序列中第K小的元素 
int Partition(int*,int,int);

int QuickSearch(int*,int,int,int);
///////// 生成测试数据，并且保存到指定文件，返回数组个数方便后面读取到指定大小数组 
int SaveDataToFile();

//////// 读取文件中的数据，并调用上述排序函数排序
void SortDataFromFile(); 
