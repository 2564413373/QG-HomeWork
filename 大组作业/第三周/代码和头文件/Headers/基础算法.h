#include <stdio.h>
#include <iostream>
#include <time.h>
#include <string.h>
using namespace std;

//////// �Ƿ��ӡ
void isPrint(int); 

//////// ��������
void swap(int*,int*); 

//////// ð������
void BubbleSort(int*,int); 

///////// ��������
void InsertSort(int*,int);

///////// ��������(�ݹ��)
void QuickSort(int*,int,int);

///////// ��������
void CountSort(int*,int);

///////// �鲢����
void MergeSort(int*,int,int); 

void merge(int*,int,int,int);
////////  ��������
void RadixCountSort(int*,int);

////////   ѡ������
void ChooseSort(int*,int);

///////  ��ɫ���� (��7��Ϊ����)
void ColorSort(int* arr,int n);

///////  ���Ż��ַ�Ѱ�����������е�KС��Ԫ�� 
int Partition(int*,int,int);

int QuickSearch(int*,int,int,int);
///////// ���ɲ������ݣ����ұ��浽ָ���ļ����������������������ȡ��ָ����С���� 
int SaveDataToFile();

//////// ��ȡ�ļ��е����ݣ���������������������
void SortDataFromFile(); 
