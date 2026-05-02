#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string readFile(string fileName) {
	
	string fileText;
	ifstream myFile(fileName);
	string tempText;
	
	// if (!myFile.is_open()) {
	// 	cerr << "ERROR: Failed to open file: " << fileName << endl;
	// 	return "";
	// }
	// else {
	// 	// cout << "File opened";
	// }
	

	while (getline(myFile, tempText) )
	{
		fileText += tempText + '\n';
	}
	
	// cout << fileText << endl;
	return fileText;
}

