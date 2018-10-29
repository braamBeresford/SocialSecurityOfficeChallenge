#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define NUM_RECORDS 100'000'000

string randName();
int randSS();
int main(){
	FILE *myFile = fopen("ss.txt", "w");

	cout << "Not Threading... " << endl;
	for(int i = 0; i < NUM_RECORDS; i++){
		fprintf(myFile, "%s: %d\n", randName().c_str(), randSS());
	}

	cout << "Done. " << endl;

	return 0;
}



