#include "../Headers/�����㷨.h"

void isPrint(int* arr,int num_test) {
	int choice1;
	    printf("�Ƿ��ӡ������: 1.�� ��������.����\n");
	    scanf("%d",&choice1);
	    if (choice1 == 1) {
		    printf("�������\n");
		   for (int i=0;i<num_test;i++) {
			printf("%d ",arr[i]);
		   }
	  } else {
		  printf("��������������");
	  }
}

void swap(int* x,int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

int SaveDataToFile() {
	int choice; ///// ѡ�� 
	int num_test;  ///////// ���ݸ��� 
	printf("��������Ҫ���ɵ���������1.10000 2.50000 3.200000\n");
	scanf("%d",&choice);
	if (choice == 1)  {
		num_test = 10000;
	} else if (choice == 2) {
		num_test = 50000;
	} else if (choice == 3) {
		num_test = 200000;
	} else {
		printf("�������ѡ�����Ҫ��\n");
	}
	FILE* fp = fopen("TestData.txt","w");
	if (fp == NULL) {
		printf("�޷����ļ���\n");
		return 0;
	}
	srand((int)time(NULL));  /////// �������������
	for (int i=0;i<num_test;i++) {
		int data = rand() % 100 + 1;
		fprintf(fp,"%d\n",data);
	}
	fclose(fp);
    printf("�������������ɲ����浽TestData.txt�ļ��С�\n");
	return num_test; 
}

void SortDataFromFile() {
	int Length = SaveDataToFile();
	int arr[Length];
	int count = 0;
	FILE* fp = fopen("TestData.txt","r");
	if (fp == NULL) {
		printf("�޷����ļ���\n");
		return;
	}
	////////// ��ȡ�ļ����ݵ������� 
	while (count<Length) {
		fscanf(fp,"%d",&arr[count]);
		++count;
	}
	fclose(fp);
	int choice;
	printf("����������Ҫ�����򷽷���\n 1.ð������\n 2.��������\n 3.��������\n 4.��������\n 5.�鲢����\n 6.������������\n 7.ѡ������\n");
	scanf("%d",&choice);
	if (choice == 1) {
		clock_t start = clock();
		BubbleSort(arr,Length);
		clock_t diff = clock() - start;
		isPrint(arr,Length);
		printf("\n");
		printf("\n");
		printf("��ѡ����㷨��ʱΪ:%d����\n",diff);
	} else if (choice == 2) {
		clock_t start = clock();
		InsertSort(arr,Length);
		clock_t diff = clock() - start;
		isPrint(arr,Length);
		printf("\n");
		printf("\n");
		printf("��ѡ����㷨��ʱΪ:%d����\n",diff);
	} else if (choice == 3) {
		clock_t start = clock();
		QuickSort(arr,0,Length-1);
		clock_t diff = clock() - start;
		isPrint(arr,Length);
		printf("\n");
		printf("\n");
		printf("��ѡ����㷨��ʱΪ:%d����\n",diff);
	} else if (choice == 4) {
		clock_t start = clock();
		CountSort(arr,Length);
		clock_t diff = clock() - start;
		isPrint(arr,Length);
		printf("\n");
		printf("\n");
		printf("��ѡ����㷨��ʱΪ:%d����\n",diff);
	} else if (choice == 5) {
		clock_t start = clock();
		MergeSort(arr,0,Length-1);
		clock_t diff = clock() - start;
		isPrint(arr,Length);
		printf("\n");
		printf("\n");
		printf("��ѡ����㷨��ʱΪ:%d����\n",diff);
	} else if (choice == 6) {
		clock_t start = clock();
		RadixCountSort(arr,Length);
		clock_t diff = clock() - start;
		isPrint(arr,Length);
		printf("\n");
		printf("\n");
		printf("��ѡ����㷨��ʱΪ:%d����\n",diff);
	} else if (choice == 7) {
		clock_t start = clock();
		ChooseSort(arr,Length);
		clock_t diff = clock() - start;
		isPrint(arr,Length);
		printf("\n");
		printf("\n");
		printf("��ѡ����㷨��ʱΪ:%d����\n",diff);
	}
		////////// ����С���� (100������*1000�Σ�
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
	printf("100������*1000�ε�����ʱΪ��%d����",value); 
}

/////////  �㷨ʵ��

//// ð������
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

////////// ��������
void InsertSort(int* arr,int num_test) {
	int end,temp; /////// end : ������������һ��Ԫ�� temp �� �Ƚ�ֵ�������������һ��ֵ�� 
	for (int i=0;i<num_test-1;i++) {
		end = i;
		temp = arr[end+1]; ///// ��ʱ���� 
		while (end>=0) {
			/////// ����Ƚ�ֵ��arr[end]С
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

////////// ѡ������
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

///////// �������򣨵ݹ�汾��
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

////////// ��������
void CountSort(int* arr,int num_test) {
	/////////// ���ҵ���Сֵ�����ֵ
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
	int num_arr[max-min+1]; /////// ��ų��ָ���������
	memset(num_arr,0,max-min+1);
	for (int i=0;i<max-min+1;i++) {
		num_arr[i] = 0;
	}
	for (int i=0;i<num_test;i++) {
		++num_arr[arr[i]-min];
	}
	///////// ��串��ԭ���飬ʹ�������
	int j = 0; 
	for (int i=0;i<max-min+1;i++) {
		for (int z=0;z<num_arr[i];z++) {
			arr[j] = i+min;
			++j;
		}
	} 
} 

////////// ������������Ͱ������ ���Խ������ 
void RadixCountSort(int* arr,int num_test) {
	int base = 1;    //////// ����
    ////////// �õ����ֵ����Сֵ
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
	////// ������������Сֵ�ľ���ֵ��ʹ����������Ϊ������������������м���ȥ 
	for (int i=0;i<num_test;i++) {
		arr[i] += abs(min);
	}
	/////// ������ʱ�����Լ���¼λ����Ͱ������
	/////// Ͱ�������¼λ�� 
	while (max/base > 0) {
		int bucket[10] =  {0};
		int* temp = (int*)malloc(num_test*sizeof(int));
		for (int i=0;i<num_test;i++) {
		    ++bucket[arr[i]/base%10];	
		}
		/////// �ۼӴ���
		for (int i=1;i<10;i++) {
			bucket[i] += bucket[i-1];
		}
		/////// ����Ӧֵ�ŵ���ʱ������
		for (int i=num_test-1;i>=0;i--) {
			temp[bucket[arr[i]/base%10]-1] = arr[i];
			--bucket[arr[i]/base%10];
		}
		///////  ����ʱ���鸴�Ƶ�ԭ����
		for (int i=0;i<num_test;i++) {
			arr[i] = temp[i];
		}
		//////   �ͷ���ʱ����
		free(temp); 
		base *= 10;
	}
	//////// ȫ��������Сֵ
	for (int i=0;i<num_test;i++) {
		arr[i] -= abs(min);
	} 
}

/////// ��ɫ����
void ColorSort(int* arr,int num_test) {
	if (num_test <= 1) {
		return;
	}
	int p0 = 0,p1 = 0;
	int p2 = num_test-1;
	while (p1<=p2) {
		//////// ��С��Χ   p0ǰ��Ķ���0��p2����Ķ���2 
		if (arr[p0] == 0) {
		   ++p0;
	    }
	    if (arr[p2] == 2) {
		   --p2;
	    }
	    ////// ������ʹ��0��2���������� 
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

///////// �鲢����
void merge(int* arr, int begin, int mid, int end) {
    int i, j, k;
    int n1 = mid - begin + 1;
    int n2 = end - mid;

    // ������ʱ����
    int L[n1], R[n2];

    // �������ݵ���ʱ���� L[] �� R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[begin + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // �ϲ���ʱ����� arr[l..r]
    i = 0; // ��ʼ����һ�������������
    j = 0; // ��ʼ���ڶ��������������
    k = begin; // ��ʼ�ϲ������������
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

    // ���� L[] ��ʣ��Ԫ��
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // ���� R[] ��ʣ��Ԫ��
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// l ����������r������������ arr[] ������
void MergeSort(int* arr, int begin, int end) {
    if (begin < end) {
        // �ҵ��м�����
        int mid = (begin + end) / 2;

        // �ݹ�ض����������������
        MergeSort(arr, begin, mid);
        MergeSort(arr, mid + 1, end);

        // �ϲ�����
        merge(arr, begin, mid, end);
    } else {
    	return;
	}
} 

/////////// ���Ż��ַ��Ѳ��kС��Ԫ�� 
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
	//////// k ����Ҫ����
	if (k>0 && k<=right-left+1) {
		int index = Partition(arr,left,right);
		//// �����������Ҫ�ҵ�ֵ��ֱ�ӷ���
		if (index-left == k-1) {
			return arr[index];
		} 
		//// �����������k-1����ȥ�����
		if (index-left > k-1) {
			return QuickSearch(arr,left,index-1,k);
		}
		//// �������С��k-1����ȥ�ұ���
		if (index-left < k-1) {
			return QuickSearch(arr,index+1,right,k-1-index+left);
		} 
	} 
	/////// �Ҳ����ͷ���-1
	return -1; 
}

int main() {
	int choice;
	bool loop = true;
	while (loop) {
		printf("��ѡ��ѡ�\n 1.�����㷨\n 2.��ɫ����չʾ\n 3.��KСԪ��\n ��������.�˳�\n");
		scanf("%d",&choice);
		if (choice == 1) {
			SortDataFromFile();
			printf("\n");
		} else if (choice == 2) {
			int arr[] = {2,1,1,2,0,1,2,0,2,1,0};
				printf("ԭ���飺\n");
				for (int i=0;i<11;i++) {
		            printf("%d ",arr[i]);
	            }
	            printf("\n");
	            ColorSort(arr,11);
	            printf("�����飺\n");
	            for (int i=0;i<11;i++) {
		            printf("%d ",arr[i]);
	            }
	            printf("\n");
		} else if (choice == 3) {
		    int arr[] = {2,8,1,7,5,6,3,4,9};
		    int k;
		    printf("������Ҫ�鿴��kС��Ԫ��:(ʵ�����鳤��Ϊ9)\n");
			scanf("%d",&k);
			printf("��%dС��Ԫ��Ϊ��%d\n",k,QuickSearch(arr,0,8,k));	
		} else {
			loop = false;
		}
	}
	system("pause");
	return 0;
}
