#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void parseDirectory (ifstream &fin_D, ofstream &fileOut, string &tempDirectory, string &input_directory);

void createDirectory (ofstream &fOut_D, string &input_directory);

void addFileType (ifstream &fin_FT, ofstream &fOut_FT, vector<string> &fileTypes);
