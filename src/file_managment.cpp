#include "../inc/file_managment.hh"
#include "../inc/helper_func.hh"

using namespace std;


// Checks whether the file exists
bool file_exist(string name)
{
    ifstream myFile;
    myFile.open(name);
    return myFile.is_open();
}


// Changes the name of the file if file with that name already exists
void change_file_name(string * name)
{
    *name = "new_" + *name;
    if(file_exist(*name))   // If the file with that name still exists
        change_file_name(name);     // call the function again
}


// Saves time of sorting to file
bool time_to_file(string name, double sort_time[], int size, float percent)
{
    ofstream myFile(name, ios_base::out| ios_base::app);    // Open file with option to only add text
                                                            // at the end
    if(is_full(name))       // If it's full
        ofstream myFile(name);  // reduce the size and rewrite it

    if(!myFile.is_open())   // If it won't open
    {                       // give the error
        cerr << " Error: Opening file to save have failed!" << endl;
        return false;
    }

    myFile << fixed << setprecision(2);
    myFile << percent << "% OF ARRAY IS SORTED";    // Information on what iteration it's saving
    if (percent == 100)
        myFile << ", BUT IT'S REVERSED";
    myFile << endl;
    myFile << "Average time it took to sort 1 array with " << size << " elements:\n ";
    myFile << sum_array(sort_time, 100)/100 << ';' << endl;     // Saves average time of sorting

    for (int i = 0; i < 100; i++)
    {
        myFile << "Array nr. " << i + 1 << ";";
        myFile  << sort_time[i] << endl;
    }
    myFile << endl;

    myFile.close();

    return true;
}

// Marks file ass full
bool mark_as_full(string name)
{
    ofstream myFile(name, ios_base::out| ios_base::app);    // Open file with option to only add text
                                                            // at the end
    if(!myFile.is_open())
    {
        cerr << " Error: Opening file to mark as full have failed!" << endl;
        return false;
    }

    myFile << endl;
    myFile << "End of results";

    myFile.close();
}

// Checks if the file is full, by checking if the last line of file is
// string "End of results"
bool is_full(string name)
{
    string temp;
    ifstream myFile(name);  // Open file to read only
    if(!myFile.is_open())   // If it won't open
    {                       // give the error
        cerr << " Error: Opening file to read have failed!" << endl;
        return false;
    }

    myFile.seekg(-1,ios_base::end);                // go to one spot before the EOF

    bool keepLooping = true;
    while(keepLooping)
    {
        char ch;
        myFile.get(ch);                            // Get current byte's data

        if((int)myFile.tellg() <= 1)
        {             // If the data was at or before the 0th byte
            myFile.seekg(0);                       // The first line is the last line
            keepLooping = false;                // So stop there
        }
        else if(ch == '\n')
        {                   // If the data was a newline
            keepLooping = false;                // Stop at the current position.
        }
        else
        {                                  // If the data was neither a newline nor at the 0 byte
            myFile.seekg(-2,ios_base::cur);        // Move to the front of that data, then to the front of the data before it
        }
    }

    getline(myFile, temp);

    return temp == "End of results";
}
