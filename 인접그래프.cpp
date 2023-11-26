#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef char element;

typedef struct AdjacentVertex {
    element aName;
    struct AdjacentVertex *next;
} AdjacentVertex;

typedef struct Vertex {
    element vNAME;
    AdjacentVertex *aHead;
    struct Vertex *next;
} Vertex;

typedef struct {
    Vertex *vHead;
} GraphType;

void init(GraphType *G) {
    G->vHead = NULL;
}

void makeVertex(GraphType *G, element vName) {
    Vertex *v = (Vertex *)malloc(sizeof(Vertex));
    v->vNAME = vName;
    v->aHead = NULL;
    v->next = NULL;
    Vertex *p = G->vHead;
    if (p==NULL) G->vHead = v;
    else {
        while(p->next!=NULL) {
            p = p->next;
        }
        p->next = v;
    }
}

void print(GraphType *G) {
    Vertex *p = NULL;
    for(p = G->vHead; p!=NULL; p=p->next) {
        printf("[%c]: ", p->vNAME);
        for(AdjacentVertex *q = p->aHead; q!=NULL; q=q->next) {
            printf("%c ", q->aName);
        }
        printf("\n");
    }
}
void makeAdjacentVertex(Vertex *v, element aName) {
    AdjacentVertex *a = (AdjacentVertex *)malloc(sizeof(AdjacentVertex));
    a->aName = aName;
    a->next = NULL;
    AdjacentVertex *p = v->aHead;
    if (p==NULL) v->aHead = a;
    else {
        while(p->next!=NULL) {
            p = p->next;
        }
        p->next = a;
    }

}

Vertex* findVertex(GraphType *G, element vName) {
    Vertex *p = G->vHead;
    while(p->vNAME != vName) p = p->next;
    return p;
}

void insertEdge(GraphType *G, element v1, element v2) {
    Vertex *v = findVertex(G, v1);
    makeAdjacentVertex(v, v2);
    v = findVertex(G, v2);
    makeAdjacentVertex(v, v1);
}

int main() {
    GraphType G;
    init(&G);

    makeVertex(&G, 'a');makeVertex(&G, 'b');makeVertex(&G, 'c');makeVertex(&G, 'd');
    makeVertex(&G, 'e');makeVertex(&G, 'f');makeVertex(&G, 'g');
    
    insertEdge(&G, 'a', 'b'); insertEdge(&G, 'a', 'f'); insertEdge(&G, 'b', 'c');
    insertEdge(&G, 'b', 'g'); insertEdge(&G, 'c', 'd'); insertEdge(&G, 'd', 'e');
    insertEdge(&G, 'd', 'g'); insertEdge(&G, 'e', 'g'); insertEdge(&G, 'e', 'f');
    
    print(&G);
    return 0;
}