#ifndef STRINGQUEUE_H
#define STRINGQUEUE_H

typedef struct stringQueue stringQueue;

stringQueue* createQueue(int capacity);
int queueFull(stringQueue* queue);
int queueEmpty(stringQueue* queue);
void queueEnqueue(stringQueue* queue, char* data);
void queueDequeue(stringQueue* queue);
char* queueFirst(stringQueue* queue);
char* queueLast(stringQueue* queue);

#endif
