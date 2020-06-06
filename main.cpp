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
  ifstream dir;
  string iDir;
  string tempDir;

  parseDirectory(dir, fOut, tempDir, iDir);
  

  return 0;
}
