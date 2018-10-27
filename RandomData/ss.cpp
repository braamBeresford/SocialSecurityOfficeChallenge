#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


string randName();
int randSS();
int main(){
	srand (time(NULL));
	ofstream myfile;
	myfile.open("ss.txt");
	for(int i = 0; i < 100000000; i++){
		myfile << randName() << " " << randSS() << endl;
	}
	myfile.close();
	return 0;
}

string randName(){
	int len = rand()%(12-8 + 1) + 8;
	
	string test = "";

	for(int i =0 ; i < len; i ++){
		test += ((char)('a' + rand()%26));
	}

	return test;

}


int randSS(){
	int ss = 0;

	for(int i =0; i < 9; i++){
		ss = ss*10 + rand()%10;
	}
	return ss;
}

