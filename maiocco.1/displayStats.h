#ifndef DISPLAYSTATS_H
#define DISPLAYSTATS_H

int bigLflag, dflag, gflag,
		iflag, pflag, sflag, tflag,
	 uflag, lflag;		//option flags, to track which option has been hit
//made these global to go between functions
//functions for individual options go here!


struct stat;
void displayStats(char* path, struct stat dirstat);

#endif
