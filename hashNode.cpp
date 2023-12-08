#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 20

typedef struct HashNode {
    int key;
    struct HashNode *next;
} HashNode;

int h(int key) {
    return key % M;
}   

void init(HashNode *HT) {
   for(int i=0; i<M; i++) {
        HT[i].key = 0;
        HT[i].next = NULL;
   }
}

void insertItem(HashNode *HT, int key) {
    int b = h(key);
    HashNode *node = (HashNode *)malloc(sizeof(HashNode));
    node->key = key;
    node->next = HT[b].next;
    HT[b].next = node;
}

void print(HashNode *HT) {
    HashNode* p;
    for(int i=0; i<M; i++) {
        printf("HT[%02d] : ", i);
        for(p = HT[i].next; p !=NULL; p = p->next) {
            printf("[%d]", p->key);
        }
        printf("\n");
    }
}

int main() {
    HashNode HT[M];
    init(HT);

    srand(time(NULL));
    for(int i=0; i<20; i++) {
        insertItem(HT, rand()%90+10);
    }
    print(HT);

    return 0;
}