#ifndef CPULIB
#define CPULIB
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void _cpuid_asm(unsigned int* a, unsigned int* b, unsigned int* c, unsigned int *d){
        __asm__ __volatile__(
                 "cpuid;"
                 : "=a"(*a), "=b"(*b), "=c"(*c), "=d"(*d)
                 : "a"(*a)
                 );
}

void _cpuid_asm_c(unsigned int* a, unsigned int* b, unsigned int* c, unsigned int *d){
        __asm__ __volatile__(
                 "cpuid;"
                 : "=a"(*a), "=b"(*b), "=c"(*c), "=d"(*d)
                 : "a"(*a), "c"(*c)
                 );
}

int base2(int exp){
        int i=0;
        int temp = 2;

        if(exp == 0){
                return 1;
        }
        for(i; i<exp-1; i++){
                temp = temp * 2;
        }
        return temp;
}

void _uint_to_bin(unsigned int in, char* out){
        int i=(8*(sizeof(unsigned int)));
        int j = 0;

        memset(out, '\0', (i+1));
        i--;
        for(i; i>=0; i--){
                if(in >= base2(i)){
                        out[j] = '1';
                        in = in - (base2(i));
                }
                else{
                        out[j] = '0';
                }
                j++;
        }
}

int bin2int(char* binary, int start, int size){
        int exp=size-1;
        int i = 0;
        int temp=0;
        for(i; i<size; i++){
                if(binary[start+i] == '1'){
                        temp += base2(exp);
                }
                exp--;
        }
        return temp;
}

void int2hex(int temp, char* out, int idx){
	switch(temp){
		case 0:
			out[idx] = '0';
		case 1:
			out[idx] = '1';
		case 2:
			out[idx] = '2';
		case 3:
			out[idx] = '3';
		case 4:
			out[idx] = '4';
		case 5:
			out[idx] = '5';
		case 6:
			out[idx] = '6';
		case 7:
			out[idx] = '7';
		case 8:
			out[idx] = '8';
		case 9:
			out[idx] = '9';
		case 10:
			out[idx] = 'A';
		case 11:
			out[idx] = 'B';
		case 12:
			out[idx] = 'C';
		case 13:
			out[idx] = 'D';
		case 14:
			out[idx] = 'E';
		case 15:
			out[idx] = 'F';
		default:
			write(2, "ERROR CONVERTING INTEGER TO HEXIDECIMAL\n", 40);
			exit(1);
	}
}

char* bin2hex(char* bin, int offset){
	int i=0; 
	int length1 = strlen(bin);
	int length2;
	char* temp;
	if((length1%4) != 0){
		switch(length1%4){

		}
	}
	length2 = (strlen());
	temp = malloc(length2+1);
	memset(temp, '\0', length2+1);
	for(i; i<length1; i++){
		int2hex((bin2int((), (4*i), 4)), temp, i);
	}
}
#endif
