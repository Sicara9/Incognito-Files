#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <string>

//#include "database.cpp"
#include "setup.cpp"
using namespace std;

int main() {

//  int looper = 1;
  ofstream fOut;
  ifstream fin;
  string iDir;
  string tempDir;
  vector<string> fileT;

  parseDirectory(fin, fOut, tempDir, iDir);
  addFileType(fin, fOut, fileT);

  return 0;
}
