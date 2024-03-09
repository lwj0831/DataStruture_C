#include<stdio.h>
#include<stdlib.h>

#define SWAP(a,b,temp) (temp)=(a),(a)=(b),(b)=(temp);

int partition(int arr[], int left, int right) {
	int pivot = left;
	int a = left;
	int b = right + 1;
	int temp;
	do {
		do {
			a++;
		} while (arr[a] < arr[pivot]);
		do {
			b--;
		} while (arr[b] > arr[pivot]);
		if (a<b)SWAP(arr[a], arr[b], temp);
	} while (a<b);
	SWAP(arr[pivot], arr[b], temp);
	return b;
}

void quick_sort(int arr[], int left, int right) {
	if (left < right) {
		int q = partition(arr, left, right);
		quick_sort(arr, left, q - 1);
		quick_sort(arr, q + 1, right);
	}
}