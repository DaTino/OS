#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Queue
{
	char* first, last;
	int   size;
	unsigned capacity;
	char** array;
};

//Queue initialization function of stated capacity.
//Initialized size of queue as 0
struct Queue* createQueue(unsigned capacity)
{
	struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
	queue->capacity = capacity;
	queue->first	= queue->size = 0;
	queue->last	= capacity - 1; //important, via enqueue
	queue->array 	= (char**) malloc(queue->capacity * sizeof(char*));
	return queue;
}

// Queue is full when size equals capacity
int queueFull(struct Queue* queue)
{
	return (queue->size == queue->capacity);
}

//Queue is empty when size is 0, obviously
int queueEmpty(struct Queue* queue)
{
	return (queue->size == 0);
}

//Adds data to the queue
void queueEnqueue(struct Queue* queue, int data)
{
	if (queueFull(queue))
		return; // <- add stderror message here later
	queue->last = (queue->last + 1_)%queue->capacity;
	queue->array[queue->rear] = item;
	queue->size = queue->size + 1;
	//debugging
	printf("%d enqueued to queue\n", item);
}

//Removes data from queue
char* queueDequeue(struct Queue* queue)
{
	if (queueEmpty(queue))
		return INT_MIN; // <- ??? what is int min?
	int data = queue->array[queue->first];
	queue->first = (queue->first + 1)%queue->capacity;
	queue->size = queue->size - 1;
	return data;
}

//get first data item in queue
char* queueFirst(struct Queue* queue)
{
	if (queueEmpty(queue))
		return INT_MIN;
	return queue->array[queue->first];
}

//get last data item in queue
char* queueRear(Queue* queue)
{
	if (queueEmpty(queue))
		return INT_MIN;
	return queue->array[queue->rear];
}















