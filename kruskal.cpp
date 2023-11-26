#include <stdio.h>
#include <stdlib.h>

#define N 10
#define TRUE 1
#define FALSE 0

typedef char element;

typedef struct Edge {
    element v1, v2;
    int weight;
    struct Edge *next;
}Edge;

typedef struct AdjacentVertex
{
    element aName;
    Edge *e;
    struct AdjacentVertex *next;
}AdjacentVertex;

typedef struct Vertex
{
    element vName;
    int isVisit;
    AdjacentVertex *aHead;
    struct Vertex *next;
}Vertex;

typedef struct
{
    Vertex *vHead;
    Edge *eHead;
    int vCount, eCount;
}GraphType;

void init(GraphType *G)
{
    G->vHead = NULL;
    G->eHead = NULL;
    G->vCount = G->eCount = 0;
}

void makeVertex(GraphType *G, element vName)
{
    Vertex *v = (Vertex *)malloc(sizeof(Vertex));
    v->vName = vName;
    v->isVisit = FALSE;
    v->aHead = NULL;
    v->next = NULL;
    
    G->vCount++;

    Vertex *p = G->vHead;
    
    if(p == NULL)
        G->vHead = v;
    else
    {
        while(p->next != NULL)
            p = p->next;
            
        p->next = v;    
    }
}

Vertex* findVertex(GraphType *G, element vName)
{
    Vertex *p = G->vHead;
    
    while(p->vName != vName)
        p = p->next;
    
    return p;    
}

void makeAdjacentVertex(Vertex *v, element aName, Edge *e)
{
    AdjacentVertex *a = (AdjacentVertex *)malloc(sizeof(AdjacentVertex));
    a->aName = aName;
    a->next = NULL;
    a->e = e;
    
    AdjacentVertex *p = v->aHead;
    
    if(p == NULL)
        v->aHead = a;
    else
    {
        while(p->next != NULL)
            p = p->next;
            
        p->next = a;    
    }
}

void insertEdge(GraphType *G, element v1, element v2, int weight)
{
    Edge *e = (Edge *)malloc(sizeof(Edge));
    e->v1 = v1;
    e->v2=  v2;
    e->weight = weight;
    e->next = NULL;

    G->eCount++;

    Edge *p = G->eHead;

    if (p==NULL) {
        G->eHead = e;
    } else {
        while(p->next!= NULL) {
            p = p->next;
        }
        p->next = e;
    }

    Vertex *v = findVertex(G, v1);
    makeAdjacentVertex(v, v2, e);

    v = findVertex(G, v2);
    makeAdjacentVertex(v, v1, e);
}

void print(GraphType *G)
{
    Vertex *p = NULL;
    AdjacentVertex *q = NULL;
    
    for(p = G->vHead; p != NULL; p = p->next)
    {
        printf("[%c] : ", p->vName);
        for(q = p->aHead; q != NULL; q = q->next)
            printf("[%c, %d] ", q->aName, q->e->weight);
        printf("\n");    
    }
}

void rDFS(GraphType *G, char vName)
{
    Vertex *v = findVertex(G, vName);
    AdjacentVertex *a = NULL;
    
    if(v->isVisit == FALSE)
    {
        v->isVisit = TRUE;
        printf("[%c] ", v->vName);
    }
    
    for(a = v->aHead; a != NULL; a = a->next)
    {
        v = findVertex(G, a->aName);
        if(v->isVisit == FALSE)
            rDFS(G, v->vName);
    }
}

typedef struct
{
	element data[N];
	int front, rear;
}QueueType;

void initQueue(QueueType* Q)
{
	Q->front = Q->rear = 0;
}

int isQueueEmpty(QueueType* Q)
{
	return Q->rear == Q->front;
}

int isQueueFull(QueueType* Q)
{
	return (Q->rear + 1) % N == Q->front;
}

void enqueue(QueueType* Q, element d)
{
	if (isQueueFull(Q))
    	printf("Overflow!!\n");
	else
	{
	    Q->rear = (Q->rear + 1) % N;
	    Q->data[Q->rear] = d;
	}
}

element dequeue(QueueType* Q)
{
	if (isQueueEmpty(Q))
	{
		printf("Empty!!\n");
        return -1;
	}
	Q->front = (Q->front + 1) % N;
	return Q->data[Q->front];
}

void BFS(GraphType *G, element vName)
{
    Vertex *v = findVertex(G, vName);
    AdjacentVertex *a = NULL;
    
    QueueType Q;
    initQueue(&Q);
    
    v->isVisit = TRUE;
    printf("[%c] ", v->vName);
    enqueue(&Q, v->vName);
    
    while(!isQueueEmpty(&Q))
    {
        v = findVertex(G, dequeue(&Q));
        
        for(a = v->aHead; a != NULL; a = a->next)
        {
            v = findVertex(G, a->aName);
            if(v->isVisit == FALSE)
            {
                v->isVisit = TRUE;
                printf("[%c] ", v->vName);
                enqueue(&Q, v->vName);
            }
        }
    }
}

