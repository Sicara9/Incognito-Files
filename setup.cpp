#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include "setup.h"

using namespace std;

void parseDirectory (ifstream &fin_D, ofstream &fileOut, string &tempDirectory, string &input_directory) {
  struct stat stats;
  fin_D.open("directory.txt");

  if (fin_D.is_open()) {

    if (getline (fin_D, tempDirectory)) {
      if (tempDirectory == "File: ") {
        if (getline (fin_D, tempDirectory)) {
          // if (!system(("dir " + tempDirectory).c_str())) {
          // const string tempDir = tempDirectory;
          stat(tempDirectory.c_str(), &stats);
          if (S_ISDIR(stats.st_mode)) {
            fileOut.open("database.txt");
            fileOut.close();
            system(("dir " + tempDirectory + " > database.txt").c_str());
          }
          else {
            createDirectory (fileOut, input_directory);
          }
        }
      }
      fin_D.close();
    }
    else {
      createDirectory (fileOut, input_directory);
    }
  }
  else {
    cout << "Directory.txt could not be opened. ";
  }
}

void createDirectory (ofstream &fOut_D, string &input_directory) {
  fOut_D.open("directory.txt");
  fOut_D << "File: " << endl;
  cout << "Input a directory path that you would like your files to be monitored for deletion: ";
  cin >> input_directory;
  fOut_D << input_directory;
  cout << endl << input_directory << endl;
  fOut_D.close();
}

void addFileType (ifstream &fin_FT, ofstream &fOut_FT, vector<string> &fileTypes) {

  string tempFileType;
  string end;

  fileTypes.clear();
  fin_FT.open("FileTypes.txt");

  if (!fin_FT.is_open()) {
    fOut_FT.open("FileTypes.txt");
    fOut_FT.close();
  }
  else {
    getline (fin_FT, end);

    while (end != "*") {
      fileTypes.push_back(end);
      getline (fin_FT, end);
    }

    fin_FT.close();
  }

  cout << "Enter in the file types you want to look out for." << endl
  << "- Type 'all' to look for all file types." << endl
  << "- Type 'clear' to remove all file types you are currently looking for. " << endl
  << "- Type 'filetypes' to view all files you are currently looking for." << endl
  << "- Type * when done: ";

  cin >> tempFileType;

  fOut_FT.open("FileTypes.txt");

  while (tempFileType != "*") {
    fileTypes.push_back(tempFileType);
    fOut_FT << tempFileType;
    cin >> tempFileType;
  }

  fOut_FT.close();
}
