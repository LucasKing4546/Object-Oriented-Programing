#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int arr[], int n) {
    for (int i = 0; i < n ; i++) {
        for (int j = i + 1; j < n ; j++) {
            if (arr[i] > arr[j]) {
               swap(&arr[i], &arr[j]);
            }
        }
    }
}

int main() {
    int n;
    int k = 0;
    int produce = 1;
    scanf("%d", &n);
    int* arr = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, n);
    int* newArr = (int*)malloc(sizeof(int) * 3);
    for (int i = n-3; i < n; i++) {
        newArr[k++] = arr[i];
        produce = produce * arr[i];
    }
    printf("%d\n", produce);
    for (int i = 0; i < k; i++) {
        printf("%d ", newArr[i]);
    }
    free(arr);
    free(newArr);
    return 0;
}
