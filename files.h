/*******************************************************************************************
*Title: files.h
*Author: Glenn Upthagrove
*Date: 01/24/2018
*Description: A set of useful utilites for working with files 
*******************************************************************************************/
#ifndef FILESH
#define FILESH
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int read_file(char* buff, char* file_name){ // version without file already open 
	int bytes;
	int file;
	struct stat bucket;
	file = open(file_name, O_RDONLY); // open the file
	stat(file_name, &bucket); // get informaton about the file
	if(buff != NULL){
		free(buff); // if not null, free memory 
	}	
	buff = malloc((sizeof(char))*(bucket.st_size+1)); // allocate memory (size of file + 1)
	memset(buff, '\0', bucket.st_size+1); // Clear out the buffer array
        bytes = read(text_file, buffer, bucket.st_size); // read the file into buffer
	close(file); // close the file
	return bytes; //return number of bytes read, or error number 
}


int compare(char* file1, char* file2){
	char* buff1 = NULL;
	char* buff2 = NULL;
	read_file(buff1, file1);
	read_file(buff2, file2);
	if(strcmp(buff1, buff2) != 0){
		free(buff1);
		free(buff2);
		return 1;
	}
	else{
		free(buff1);
		free(buff2);
		return 0;
	}
}
#endif
