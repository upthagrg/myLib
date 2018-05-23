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
/*
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
*/
/********************************************
*Title: reverse
*Input: char* string for input, char* string 
*for output, int string size.
*Description: reverses endianess of a string 
*of hex values.
********************************************/
void reverse(char* in, char* out, int size){
        for(int i = 0; i<size; i+=2){
                out[size-1-i-1] = in[i];
                out[size-1-i] = in[i+1];
        }
}

/********************************************
*Title: get_dec
*Input: char
*Ouput: int
*Descrption: returns the decimal of a
*hexidecimal represented as a char. 
********************************************/
int get_dec(char in){
        if((int)in > 96){
                in -= 32;
        }
        if(in == '0'){
                return 0;
        }
        else if(in == '1'){
                return 1;
        }
        else if(in == '2'){
                return 2;
        }
        else if(in == '3'){
                return 3;
        }
        else if(in == '4'){
                return 4;
        }
        else if(in == '5'){
                return 5;
        }
        else if(in == '6'){
                return 6;
        }
        else if(in == '7'){
                return 7;
        }
        else if(in == '8'){
                return 8;
        }
        else if(in == '9'){
                return 9;
        }
        else if(in == 'A'){
                return 10;
        }
        else if(in == 'B'){
                return 11;
        }
        else if(in == 'C'){
                return 12;
        }
        else if(in == 'D'){
                return 13;
        }
        else if(in == 'E'){
                return 14;
        }
        else if(in == 'F'){
                return 15;
        }
        else{
                return -5;
        }
}

/*******************************************
*Title: convert_hex
*Input: char* input string, int string size
*Output: int
*description: Converts a string 
*representation of hexidecimal of length
*decribed by size into an integer.
*******************************************/
int convert_hex(char* in, int size){
        int i=0;
        int j;
        int pow;
        int cur;
        int total = 0;
        for(i; i<size; i++){
                j=0;
                cur = 1;
                pow = size-1-i;
                for(j; j<pow; j++){
                        cur *=16;
                }
                j=0;
                for(j; j<(get_dec(in[i])); j++){
                        total += (cur);
                }
        }
        return total;
}

#endif
