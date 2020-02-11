#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include "stringQueue.h"
#include "displayStats.h"
#include <sys/stat.h>
//need #include for header with functions to get stats for dirs

//the queue itself will be created in main
//or should I just make one here? that may be easier
void breadthfirst(char* directory)
{
    struct stat dirstat;
    char statbuffer[512];
    struct dirent *dirent;
    DIR *dir;
    //maintain a queue to store files and directories
    stringQueue* queue = createQueue(50);
    char pathbuf[256]; //to store path of parent dirs
    //root directory
    if ((dir = opendir(directory)) == NULL)
    {
      perror("bt: Error: Failed to open directory.");
      return;
    }
    //add root directory to the queue
    queueEnqueue(queue, directory);
    strcat(pathbuf, directory);
    char* prefix = strcat(pathbuf, "/");
    //debug printf("prefix: %s\n", prefix);

    while ((dirent = readdir(dir)) != NULL)
    {
      if (strcmp(dirent->d_name, ".") == 0 || strcmp(dirent->d_name, "..") == 0)
        continue;
      char temp[64]; strcpy(temp, prefix);
      //debug printf("temp: %s\n", temp);
      queueEnqueue(queue, strcat(temp, dirent->d_name));
    }
    closedir(dir);
    printf("%s\n", queueFirst(queue));
    stat(queueFirst(queue), &dirstat);
    displayStats(queueFirst(queue), dirstat);
    queueDequeue(queue);

    //loop until queue is empty-all files and directories present inside root directory are processed
    while (!queueEmpty(queue))
    {
      //get next file/directory from the queue
      char* current = queueFirst(queue);
      queueDequeue(queue);

      //get list of all files and directories in the current directory
      printf("%s\n", current);
      stat(current, &dirstat);
      displayStats(current, dirstat);
      if ((dir = opendir(current)) == NULL)
      {
        //debug printf("Fails: %s\n", current);
        perror("bt: Error: Failed to open directory.");
        return;
      }
      char* prefix = strcat(current, "/");
      while ((dirent = readdir(dir)) != NULL)
      {
        char temp[64]; strcpy(temp, prefix);
        if (strcmp(dirent->d_name, ".") == 0 || strcmp(dirent->d_name, "..") == 0)
          continue;
        if (dirent->d_type != DT_DIR) {
          printf("%s\n", strcat(temp, dirent->d_name));
          stat(temp, &dirstat);
          displayStats(temp, dirstat);
          continue;
        }
        queueEnqueue(queue, strcat(temp, dirent->d_name));
      }
    }

}

// int main()
// {
//   breadthfirst("./proj");
//   return 0;
// }
