#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

//takes in all file types and parses through the unedited database.txt file
//and only leaves what is necessary behind
void databaseParser (ifstream &fin_DB, ofstream &fOut_DB, string &tempDirectory, vector<string> &fileTypes, map<string, int> &files);
