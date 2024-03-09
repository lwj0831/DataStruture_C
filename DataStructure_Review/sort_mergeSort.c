#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100

void merge(int arr[], int left, int right) {
	int sorted[MAX_SIZE];
	int middle = (left + right) / 2;

	int i = left;
	int j = middle + 1;
	int k = left;

	while (i <= middle && k <= right) {
		if (arr[i] > arr[j])sorted[k++] = arr[j];
		else sorted[k++] = arr[i];
	}
	while (i <= middle) {
		sorted[k++] = arr[i];
	}
	while (j <= right) {
		sorted[k++] = arr[j];
	}
	for (int i = left; i <= right; i++) {
		arr[i] = sorted[i];
	}
}

void merge_sort(int arr[], int left,int right) {
	if (left < right) {
		int middle = (left + right) / 2;
		merge_sort(arr, left, middle);
		merge_sort(arr, middle + 1, right);
		merge(arr, left, right);
	}
}