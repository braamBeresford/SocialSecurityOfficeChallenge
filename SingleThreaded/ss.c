#include <stdio.h>
#include <stdlib.h>
#define NUM_RECORDS 100000000
static unsigned long x=123456789, y=362436069, z=521288629;
unsigned long xorshf96();

char* randName(){
    int random = xorshf96();
	int len = random%(12-8 + 1) + 8;
	char * name = (char*) malloc(len*sizeof(char));
    int i;
	for(i =0 ; i < len; i ++){
		name[i] = ((char)('a' + random%26));
	}

	return name;

}

int randSS(){
	int ss = 0;
    int i;
	for(i =0; i < 9; i++){
		ss = ss*10 + xorshf96()%10;
	}
	return ss;
}

unsigned long xorshf96() {          //period 2^96-1
unsigned long t;
    x ^= x << 16;
    x ^= x >> 5;
    x ^= x << 1;

   t = x;
   x = y;
   y = z;
   z = t ^ x ^ y;

  return z;
}


int main(){
    FILE *myFile = fopen("ss.txt", "w");
    printf("startings");
    int i; 
    for(i = 0; i < NUM_RECORDS; i++){
		fprintf(myFile, "%s: %d\n", randName(),  randSS());
	}

    printf("Done");
    return 0;
}


