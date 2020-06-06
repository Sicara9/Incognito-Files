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

    // loop for Task Manager

    ofstream file;
    file.open ("Problem.txt"); // NAME CAN CHANGE
    file.close ();

    system("tasklist > C:\\Users\\benja\\OneDrive\\Documents\\Hackathon\\Problem.txt"); //*****EDIT THIS*****

    fstream files;
    string word;
    string filename;
    string type[10];
    type[0] = "Nothing"; // PLACE HOLDER
    filename = "Problem.txt";
    
    
    while (!exit)
    {
        while (type[0] == "Nothing")
        {
            system("tasklist > C:\\Users\\benja\\OneDrive\\Documents\\Hackathon\\Problem.txt"); //*****EDIT THIS ******
            files.open(filename);

            while (files >> word)
            {

                cout << word << endl; // DELETE THIS LINE
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
        //Run vector list for name ***************************

        cout << "Would you like to save or delete this file? (s/d) ";
        cin >> save;
        if (save == 's' || save == 'S')
        {
            exit = true;
            // then change vector to saved **************
        }
        else
        {
            // Change the last digit in the vector name to delete **************
            // label vector *******************
        }

        // task manager PID close
        if (!exit)
        {
            while (escape == false)
            {
                system("tasklist > C:\\Users\\benja\\OneDrive\\Documents\\Hackathon\\Problem.txt"); // COULD CHANGE FIX
                files.open(filename);
                escape == true;
                while (files >> word)
                {

                    //This will search to see if the program is still open
                    if (word == type[i])
                    {
                        escape == false;

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
        else
        {
            ;
        }
    }

    cout << "Thank you for using Incognito Files!";

    return 0;

}