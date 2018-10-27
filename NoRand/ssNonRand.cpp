#include <iostream>
#include <string>
using namespace std;


int main(){
	ofstream myfile;
	myfile.open("ss.txt");
	for(int i = 0; i < 100000000; i++){
		myfile << "Breanan sucks" << " " << "555-555-5555" << endl;
	}
	myfile.close();
	return 0;
}