typedef struct
{
    element data[N];
    int top;
}StackType;

void initStack(StackType* S)
{
    S->top = -1;
}

int isStackEmpty(StackType* S)
{
    return S->top == -1;
}

int isStackFull(StackType* S)
{
    return S->top == N - 1;
}

void push(StackType* S, element d)
{
    if(isStackFull(S))
        printf("Overflow!!\n");
    else
    {
        S->top++;
        S->data[S->top] = d;
    }
}

element pop(StackType* S)
{
    if(isStackEmpty(S))
    {
        printf("Empty!!\n");
        return -1;
    }
    
    element d = S->data[S->top];
    S->top--;
    return d;
}

element peek(StackType* S)
{
    if(isStackEmpty(S))
    {
        printf("Empty!!\n");
        return -1;
    }
    
    return S->data[S->top];
}

void DFS(GraphType *G, element vName)
{
    Vertex *v = findVertex(G, vName);
    AdjacentVertex *a = NULL;
    
    StackType S;
    initStack(&S);
    
    push(&S, v->vName);
    //int flag;
    while(!isStackEmpty(&S))
    {
        v = findVertex(G, peek(&S));
        if(v->isVisit == FALSE)
        {
            v->isVisit = TRUE;
            printf("[%c] ", v->vName);
        }
     		
		 //flag = TRUE;   
        for(a = v->aHead; a != NULL; a = a->next)
        {
            v = findVertex(G, a->aName);
            if(v->isVisit == FALSE)
            {
                push(&S, v->vName);
				  //flag = FALSE; 
                break;
            }
        }
        
		 //if(flag == TRUE)
        if(a == NULL)
            pop(&S);
    }
}

void incSort(GraphType *G, Edge* edges[]) {
    int i, least;
    Edge *p = G->eHead;

    for(i=0; i<G->eCount; i++) {
        edges[i] = p;
        p = p->next;
    }
    for(i = 0; i<G->eCount-1; i++) {
        least = i;
        for(int j=i+1; j<G->eCount; j++) {
            if(edges[least]->weight > edges[j]->weight) least = j;
        }
        p = edges[least];
        edges[least] = edges[i]; 
        edges[i] = p;
    }

    for(i=0; i<G->eCount; i++)
        printf("[%c %c %d] ", edges[i]->v1, edges[i]->v2, edges[i]->weight);
}

int vFind(int vertices[], int vNum) {
    if(vertices[vNum]==-1) return vNum;
    // return vFind(vertices, vertices[vNum]);
    while (vertices[vNum] != -1) vNum = vertices[vNum];
    return vNum;
}

void vUnion(int vertices[], int vNum1, int vNum2) {
    vertices[vNum2] = vNum1;
}

void kruskal(GraphType *G, Edge* edges[], int vertices[]) {
    int eCnt = 0, i = 0;
    int vNum1, vNum2;
    Edge *e;
    while(eCnt < G->vCount-1) {
        e = edges[i];
        vNum1 = vFind(vertices, e->v1-97);
        vNum2 = vFind(vertices, e->v2-97);
    
        if(vNum1!=vNum2) {
            eCnt++;
            printf("%d. [%c %c %d]", eCnt, e->v1, e->v2, e->weight);
            vUnion(vertices, vNum1, vNum2);
        }
        i++;
    }
}

int main()
{
    GraphType G;
    init(&G);
    
    makeVertex(&G, 'a'); makeVertex(&G, 'b');
    makeVertex(&G, 'c'); makeVertex(&G, 'd');
    makeVertex(&G, 'e'); makeVertex(&G, 'f');
    makeVertex(&G, 'g');
    
    insertEdge(&G, 'a', 'b', 29); insertEdge(&G, 'a', 'f', 10);
    insertEdge(&G, 'b', 'c', 16); insertEdge(&G, 'b', 'g', 15);
    insertEdge(&G, 'c', 'd', 12);
    insertEdge(&G, 'd', 'e', 22); insertEdge(&G, 'd', 'g', 18);
    insertEdge(&G, 'e', 'f', 27); insertEdge(&G, 'e', 'g', 25);
    
    print(&G); printf("\n");
    
    //printf("rDFS : "); rDFS(&G, 'g');
    //printf("BFS : "); BFS(&G, 'g');
    // printf("DFS : "); DFS(&G, 'g');
    
    Edge* edges[N];

    incSort(&G, edges); printf("\n");

    int vertices[N] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    kruskal(&G, edges, vertices);
    
    return 0;
}