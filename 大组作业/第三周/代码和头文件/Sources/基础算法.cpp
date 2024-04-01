#include "../Headers/基础算法.h"

void isPrint(int* arr,int num_test) {
	int choice1;
	    printf("是否打印排序结果: 1.是 其他数字.不是\n");
	    scanf("%d",&choice1);
	    if (choice1 == 1) {
		    printf("结果如下\n");
		   for (int i=0;i<num_test;i++) {
			printf("%d ",arr[i]);
		   }
	  } else {
		  printf("操作结束！！！");
	  }
}

void swap(int* x,int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

int SaveDataToFile() {
	int choice; ///// 选项 
	int num_test;  ///////// 数据个数 
	printf("请输入你要生成的数据量：1.10000 2.50000 3.200000\n");
	scanf("%d",&choice);
	if (choice == 1)  {
		num_test = 10000;
	} else if (choice == 2) {
		num_test = 50000;
	} else if (choice == 3) {
		num_test = 200000;
	} else {
		printf("你输入的选项不符合要求！\n");
	}
	FILE* fp = fopen("TestData.txt","w");
	if (fp == NULL) {
		printf("无法打开文件！\n");
		return 0;
	}
	srand((int)time(NULL));  /////// 生成随机数种子
	for (int i=0;i<num_test;i++) {
		int data = rand() % 100 + 1;
		fprintf(fp,"%d\n",data);
	}
	fclose(fp);
    printf("测试数据已生成并保存到TestData.txt文件中。\n");
	return num_test; 
}

void SortDataFromFile() {
	int Length = SaveDataToFile();
	int arr[Length];
	int count = 0;
	FILE* fp = fopen("TestData.txt","r");
	if (fp == NULL) {
		printf("无法打开文件！\n");
		return;
	}
	////////// 读取文件数据到数组中 
	while (count<Length) {
		fscanf(fp,"%d",&arr[count]);
		++count;
	}
	fclose(fp);
	int choice;
	printf("请输入你需要的排序方法：\n 1.冒泡排序\n 2.插入排序\n 3.快速排序\n 4.计数排序\n 5.归并排序\n 6.基数计数排序\n 7.选择排序\n");
	scanf("%d",&choice);
	if (choice == 1) {
		clock_t start = clock();
		BubbleSort(arr,Length);
		clock_t diff = clock() - start;
		isPrint(arr,Length);
		printf("\n");
		printf("\n");
		printf("你选择的算法耗时为:%d毫秒\n",diff);
	} else if (choice == 2) {
		clock_t start = clock();
		InsertSort(arr,Length);
		clock_t diff = clock() - start;
		isPrint(arr,Length);
		printf("\n");
		printf("\n");
		printf("你选择的算法耗时为:%d毫秒\n",diff);
	} else if (choice == 3) {
		clock_t start = clock();
		QuickSort(arr,0,Length-1);
		clock_t diff = clock() - start;
		isPrint(arr,Length);
		printf("\n");
		printf("\n");
		printf("你选择的算法耗时为:%d毫秒\n",diff);
	} else if (choice == 4) {
		clock_t start = clock();
		CountSort(arr,Length);
		clock_t diff = clock() - start;
		isPrint(arr,Length);
		printf("\n");
		printf("\n");
		printf("你选择的算法耗时为:%d毫秒\n",diff);
	} else if (choice == 5) {
		clock_t start = clock();
		MergeSort(arr,0,Length-1);
		clock_t diff = clock() - start;
		isPrint(arr,Length);
		printf("\n");
		printf("\n");
		printf("你选择的算法耗时为:%d毫秒\n",diff);
	} else if (choice == 6) {
		clock_t start = clock();
		RadixCountSort(arr,Length);
		clock_t diff = clock() - start;
		isPrint(arr,Length);
		printf("\n");
		printf("\n");
		printf("你选择的算法耗时为:%d毫秒\n",diff);
	} else if (choice == 7) {
		clock_t start = clock();
		ChooseSort(arr,Length);
		clock_t diff = clock() - start;
		isPrint(arr,Length);
		printf("\n");
		printf("\n");
		printf("你选择的算法耗时为:%d毫秒\n",diff);
	}
		////////// 大量小数据 (100个数据*1000次）
	clock_t start1 = clock();
	for (int i=0;i<1000;i++) {
		int* temp_arr = (int*)malloc(100*sizeof(int));
		for (int j=0;j<100;j++) {
			temp_arr[j] = rand()%100+1;
		}
		if (choice == 1) {
			BubbleSort(temp_arr,100);
		} else if (choice == 2) {
			InsertSort(temp_arr,100);
		} else if (choice == 3) {
			QuickSort(temp_arr,0,99);
		} else if (choice == 4) {
			CountSort(temp_arr,100);
		} else if (choice == 5) {
			MergeSort(temp_arr,0,99);
		} else if (choice == 6) {
			RadixCountSort(temp_arr,100);
		} else if (choice == 7) {
			ChooseSort(arr,100);
		}
		free(temp_arr);
	}
	clock_t value = clock() - start1;
	printf("100个数据*1000次的总用时为：%d毫秒",value); 
}

/////////  算法实现

//// 冒泡排序
void BubbleSort(int* arr,int num_test) {
	int flag;
	for (int i=0;i<num_test-1;i++) {
		flag = 1;
		for (int j=0;j<num_test-1-i;j++) {
			if (arr[j] > arr[j+1]) {
			    swap(&arr[j],&arr[j+1]);
				flag = 0;
			}
		}
		if (flag == 1) {
			break;
		}
	}
} 

////////// 插入排序
void InsertSort(int* arr,int num_test) {
	int end,temp; /////// end : 有序数组的最后一个元素 temp ： 比较值（有序数组的下一个值） 
	for (int i=0;i<num_test-1;i++) {
		end = i;
		temp = arr[end+1]; ///// 临时储存 
		while (end>=0) {
			/////// 如果比较值比arr[end]小
			if (temp < arr[end]) {
				arr[end+1] = arr[end];
				--end; 
			} else {
				break;
			}
		}
		arr[end+1] = temp;
	}
} 

////////// 选择排序
void ChooseSort(int* arr,int num_test) {
	int temp,min;
	for (int i=0;i<num_test-1;i++) {
	    temp = i+1;
		min = arr[i+1];
		for (int j=i+1;j<num_test-1;j++) {
			if (arr[j+1] < min) {
				temp = j+1;
				min = arr[j+1];
			}
		}
		if (arr[i] > arr[temp]) {
			swap(&arr[i],&arr[temp]);
		}
	}
} 

///////// 快速排序（递归版本）
void QuickSort(int* arr,int begin,int end) {
	if (begin >= end) {
		return;
	}
	int key = arr[begin];
	int left = begin,right = end;
	while (begin < end) {
		while (arr[end]>=key && begin<end) {
			--end;
		}
		while (arr[begin]<=key && begin<end) {
			++begin;
		}
		swap(&arr[begin],&arr[end]);
	}
	swap(&arr[left],&arr[begin]);
	QuickSort(arr,left,end);
	QuickSort(arr,end+1,right);
} 

////////// 计数排序
void CountSort(int* arr,int num_test) {
	/////////// 先找到最小值和最大值
    int max,min;
	max = min = arr[0];
	int count = 0;
	while (count < num_test) {
		if (arr[count] > max) {
			max = arr[count];
		}
		if (arr[count] < min) {
			min = arr[count];
		}
		++count;
	}
	int num_arr[max-min+1]; /////// 存放出现个数的数组
	memset(num_arr,0,max-min+1);
	for (int i=0;i<max-min+1;i++) {
		num_arr[i] = 0;
	}
	for (int i=0;i<num_test;i++) {
		++num_arr[arr[i]-min];
	}
	///////// 填充覆盖原数组，使其变有序
	int j = 0; 
	for (int i=0;i<max-min+1;i++) {
		for (int z=0;z<num_arr[i];z++) {
			arr[j] = i+min;
			++j;
		}
	} 
} 

////////// 基数计数排序（桶子排序） 可以解决负数 
void RadixCountSort(int* arr,int num_test) {
	int base = 1;    //////// 基底
    ////////// 得到最大值和最小值
	int max,min;
	max = min = arr[0];
	for (int i=0;i<num_test;i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
		if (min > arr[0]) {
			min = arr[i];
		}
	}
	////// 所有数加上最小值的绝对值，使得所有数都为正数，排序完后再所有减回去 
	for (int i=0;i<num_test;i++) {
		arr[i] += abs(min);
	}
	/////// 创建临时数组以及记录位数的桶子数组
	/////// 桶子数组记录位数 
	while (max/base > 0) {
		int bucket[10] =  {0};
		int* temp = (int*)malloc(num_test*sizeof(int));
		for (int i=0;i<num_test;i++) {
		    ++bucket[arr[i]/base%10];	
		}
		/////// 累加次数
		for (int i=1;i<10;i++) {
			bucket[i] += bucket[i-1];
		}
		/////// 将对应值放到临时数组中
		for (int i=num_test-1;i>=0;i--) {
			temp[bucket[arr[i]/base%10]-1] = arr[i];
			--bucket[arr[i]/base%10];
		}
		///////  将临时数组复制到原数组
		for (int i=0;i<num_test;i++) {
			arr[i] = temp[i];
		}
		//////   释放临时数组
		free(temp); 
		base *= 10;
	}
	//////// 全部减回最小值
	for (int i=0;i<num_test;i++) {
		arr[i] -= abs(min);
	} 
}

/////// 颜色排序
void ColorSort(int* arr,int num_test) {
	if (num_test <= 1) {
		return;
	}
	int p0 = 0,p1 = 0;
	int p2 = num_test-1;
	while (p1<=p2) {
		//////// 缩小范围   p0前面的都是0，p2后面的都是2 
		if (arr[p0] == 0) {
		   ++p0;
	    }
	    if (arr[p2] == 2) {
		   --p2;
	    }
	    ////// 交换，使得0或2在左右两端 
		if (arr[p1] == 2) {
			swap(&arr[p1],&arr[p2]);
			--p2;
   		}
		if (arr[p1] == 0) {
   		    swap(&arr[p1],&arr[p0]);
			++p0;
			++p1;
		} else {
			++p1;
		}
	}
} 

///////// 归并排序
void merge(int* arr, int begin, int mid, int end) {
    int i, j, k;
    int n1 = mid - begin + 1;
    int n2 = end - mid;

    // 创建临时数组
    int L[n1], R[n2];

    // 拷贝数据到临时数组 L[] 和 R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[begin + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // 合并临时数组回 arr[l..r]
    i = 0; // 初始化第一个子数组的索引
    j = 0; // 初始化第二个子数组的索引
    k = begin; // 初始合并子数组的索引
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // 拷贝 L[] 的剩余元素
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // 拷贝 R[] 的剩余元素
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// l 是左索引，r是右索引，是 arr[] 的区间
void MergeSort(int* arr, int begin, int end) {
    if (begin < end) {
        // 找到中间索引
        int mid = begin + (end - begin) / 2;

        // 递归地对左右两半进行排序
        MergeSort(arr, begin, mid);
        MergeSort(arr, mid + 1, end);

        // 合并两半
        merge(arr, begin, mid, end);
    } else {
    	return;
	}
} 

/////////// 快排划分法搜查第k小的元素 
int Partition(int* arr,int left,int right) {
	int pivot = arr[right];
	int i = left;
	for (int j=left;j<right;j++) {
		if (arr[j] < pivot) {
			swap(&arr[i],&arr[j]);
			++i;
		}
	}
	swap(&arr[i],&arr[right]);
	return i;
}

int QuickSearch(int* arr,int left,int right,int k) {
	//////// k 首先要合理
	if (k>0 && k<=right-left+1) {
		int index = Partition(arr,left,right);
		//// 如果索引就是要找的值，直接返回
		if (index-left == k-1) {
			return arr[index];
		} 
		//// 如果索引大于k-1，则去左边找
		if (index-left > k-1) {
			return QuickSearch(arr,left,index-1,k);
		}
		//// 如果索引小于k-1，则去右边找
		if (index-left < k-1) {
			return QuickSearch(arr,index+1,right,k-1-index+left);
		} 
	} 
	/////// 找不到就返回-1
	return -1; 
}

int main() {
	int choice;
	bool loop = true;
	while (loop) {
		printf("请选择选项：\n 1.经典算法\n 2.颜色排序展示\n 3.第K小元素\n 其他数字.退出\n");
		scanf("%d",&choice);
		if (choice == 1) {
			SortDataFromFile();
			printf("\n");
		} else if (choice == 2) {
			int arr[] = {2,1,1,2,0,1,2,0,2,1,0};
				printf("原数组：\n");
				for (int i=0;i<11;i++) {
		            printf("%d ",arr[i]);
	            }
	            printf("\n");
	            ColorSort(arr,11);
	            printf("现数组：\n");
	            for (int i=0;i<11;i++) {
		            printf("%d ",arr[i]);
	            }
	            printf("\n");
		} else if (choice == 3) {
		    int arr[] = {2,8,1,7,5,6,3,4,9};
		    int k;
		    printf("请输入要查看第k小的元素:(实验数组长度为9)\n");
			scanf("%d",&k);
			printf("第%d小的元素为：%d\n",k,QuickSearch(arr,0,8,k));	
		} else {
			loop = false;
		}
	}
	system("pause");
	return 0;
}
