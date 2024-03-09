#include<stdio.h>
#include<stdlib.h>

void insertion_sort(int arr[],int n) {
	for (int i = 1; i < n; i++) {
		int temp = arr[i];
		int j;
		for (j = i - 1; j >= 0  && arr[j]>temp; j--) {
			arr[j + 1] = arr[j];
		}
		arr[j+1] = temp;
	}
}