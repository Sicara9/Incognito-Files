#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void fileManager (ofstream &fOut_FM, string &tempDirectory, map<string, int> &files, vector<string> &fileTypes);

void parseDirectory (ifstream &fin_D, ofstream &fileOut, string &tempDirectory, string &input_directory);

void createDirectory (ofstream &fOut_D, string &input_directory);

void addFileType (ifstream &fin_FT, ofstream &fOut_FT, vector<string> &fileTypes);
