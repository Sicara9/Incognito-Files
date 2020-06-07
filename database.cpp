#include <iostream>
#include <fstream>
#include <map>
#include <vector>

#include "database.h"

using namespace std;

void databaseParser (ifstream &fin_DB, ofstream &fOut_DB, string &tempDirectory, vector<string> &fileTypes, map<string, int> &files) {
  string parser;
  fin_DB.open("database.txt");

  while (parser.find(tempDirectory) == string::npos) {
    getline(fin_DB, parser);
  }

  while (parser != "0") {
    fin_DB >> parser;
    fin_DB >> parser;
    fin_DB >> parser;
    if ((parser == "AM") || (parser == "PM")) {
      fin_DB >> parser;
      if (parser != "<DIR>") {
        getline(fin_DB, parser);
        for (int i = 0; i < fileTypes.size(); i++) {
          if (parser.find(fileTypes[i])) {
            files.insert(pair<string, int>(parser, 0));
          }
        }
      }
      else {
        getline(fin_DB, parser);
      }
    }
    else {
      break;
    }
    //cout << parser << endl;
  }

  fin_DB.close();

  fOut_DB.open("files.txt");
  map<string, int>::iterator i;
  for (i = files.begin(); i != files.end(); i++) {
    fOut_DB << i->first << '\t' << i->second << '\n';
  }
  fOut_DB.close();
}
