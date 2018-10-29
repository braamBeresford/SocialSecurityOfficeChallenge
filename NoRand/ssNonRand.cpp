#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
	ofstream myfile;
	myfile.open("ss.txt");
	for(int i = 0; i < 100'000'000; i++){
		myfile << "Breanan sucks" << " " << "5555555555" << endl;
	}
	myfile.close();
	return 0;
}

