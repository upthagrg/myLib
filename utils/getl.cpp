/**********************************
*Title: getl.cpp
*Author: Glenn Upthagrove
*Date: 6/21/2018
*Decscription: Gets one line at a 
*time from a file.
**********************************/
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
using namespace std;
int main(int argc, char** argv){
	string res;
	bool clean = false;
	int i=1;
	if(argc<2){
		cout << "USAGE: ./getl <arg> ... <file name>" << endl;
		return 1; //error code
	}
	for(i; i<argc-1; i++){
		if (strcmp(argv[i], "-clean")==0){
			clean = true;
		}
		else{
			cout << "Unrecognized argument " << argv[i] << " for getl." << endl;
			return 2; //error code
		}
	}
	i = argc-1;
	ifstream file(argv[i]);
	while(getline(file, res)){
		if(!clean){
			cout<<"Line: " << res << endl;
		}
		else{
			cout<< res << endl;
		}
	}
	return 0;
}
