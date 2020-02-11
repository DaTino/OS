#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <dirent.h>

#define SIZE 100


//members of stringQueue are:
//indexes of first and last elements of the queue
//size of the queue
//capacity of the queue
//and the elements of the queue themselves
typedef struct stringQueue
{
	int first, last;
	int   size;
	int capacity;
	char** elements;
}stringQueue;

//Queue initialization function of stated capacity.
//Initialized size of queue as 0
stringQueue* createQueue(int capacity)
{
	stringQueue* queue  = (stringQueue*) malloc(sizeof(stringQueue));
	queue->capacity     = capacity;
	queue->first   	    =  0;
	queue->last	        = -1;
	queue->elements	    = (char**)malloc(sizeof(char*)*capacity);
	return queue;
}

// Queue is full when size equals capacity
int queueFull(stringQueue* queue)
{
	return (queue->size == queue->capacity);
}

//Queue is empty when size is 0, obviously
int queueEmpty(stringQueue* queue)
{
	return (queue->size == 0);
}

//Adds data to the queue
void queueEnqueue(stringQueue* queue, char* data)
{
	if (queueFull(queue))
  {
    perror("bt: Error: Queue over capacity!");
		return; // <- add stderror message here later
  }
  else
  {
    queue->size++;                      //add space for node
  	queue->last = queue->last + 1;      //move final node over
  	if (queue->last==queue->capacity)   //make sure element gets put in rear
    {
      queue->last = 0;
    }
    //allocate space to copy string
    queue->elements[queue->last] = (char*)malloc(sizeof(data + 1)*sizeof(char));
    //fill node with copied string/
    strcpy(queue->elements[queue->last], data);
  }
	//debugging
	//printf("%s enqueued to queue\n", data);
  return;
}

//Removes data from queue
void queueDequeue(stringQueue* queue)
{
	if (!queueEmpty(queue))
	{
    queue->size--;
    queue->first++;
    if(queue->first==queue->capacity)
    {
      queue->first=0;
    }
  }
	return;
}

//get first data item in queue
char* queueFirst(stringQueue* queue)
{
	if(!queueEmpty(queue))
  {
    return queue->elements[queue->first];
  }
  return NULL;
}

//get last data item in queue
char* queueLast(stringQueue* queue)
{
	if (!queueEmpty(queue))
  {
    return queue->elements[queue->last];
  }
	return NULL;
}

/* Driver for testing
int main()
{
    stringQueue* queue = createQueue(6);

    queueEnqueue(queue, "my");
    queueEnqueue(queue, "rear");
    queueEnqueue(queue, "is");
    queueEnqueue(queue, "enormous");

    printf("%s to be dequeued from queue\n\n", queueFirst(queue));
    queueDequeue(queue);

    printf("Front item is %s\n", queueFirst(queue));
    printf("Rear item is %s\n", queueLast(queue));

    return 0;
}
*/
