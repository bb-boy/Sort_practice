#include <stdio.h>
 
void swap(int &a, int &b) {                           //Ωªªª∫Ø ˝
	int t = b;
	b = a;
	a = t;
}

void arr_print(int a[]) {                             //¥Ú”° ˝◊È
	for (int i = 0; i < sizeof(a); i++)
		printf("%d\t", a[i]);
	printf("\n");
}

/*√∞≈›≈≈–Ú*/
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


/*øÏÀŸ≈≈¡–£¨œ»∑÷∏Ó‘⁄µ›πÈ*/
int partition(int a[], int left, int right) {           //∑÷∏Ó
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

void QuickSort(int a[],int left,int right) {            //µ›πÈ
	if (left < right) {
		int pivot = partition(a, left, right);
		QuickSort(a, left, pivot - 1);
		QuickSort(a, pivot + 1, right);
	}
}


/*≤Â»Î≈≈–Ú*/
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


/*÷±Ω”≤Â»Î≈≈–Ú*/
void insert_sort1(int a[], int n) {
	for (int i = 1; i < n ; i++) {
		int key = a[i];
		int j=i-1;
		for (;a[j] > key&&j>=0;--j)
				a[j + 1] = a[j];
		a[j + 1] = key;
	}

}

/*’€∞Î≤Â»Î≈≈–Ú*/
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


int main() {
	int A[8] = { 49,38,65,97,76,13,27,49 };
	arr_print(A);

	/*√∞≈›≈≈–Ú*/
	/*BubbleSort(A);
	arr_print(A);*/    

	/*øÏ≈≈*/
	/*QuickSort(A, 0, 7);
	arr_print(A);*/

	/*≤Â»Î≈≈–Ú*/
	/*insert_sort(A, 8);
	arr_print(A);*/

	/*’€∞Î≤Â»Î≈≈–Ú*/
	binary_insertion_sort(A, 8);
	arr_print(A);

	
}