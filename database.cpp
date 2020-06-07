#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

#include "database.h"

using namespace std;

void databaseParser (ifstream &fin_DB, ofstream &fOut_DB, string &tempDirectory, vector<string> &fileTypes, map<string, int> &files) {
  string parser;
  fin_DB.open("database.txt");

  while (parser.find(tempDirectory) == string::npos) {
    getline(fin_DB, parser);
    cout << parser << endl;
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
            parser.replace(parser.begin(), parser.begin()+1, "");
            files.insert(pair<string, int>(parser, 0));
            break;
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
  fOut_DB.close();
  fOut_DB.open("files.txt");
  map<string, int>::iterator i;
  for (i = files.begin(); i != files.end(); i++) {
    cout << i->first << '\t' << i->second << '\n';
  }
  for (i = files.begin(); i != files.end(); i++) {
    fOut_DB << i->first << '\t' << i->second << '\n';
  }
  fOut_DB.close();
}
