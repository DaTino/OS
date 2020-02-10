#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include "stringQueue.h"
//need #include for header with functions to get stats for dirs

//the queue itself will be created in main
//or should I just make one here? that may be easier
void breadthfirst(char* directory)
{
    struct dirent *dirent;
    DIR *dir;
    //maintain a queue to store files and directories
    stringQueue* queue = createQueue(50);
    //root directory
    if ((dir = opendir(directory)) == NULL)
    {
      perror("bt: Error: Failed to open directory.");
      return;
    }
    //add root directory to the queue
    queueEnqueue(queue, directory);
    while ((dirent = readdir(dir)) != NULL)
    {
      queueEnqueue(queue, dirent->d_name);
    }
    closedir(dir);


    //loop until queue is empty-all files and directories present inside root directory are processed
    while (!queueEmpty(queue))
    {
      //get next file/directory from the queue
      char* current = queueFirst(queue);
      queueDequeue(queue);
      //get list of all files and directories in the current directory
      printf("%s\n", current);

    }


    // queueEnqueue(queue, directory);
    // while (!queueEmpty)
    // {
    //   char* next = queueFirst(queue);
    //   queueDequeue(queue);
    //
    // }
}

int main()
{
  breadthfirst("./proj");
  return 0;
}
