#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

int main(){
  FILE *myFile = fopen("ss.txt", "w");
	for(int i = 0; i < 100'000'000; i++){
    fprintf(myFile, "Breanan sucks: 555-555-5555");
	}
	return 0;
}

