#include <stdio.h>
#include <stdlib.h>

#define N 10
#define TRUE 1
#define FALSE 0

typedef int element;
int visited[N];
typedef struct {
    int n;
    int adjMat[N][N];
} GraphType;

void initGraph(GraphType *G) {
    G->n = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            G->adjMat[i][j] = 0;
        }
    }
}

void makeVertex(GraphType *G) {
    G->n++;
}
void insertEdge(GraphType *G, int u, int v) {
    G->adjMat[u][v] = G->adjMat[v][u] = 1;
}
void print(GraphType *G) {
    for(int i=1; i<=G->n; i++) {
        printf("| ");
        for(int j=1; j<=G->n; j++) printf("%d ", G->adjMat[i][j]);
        printf("|\n"); 
    }
}

void rDFS(GraphType *G, int s) {
    printf("[%d]", s);
    visited[s] = 1;
    for(int t=1; t<=G->n; t++) {
        if(G->adjMat[s][t]==1 && visited[t]==0) {
            rDFS(G, t);
        }
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

void BFS(GraphType *G, int s) {
    QueueType  Q;
    initQueue(&Q);
    visited[s] = 1;
    printf("[%d] ", s);
    enqueue(&Q, s);
    while(!isQueueEmpty(&Q)) {
        s = dequeue(&Q);
        for(int t=1; t<=G->n; t++) {
            if (G->adjMat[s][t]==1 && visited[t]==0) {
                visited[t] = 1;
                printf("[%d] ", t);
                enqueue(&Q, t);
            }  
        }
    }
}
void sBFS(GraphType *G, int s) {
    StackType S;
    initStack(&S);
    push(&S, s);
    while(!isStackEmpty(&S)) {
        int v = pop(&S);
        if (visited[v]==0) {
            visited[v] = 1;
            printf("[%d] ");

            for (int i=0; i<N; i++) {
                if (G->adjMat[v][i] && visited[i]==0) {
                    push(&S, i);
                }
            }
        }
    }
}

int main() {
    GraphType G;
    initGraph(&G);
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        makeVertex(&G);
    }
    insertEdge(&G, 1, 2);insertEdge(&G, 1, 3);insertEdge(&G, 1, 5);
    insertEdge(&G, 2, 3);
    insertEdge(&G, 3, 4);insertEdge(&G, 3, 5);
    insertEdge(&G, 4, 5);
    print(&G);
    
    // printf("rDFS: "); rDFS(&G, 4);
    // printf("BFS: "); BFS(&G, 4);
    printf("sBFS: "); sBFS(&G, 4);
    return 0;
}