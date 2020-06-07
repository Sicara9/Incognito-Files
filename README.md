# Incognito-Files
Incognito mode, but for your computer!

#Usage
Download all of the files located in the GitHub and be sure to compile through the Main. This program was coded
in c++ (specifically c++11) so be sure that your computer has the capacity to compile this file-type. You will 
initially be prompted to select a file directory path. Enter the path to the desired folder to be monitored. Once the 
program is running, you will be given the option to add additional file types to search. We suggest you use the "all"
command and then enter "*" to begin the file search. At this point, the program will monitor your files and wait for
a file in that designated folder to open. Once that file is opened and then closed, it will be deleted. 
*Note - This program was intended to be used to regulate downloads (and delete them in a timely manner), but feel free to
experiment with it in any folder.*

# Dependencies
Due to time-constraints, our program has several dependencies which should be noted before running.
This program can only run on Windows and is not adapted to Linex, Mac, or other OS types.
The code is currently designed to scan for .docx, .ppt, and .pdf files. Additionally, it only
recognizes Microsoft Word, Microsoft Powerpoint, and Acrobat Reader DC applications respectively. 
The program requires you to input a directory location which will be used to monitor files during the process.
The file you wish to be deleted after usage will need to be located inside that file directory which will additionally 
need to be found on your Windows installed drive (C: Drive). 
*Note - There is a strange bug where the FileTypes.txt folder will wipe when the application is closed improperly. To fix this problem,
renter file types (i.e. .docx, .pdf, etc.) into the file and it will run again.*

