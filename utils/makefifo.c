/*********************************************
*Title: makefifo.c
*Author Glenn Upthagrove
*Date: 6/21/2018
*Description: Makes a set of FIFO'd in the 
*filesystem under the names given to it from 
*command line.
*********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char** argv){
        int ret = 0;
	int i = 1;
        if(argc<2){
                printf("ERROR: NO FIFO NAME GIVEN\n");
		printf("USAGE: makefifo <fifo name> <fifo name> ... \n");
                exit(1);
        }
	for(i; i<argc; i++){
        	ret = mkfifo(argv[i], 0775);
	}
        return ret;
}

