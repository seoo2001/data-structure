#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void selectionSort(int A[]) {
    printf("Before Sort: ");
    for(int i=0; i<N; i++) printf("%d ", A[i]);
    printf("\n");

    for(int i=0; i<=N-2; i++) {
        int min = i;
        for(int j=i+1; j<= N-1; j++) {
            if (A[j] > A[min]) min = j;
        }
        int temp = A[min];
        A[min] = A[i];
        A[i] = temp;
    }

    printf("After Sort: ");
    for(int i=0; i<N; i++) printf("%d ", A[i]);
    printf("\n");
}

void insertionSort(int A[]) {
    printf("Before Sort: ");
    for(int i=0; i<N; i++) printf("%d ", A[i]);
    printf("\n");

    for(int i=0; i<=N-1; i++) {
        int key = A[i];
        int j = i-1;
        while (j>=0 && A[j] > key) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
        printf("%d step: ", i+1);
        for(int i=0; i<N; i++) {
            printf("%d ", A[i]);
        }
        printf("\n");
    }

    printf("After Sort: ");
    for(int i=0; i<N; i++) printf("%d ", A[i]);
    printf("\n");
}

int count;
int iBinarySearch(int A[], int key) {
    int low = 0, high = N-1, middle;
    while(low<=high) {
        count++;
        middle = (low+high)/2;
        if(A[middle]==key) return middle;
        else if (A[middle] > key) high = middle-1;
        else  low = middle + 1;

    }
    return -1;
}

int rBinarySearch(int low, int high, int A[], int key) {
    if (low<=high) {
        int middle = (low+high)/2;
        count++;
        if(A[middle]==key) return middle;
        else if (A[middle] > key) rBinarySearch(low, middle-1, A, key);
        else  return rBinarySearch(middle + 1, high, A, key);
    }
    return -1;
}

int main() {
    int A[N];
    srand(time(NULL));
    
    for (int i=0; i<N; i++) {
        A[i] = rand() % 100;
    }
    // selectionSort(A);
    insertionSort(A);

    int key, idx;
    printf("Search Key: ");
    scanf("%d", &key);

    idx = iBinarySearch(A, key);
    if (idx==-1) printf("NO\n");
    else printf("%d Times : %d in A[%d]\n", count, key, idx);
}