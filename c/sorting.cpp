#include <stdio.h>
#define N 20
 
void swap(int &a, int &b) {                           //��������
	int t = b;
	b = a;
	a = t;
}

void arr_print(int a[],int n) {       //��ӡ����
	
	
	for (int i = 0; i < n; i++)
		printf("%d\t", a[i]);
	printf("\n");
}

/*ð������*/
void BubbleSort(int a[]) {
	int count = sizeof(a);
	for (int i = 0; i < count; i++) {
		int flag =1;
		for (int j = count - 1; j > i; j--) {
			if (a[j] < a[j - 1]) {
				swap(a[j], a[j - 1]);
				flag = 0;
			}
		}
		if (flag)
			break;
	}
}


/*�������У��ȷָ��ڵݹ�*/
int partition(int a[], int left, int right) {           //�ָ�
	int k, i;
	for (i = k = left;i<right; i++) {
		if (a[i] < a[right]) {
			swap(a[i], a[k]);
			k++;
		}
	}
	swap(a[k], a[right]);
	return k;
}

void QuickSort(int a[],int left,int right) {            //�ݹ�
	if (left < right) {
		int pivot = partition(a, left, right);
		QuickSort(a, left, pivot - 1);
		QuickSort(a, pivot + 1, right);
	}
}


/*��������*/
void insert_sort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		int key = a[i];
		int j = i-1;
		while (a[j] >key&&j>=0) {
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;	
	}
}


/*ֱ�Ӳ�������*/
void insert_sort1(int a[], int n) {
	for (int i = 1; i < n ; i++) {
		int key = a[i];
		int j=i-1;
		for (;a[j] > key&&j>=0;--j)
				a[j + 1] = a[j];
		a[j + 1] = key;
	}

}

/*�۰��������*/
void binary_insertion_sort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		int low = 0, high = i-1;
		int key = a[i];
		while (low <= high) {
			int mid = (low + high) / 2;
			if (a[mid] > a[i])
				high--;
			else
				low++;
		}
		for (int j = i - 1; j >=low; j--)
			a[j + 1] = a[j];
		a[low] = key;
	}
}

/*shell����*/
void shellsort(int a[], int n) {

	
	for (int gap = n / 2; gap > 0; gap = gap / 2) {
		for (int i = gap; i < n; i++) {
			int key = a[i];
			int j;
			if (a[i - gap] > key) {
				for (j = i - gap; j>=0&&key < a[j]; j =j- gap) {
					a[j + gap] = a[j];
				}
				a[j + gap] = key;
			}
		}
	}
}



/*ѡ������*/
void select_sort(int a[], int n) {
	int i, j, min;
	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i; j < n; j++) {
			if (a[j] < a[min])
				/*swap(a[min], a[j]);*/
				min = j;
		}
		if (i != min)
			swap(a[min], a[i]);

	}
}


/*������*/

void build_heap(int a[],int k ,int n) {
		int parent=k;
		int son = 2 * parent + 1;                                            
		while (son < n) {
			if ((son + 1) < n && a[son] < a[son + 1])
				son++;
			if (a[parent] < a[son]) {
				swap(a[parent], a[son]);
				parent = son;
				son = 2 * parent + 1;
			}
			else
				break;
		}
	
}

void heap_sort(int a[], int n) {
	for (int p = n / 2 - 1; p >= 0; p--) {                 //ѭ���������ڵ㣬��ÿ��������Ϊ�����
		build_heap(a, p, n);                                
	}
	swap(a[0], a[n - 1]);									//��root�����һ��Ҷ�ӽڵ㽻��
	for (int len = n - 1; len > 0; len--) {
		build_heap(a, 0, len);                             //ȥ�����һ���ڵ㣬��ʣ�µ�����Ϊ�����
		swap(a[0], a[len - 1]);                            //����
	}
	
}


/*�鲢����*/
void merge(int A[], int low, int mid, int high) {
	
	int B[N];
	for (int i = 0; i <= high; i++)  //��������
		B[i] = A[i];

	int i, j,k;
	for (i = low, k = low, j = mid + 1; j <= high && i <= mid; k++) {
		if (B[i] < B[j])
			A[k] = B[i++];
		else
			A[k] = B[j++];
	}

	while (i <= mid ) {
		A[k++] = B[i++];
	}
	while (j <= high) {
		A[k++] = B[j++];
	}

}

void mergesort(int A[], int low,int high) {
	
	if(low<high){
		int mid = (low + high) / 2;
		mergesort(A, low, mid);
		mergesort(A, mid+1,high);
		merge(A, low, mid, high);
		}
}

int main() {
	int A[8] = { 49,38,65,97,76,13,27,49 };
	arr_print(A,8);
	
	int B[10] = { 3,87,2,93,78,56,61,38,12,40 };
	
	//arr_print(A);

	/*ð������*/
	/*BubbleSort(A);
	arr_print(A,8);*/

	/*����*/
	/*QuickSort(A, 0, 7);
	arr_print(A,8);*/

	/*��������*/
	/*insert_sort(A, 8);
	arr_print(A,8);*/

	/*�۰��������*/
	/*binary_insertion_sort(A, 8);
	arr_print(A,8);*/

	/*ϣ������*/
	/*shellsort(A, 8);
	arr_print(A,8);*/

	/*ѡ������*/
	/*select_sort(A, 8);
	arr_print(A,8);*/

	/*����*/
//	heap_sort(B, 10);
	//arr_print(B,10);

	
	mergesort(B, 0, 9);
	arr_print(B, 10);
}