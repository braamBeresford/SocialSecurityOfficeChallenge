#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <thread> 
#include <queue>
#include <mutex>
#include <chrono>

#define THREADS 3 	
#define NUM_RECORDS 1000000
using namespace std;
using namespace std::chrono;

queue<string> result;
int currResultIndex = 0;
mutex m;
ofstream myfile;

string randName();
int randSS();
void genEntry(int lower, int upper);

int main(){
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	srand (time(NULL));
	myfile.open("ss.txt");
	thread myThreads[THREADS];
	
	for(int i = 0; i < THREADS; i++){
		int bot =  (NUM_RECORDS/THREADS * i);
		int top = (NUM_RECORDS/THREADS * (i+1)) -1; 
		myThreads[i] = thread(genEntry, bot, top);
	}	
	cout << "Threading... " << endl;

	for(int i =0; i < THREADS; i++){
		myThreads[i].join();
	}
	cout << "Done. " << endl;

	myfile.close();
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>( t2 - t1 ).count();

	cout << "Duration " << duration << endl;
	return 0;
}

void genEntry(int lower, int upper){
	for(int i = lower; i < upper; i++){
		lock_guard<mutex> lock(m);
		myfile << randName() << " " << randSS() << endl;
	}
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

