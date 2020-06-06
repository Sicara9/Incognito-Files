#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
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

    ofstream file;
    file.open ("TaskList.txt"); // NAME CAN CHANGE
    file.close ();
    
    // system(("tasklist > " + directory variable + "\\TaskList.txt").c_str());

    system("tasklist > C:\\Users\\benja\\OneDrive\\Documents\\Hackathon\\TaskList.txt"); //*****EDIT THIS W/ Directory Location*****

    fstream files;
    string word;
    string filename;
    string type[10];
    type[0] = "Nothing"; // PLACE HOLDER
    filename = "TaskList.txt";
    
    
    while (!exit)
    {
        i = 0;
        type[0] = "Nothing";
        while (type[0] == "Nothing")
        {
            system("tasklist > C:\\Users\\benja\\OneDrive\\Documents\\Hackathon\\TaskList.txt"); //*****EDIT THIS ******
            files.open(filename);

            while (files >> word)
            {
                //This will search for the program to open
                if (word == "WINWORD.EXE" || word == "POWERPNT.EXE" || word == "AcroRd32.exe")
                {
                    files >> word;
                    type[i] = word; // Save PID
                    i++;

                }
                else
                {
                    ;
                }
        
            }
            files.close();
        }
        // Reset i variable value
        i = 0;

        //Run vector list for name ***************************

        cout << "Would you like to save or delete this file? (s/d) ";
        cin >> save;
        fileSkip = false;
        if (save == 's' || save == 'S')
        {
            fileSkip = true;
            // then change vector to saved **************
        }
        else
        {
            // Change the last digit in the vector name to delete **************
            // label vector *******************
        }

        // task manager PID close
        if (!fileSkip)
        {
            escape = false;
            while (escape == false)
            {
                system("tasklist > C:\\Users\\benja\\OneDrive\\Documents\\Hackathon\\TaskList.txt"); // COULD CHANGE FIX
                files.open(filename);
                escape = true;
                while (files >> word)
                {

                    //This will search to see if the program is still open
                    if (word == type[i])
                    {
                        escape = false;

                    }
                    else
                    {
                        ;
                    }
        
                }
                files.close();
            }

            // delete file

            //system("del /f DELETE.txt"); INSERT THE DIRECTORY NAME AND FILE NAME HERE TO DELETE ****************

            
        }
        else
        {
            ;
        }

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

    cout << "Thank you for using Incognito Files!";

    return 0;

}