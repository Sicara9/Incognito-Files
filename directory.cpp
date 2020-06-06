#include <iostream>
#include <fstream>
#include "directory.h"

using namespace std;

void parseDirectory (ifstream &fin_D, ofstream &fileOut, string &tempDirectory, string &input_directory) {
  fin_D.open("directory.txt");

  if (fin_D.is_open()) {

    if (getline (fin_D, tempDirectory)) {
      if (tempDirectory == "File: ") {
        if (getline (fin_D, tempDirectory)) {
          if (!system(("dir " + tempDirectory).c_str())) {
            fileOut.open("database.txt");
            fileOut.close();
            system(("dir " + tempDirectory + " > database.txt").c_str());
          }
          else {
            void createDirectory (ofstream fileOut, string input_directory);
          }
        }
      }
      fin_D.close();
    }
    else {
      void createDirectory (ofstream fileOut, string input_directory);
    }
  }
  else {
    cout << "Directory.txt could not be opened. ";
  }
}

void createDirectory (ofstream &fileOut, string &input_directory) {
  fileOut.open("directory.txt");
  fileOut << "File: " << endl;
  cout << "Input a directory path that you would like your files to be monitored for deletion: ";
  cin >> input_directory;
  fileOut << input_directory;
  cout << endl << input_directory << endl;
  fileOut.close();
}
