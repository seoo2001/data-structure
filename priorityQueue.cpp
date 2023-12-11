#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 100

typedef int element;

typedef struct {
    element heap[N];
    int heapSize;
} HeapType;

void init(HeapType *H) {
    H->heapSize = 0;
} 
void upHeap(HeapType *H) {
    int i = H->heapSize;
    element key = H->heap[i];
    while(i!=1 && H->heap[i] > H->heap[i/2]) {
        H->heap[i] = H->heap[i/2];
    }
    H->heap[i] = key;
}

void InsertHeap(HeapType *H, element e) {
    H->heapSize++;
    H->heap[H->heapSize] = e;
    upHeap(H);
}

void print(HeapType *H, int i) {
    for(int i=1; i<=H->heapSize; i++) {
        printf("[%d] ", H->heap[i]);
    }
    printf("\n");
}

void downHeap(HeapType *H) {
    element key = H->heap[1];
    int parent = 1, child = 2;
    while(child <= H->heapSize) {
        if(child < H->heapSize && H->heap[child+1] > H->heap[child]) {
            child++;
        }
        if(key >= H->heap[child]) break;
        H->heap[parent] = H->heap[child];
        parent = child;
        child *=2;
    }
    H->heap[parent] = key;
}

element removeHeap(HeapType *H) {
    element key = H->heap[1];
    H->heap[1] = H->heap[H->heapSize];
    H->heapSize--;
    downHeap(H);
    return key;
}

void HeapSort(HeapType *H) {
    
}

int main() {
    HeapType H;
    init(&H);

    InsertHeap(&H, 9); InsertHeap(&H, 7); InsertHeap(&H, 6);
    InsertHeap(&H, 5); InsertHeap(&H, 4); InsertHeap(&H, 3);
    InsertHeap(&H, 2); InsertHeap(&H, 2); InsertHeap(&H, 1);
    InsertHeap(&H, 3);
    print(&H, 1);
    element k = removeHeap(&H);
    // printf("%d ", k);
    print(&H, 1);
    removeHeap(&H);
    print(&H, 1);
    return 0;
}