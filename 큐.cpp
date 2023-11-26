#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

typedef char element;

typedef struct {
	element queue[N];
	int front, rear;
} QueueType;

void init(QueueType *Q) {
	Q->front = Q->rear = 0;
}

int isEmpty(QueueType *Q) {
	return Q->front==Q->rear;
}

int isFull(QueueType *Q) {
	return Q->front == (Q->rear+1) % N;
}

void enqueue(QueueType *Q, element e) {
	if (isFull(Q)) return;
	Q->queue[(++Q->rear) % N] = e;
}

void print(QueueType *Q) {
	printf("Front pos: %d, Rear Pos: %d\n", Q->front, Q->rear);
//	for(int i= Q->front+1; i <= Q->rear; i++) {
//		printf("[%c] ", Q->queue[i]);
//	}
	int i=Q->front;
	while (i!=(Q->rear)%N) {
		i = (i+1)%N;
		printf("[%c] ", Q->queue[i]);
	}
}

element dequeue(QueueType *Q) {
	if (isEmpty(Q)) return '.';
	return Q->queue[(++Q->front)%N];
}
element peek(QueueType *Q) {
	if (isEmpty(Q)) return '.';
	return Q->queue[(Q->front+1)%N];
}


int main() {
	QueueType q;
	init(&q);
	srand(time(NULL));
	for(int i=0; i<7; i++) {
		enqueue(&q, rand()%26+65);	
	}
	print(&q);
	printf("%c ", dequeue(&q));
	printf("%c ", dequeue(&q));
	printf("%c\n", dequeue(&q));
	for(int i=0; i<6; i++) {
		enqueue(&q, rand()%26+65);	
	}
	print(&q);
	printf("%c\n", dequeue(&q));
	print(&q);
	return 0;
}
