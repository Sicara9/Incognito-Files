#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void parseDirectory (ifstream &fin_D, ofstream &fileOut, string &tempDirectory, string &input_directory);

void createDirectory (ofstream &fileOut, string &input_directory);
