#include <stdio.h>
#include <stdlib.h>

int bigLflag=0, dflag=0, gflag=0,
		iflag=0, pflag=0, sflag=0, tflag=0,
	 uflag=0, lflag=0;		//option flags, to track which option has been hit
//made these global to go between functions

int main(int argc, char **argv)
{

	extern char *optarg;		//no. of args for getopt
	extern int optind;		//current index arg for getopt
	int c, err = 0;			//counter and errors for getopt
	// int hflag=0, bigLflag=0, dflag=0, gflag=0,
	//     iflag=0, pflag=0, sflag=0, tflag=0,
	//    uflag=0, lflag=0;		//option flags, to track which option has been hit
	char *dirname;			//string for the name of our chosen directory
	static char usage[] = "usage: %s [-h] [-L -d -g -i -p -s -t -u | -l] [dirname]" //usage statement

	//getopt loop with switch for args
	while ((c = getopt(argc, argv, "hLdgipstul")) != -1)
		switch (c) {
			case 'h':
				hflag = 1;
				printf("bt: a breadthfirst directory search by Alberto Maiocco 2020.\n
								bt is invoked with the following options:\n
								h Print a help message and exit.\n
								L Follow symbolic links, if any. Default will be to not follow symbolic links.\n
								t Print information on file type.\n
								p Print permission bits as rwxrwxrwx.\n
								i Print the number of links to file in inode table.\n
								u Print the UID associated with the file.\n
								g Print the GID associated with the file.\n");
				//print a help message and exit
			case 'L':
				bigLflag = 1;
				//follow symbolic links, if any. Default will be
				//not to follow symbolic links.
			case 'd':
				dflag = 1;
				//show the time of last modification
			case 'g':
				gflag = 1;
				//print the GID associated with the file
			case 'i':
				iflag = 1;
				//print the number of links to file in inode table
			case 'p':
				pflag = 1;
				//print permission bits as rwxrwxrwx
			case 's':
				sflag = 1;
				//print the size of file in bytes. if size is
				//larger than 1K, indicate size in KB with K suffix.
				//same with MB and GB.
			case 't':
				tflag = 1;
				//print information on file type
			case 'u':
				uflag = 1;
				//print the UIS associated with the file
			case 'l':
				lflag = 1;
				//print information on the file as if the options
				//tpiugs are all specified
			case '?':
				//some default case.
		}

		//current directory if argv == 0
		//specified directory otherwise
		breadthfirst(".")

	return 0;
}
