#include <iostream>
#include <fstream>
#include <map>
#include <vector>

#include "setup.h"

using namespace std;

class Table {
  private:
   map<string, int> files;

 public:
  //takes in all file types and parses through the unedited database.txt file
  //and only leaves what is necessary behind
  void dataParser ();
};
