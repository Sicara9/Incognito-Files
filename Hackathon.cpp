#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>

#include "setup.h"

using namespace std;

void fileManager(ofstream &fOut_FM, string &tempDirectory, map<string, int> &files, vector<string> &fileTypes)
{

    // declare variables
    char save = 'n';
    char exitChar = 'n';
    bool exit = false;
    int i = 0;
    int j = 0;
    bool escape = false;
    bool fileSkip = false;

    // loop for Task Manager

    fOut_FM.open ("TaskList.txt"); // NAME CAN CHANGE
    fOut_FM.close ();

    system("tasklist > TaskList.txt");

    //system("tasklist > C:\\Users\\benja\\OneDrive\\Documents\\Hackathon\\TaskList.txt");

    fstream file_S;
    string word;
    string filename;
    string type[10];
    type[0] = "Nothing"; // PLACE HOLDER
    filename = "TaskList.txt";
    fOut_FM.open("Recent.txt");
    fOut_FM.close();
    string name;
    vector<string> final;
    ifstream fin;
    string check;
    string deleteFileName;
    string mimic;
    string pathName;

    while (!exit)
    {
        i = 0;
        type[0] = "Nothing";
        while (type[0] == "Nothing")
        {
            //system("tasklist > C:\\Users\\benja\\OneDrive\\Documents\\Hackathon\\TaskList.txt"); //*****EDIT THIS ******
            system("tasklist > TaskList.txt");
            file_S.open(filename);

            while (file_S >> word)
            {
                //This will search for the program to open
                if (word == "WINWORD.EXE" || word == "POWERPNT.EXE" || word == "AcroRd32.exe")
                {

                    system ("dir /o-d %userprofile%\\AppData\\Roaming\\Microsoft\\Windows\\Recent > Recent.txt");
                    fin.open("Recent.txt");

                    while (fin >> mimic)
                    {
                        if (mimic == "of")
                        {
                            getline(fin, pathName);
                            pathName = pathName.replace(pathName.begin(), pathName.begin()+1, "");
                            break;
                        }

                    }
                    fin.close();

                    fin.open ("Recent.txt");

                    while (name.find(pathName) == string::npos)
                    {
                        getline(fin, name);
                    }

                    while (j < 7)
                    {

                        fin >> name;
                        fin >> name;
                        fin >> name;
                        if ((name == "AM") || (name == "PM"))
                        {
                            fin >> name;
                            if (name != "<DIR>")
                            {
                              getline(fin, name);
                              name.replace(name.end()-4, name.end(), "");
                              check = name.replace(name.begin(), name.begin()+1, "");
                                map<string, int>::iterator i;
                                for (i = files.begin(); i != files.end(); i++)
                                {
                                    if (i->first == check)
                                    {
                                      //cout << i->first << endl;
                                        deleteFileName = i->first;
                                        i->second = 1;
                                        break;
                                    }
                                }
                                final.push_back(name);
                                j++;
                            }
                            else
                            {
                                getline(fin, name);
                            }
                        }
                        else
                        {
                            break;
                        }
                    }
                    fin.close();

                    file_S >> word;
                    type[0] = word; // Save PID
                    i++;
                }
                else
                {
                    ;
                }

            }
            file_S.close();
        }
        // Reset i variable value
        i = 0;

        //Run vector list for name ***************************



        //fOut_DB << i->first << '\t' << i->second << '\n';


        // cout << "Would you like to save or delete this fOut_FM? (s/d) ";
        // cin >> save;
        // fileSkip = false;
        // if (save == 's' || save == 'S')
        // {
        //     fileSkip = true;
        //     // then change vector to saved **************
        // }
        // else
        // {
        //     // Change the last digit in the vector name to delete **************
        //     // label vector *******************
        // }

        // task manager PID close
        //if (!fileSkip)
        //{
            escape = false;
            while (escape == false)
            {
                //system("tasklist > C:\\Users\\benja\\OneDrive\\Documents\\Hackathon\\TaskList.txt"); // COULD CHANGE FIX
                system("tasklist > TaskList.txt");
                file_S.open(filename);
                escape = true;
                while (file_S >> word)
                {

                    //This will search to see if the program is still open
                    if (word == type[0])
                    {
                        escape = false;

                    }
                    else
                    {
                        ;
                    }

                }
                file_S.close();
            }

            // delete fOut_FM
cout << tempDirectory << "\\" << deleteFileName << endl;
            system(("cd " + tempDirectory + " & del /f " + deleteFileName).c_str());
            //system("del /f DELETE.txt"); INSERT THE DIRECTORY NAME AND fOut_FM NAME HERE TO DELETE ****************


        //}
        //else
        //{
           // ;
       // }

        // prompt exit program
        cout << "Would you like to exit this program? (y/n) ";
        cin >> exitChar;

        if (exitChar == 'y' || exitChar == 'Y')
        {
            exit = true;
        }
        else
        {
            exit = false;
        }

    }

    cout << "Thank you for using Incognito Files!" << endl;


}
