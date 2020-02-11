
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <locale.h>
#include <langinfo.h>

//functions for individual options go here!

void displayStats(char* path, struct stat dirstat)
{
  if (lflag) //follow all the below stats
  {
    tflag=1;
    gflag=1;
    uflag=1;
    pflag=1;
    iflag=1;
    sflage=1;
  }
  if (bigLflag) //follow symlinks
  {
    if(dirstat.st_mode & S_IFLNK)
    {
      char* slpath;
      if(lstat(path, &dirstat) == 0)
      {
        slpath = realpath(path, NULL);
        print("SymLink Path: %s\n", slpath);
      }
    }
  }
  if (dflag) //get date of last modification
  {
    printf(" %d", ctime(&dirstat.st_mtime));
  }
  if (tflag) //type of direntry
  {
    switch (dirstat.st_mode &S_IFMT)
    {
      case S_IFDIR: printf("%16s", "d"); break;
      case S_IFREG: printf("%16s", "-"); break;
      default: printf("%16s", "");
    }
  }
  if (pflag) //permission bits
  {
    printf( (dirstat.st_mode & S_IRUSR) ? "r" : "-");
      printf( (dirstat.st_mode & S_IWUSR) ? "w" : "-");
      printf( (dirstat.st_mode & S_IXUSR) ? "x" : "-");
      printf( (dirstat.st_mode & S_IRGRP) ? "r" : "-");
      printf( (dirstat.st_mode & S_IWGRP) ? "w" : "-");
      printf( (dirstat.st_mode & S_IXGRP) ? "x" : "-");
      printf( (dirstat.st_mode & S_IROTH) ? "r" : "-");
      printf( (dirstat.st_mode & S_IWOTH) ? "w" : "-");
      printf( (dirstat.st_mode & S_IXOTH) ? "x" : "-");
  }
  if (iflag)
  {
    printf("%4d", dirstat.st_nlink);
  }
  if (gflag)
  {
    if ((grp = getgrgid(dirstat.st_gid)) != NULL)
      printf(" %-8.8s", grp->gr_name);
    else
      printf(" %-8d", dirstat.st_gid);
  }
  if (sflag)
  {
    printf("%9jd", dirstat.st_size);
  }
}
