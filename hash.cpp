#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 13

typedef struct HashNode {
    int key;
    struct HahNode *next;
} HashNode;

typedef struct 
{
    int key;
    int probeCount;


}Bucket;

typedef struct
{
    Bucket B[M];
}HashTable;

void init(HashTable *HT) {
    for(int i=0; i<M; i++) {
        HT->B[i].key = 0;
        HT->B[i].probeCount = 0;
    }
}

int h(int key) {
    return key % M;
}

int h2(int key) {
    return 11 - key % 11;
}
int getNextBucketLinear(int v, int inc) {
    return (v + inc) % M;
}

int getNextBucketQuadratic(int v, int inc) {
    return (v + inc*inc) % M;
}

int getNextBucketDouble(int v, int inc, int key) {
    return (v + inc*h2(key)) % M;
}


bool isEmpty(HashTable *HT, int b) {
    return !(HT->B[b].key);
}

void insertItem(HashTable *HT, int key) {
    int v = h(key);
    int inc = 0;
    int count = 0;

    while(inc < M) {
        count++;
        int b = getNextBucketLinear(v, inc);
        // int b = getNextBucketQuadratic(v, inc, key);
        // int b = getNextBucketDouble(v, inc, key);
        
        if(isEmpty(HT, b)) {
            HT->B[b].key = key;
            HT->B[b].probeCount = count;
            return;
        } else {
            inc++;
        }
    }
}

int findItem(HashTable *HT, int key) {
    int v = h(key);
    int inc = 0;

    while(inc < M) {
        int b = getNextBucketLinear(v, inc);
        // int b = getNextBucketQuadratic(v, inc, key);
        // int b = getNextBucketDouble(v, inc, key);
        
        if(isEmpty(HT, b)) {
            return 0;
        } 
        else if (HT->B[b].key == key) {
            return key;
        }
        else {
            inc++;
        }
    }
}

void removeItem(HashTable *HT, int key) {
    int v = h(key);
    int inc = 0;
    while(inc < M) {
        int b = getNextBucketLinear(v, inc);
        // int b = getNextBucketQuadratic(v, inc, key);
        // int b = getNextBucketDouble(v, inc, key);
        
        if(isEmpty(HT, b)) {
            return;
        } 
        else if (HT->B[b].key == key) {
            // 삭제 연산 시 key 를 -1로 바꿔놔야 됨.
            // ex) 15 삭제 후, 28 삭제
            HT->B[b].key = -1;
            HT->B[b].probeCount = 0;
        }
        else {
            inc++;
        }
    }
}

void print(HashTable *HT) {
    for(int i=0; i<M; i++) {
        printf("%2d ", HT->B[i].key);
    }
    printf("\n");
}

void printHash(HashTable *HT) {
    printf("Bucket  Key Probe\n");
    printf("=================\n");

    for(int i=0; i<M; i++) {
        printf("HT[%02d]: %2d  %d\n", i, HT->B[i].key, HT->B[i].probeCount);
    }
}

int main() {
    HashTable HT;
    init(&HT);

    int data[] = {25, 13, 16, 15, 7, 28, 31, 20, 1, 38};

    printf("h(key)    0  1  2  3  4  5  6  7  8  9 10 11 12\n");
    printf("======== ======================================\n");

    for(int i=0; i<10; i++) {
        printf("h(%02d):%2d ", data[i], h(data[i]));
        insertItem(&HT, data[i]);
        print(&HT);
    }

    printf("\n");
    printHash(&HT);

    int key;
    printf("Input Search Key : ");
    scanf("%d", &key);

    if(findItem(&HT, key)) {
        printf("exist\n");
    } else {
        printf("not exist\n");
    }
    removeItem(&HT, key);
    printHash(&HT);
    printf("Input Search Key : ");
    scanf("%d", &key);

    if(findItem(&HT, key)) {
        printf("exist\n");
    } else {
        printf("not exist\n");
    }


    return 0;
}