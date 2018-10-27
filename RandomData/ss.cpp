#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

#define NUM_RECORDS 1000000

string randName();
int randSS();
int main(){
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	srand (time(NULL));
	ofstream myfile;
	myfile.open("ss.txt");
	for(int i = 0; i < NUM_RECORDS; i++){
		myfile << randName() << " " << randSS() << endl;
	}
	myfile.close();
		cout << "Not Threading... " << endl;

	cout << "Done. " << endl;
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>( t2 - t1 ).count();

	cout << "Duration " << duration << endl;
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

