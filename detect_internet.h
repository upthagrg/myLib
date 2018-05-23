/*******************************************************
*Title: detect_internet.h
*Author: Glenn Upthagrove
*Date: 05/22/18
*Description: A simple test for internet connectivity
*******************************************************/
#ifndef _DETECT_NET
#define _DETECT_NET
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h> //for strcmp


#define _USE_MATH_DEFINES
#include <math.h>

// multiprocessing includes 
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>


/***********************************************
* Title: detect_internet_connection
* Description: Detects if there is an internet 
* connection present.
***********************************************/
int	detect_internet_connection(){
	int devnul;
	pid_t   childid;
	int child_exit = -5;
	int con;
	int ret;

	devnul = open("/dev/null", O_WRONLY);

	childid = fork();

        switch(childid){

        case -1: //error
                printf("ERROR SPAWNING CHILD\n");
                fflush(stdout);
                exit(2);

        case 0: //child
                //exec into wget
		dup2(0, devnul); //duplicate /dev/null to stdin
		dup2(1, devnul); //duplicate /dev/null to stdout
		dup2(2, devnul); //duplicate /dev/null to stderr
                ret = execlp("wget", "wget", "www.google.com", NULL);
                if(ret == -1){
			printf("ERROR CHECKING CONNECTION\n");
			fflush(stdout);
			exit(1);
                }

        default: //parent
                //wait on wget
                waitpid(childid, &child_exit, 0);
		if(child_exit == 0){
			con = 1;
		}
		else{
			con = 0;
		}
        }
	if(con == 1){ //clean up index.html
		childid = fork();
		        switch(childid){
        
	        case -1: //error
	                printf("ERROR SPAWNING CHILD\n");
	                fflush(stdout);
	                exit(2);
	        
	        case 0: //child
	                //exec into rm
	                ret = execlp("rm", "rm", "./index.html", "-f", NULL);
	                if(ret == -1){
	                        printf("ERROR REMOVING INDEX.HTML\n");
	                        fflush(stdout);
	                        exit(1);
	                }
		        
        	default: //parent
        	        //wait on rm
        	        waitpid(childid, &child_exit, 0);
        	}
	}
	return con;
}
#endif
