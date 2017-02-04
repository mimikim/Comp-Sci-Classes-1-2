#include <iostream>
#include <fstream>
using namespace std;

int main ()
{
    ifstream readFile; 
    ofstream PrintFile;

    int Rows,
        Columns;

    // This part of the program reads the data and assigns values to variables rows and columns
    readFile.open("Data.txt");

    readFile >> Rows;
    readFile >> Columns;

    readFile.close();

    // Open file to write output
    PrintFile.open("Printout.txt");

        
    // Looping statements to create table
    for (int row = 2; row <= (Rows + 1); row++)
    {
        if (row % 2 == 0)
        {
            for (int col = 1; col <= Columns; col++)
            {
                cout << "0 ";
                PrintFile << "0 ";
            }

            PrintFile << endl;
        }
        else
        {    
            for (int col = 1; col <= Columns; col++)
            {
                cout << "1 ";
                PrintFile << "1 ";
            }

            PrintFile << endl;
        }

        cout << endl;
    }

    PrintFile.close();
    system("pause");
}

/*
0 0 0 0 0 0 0
1 1 1 1 1 1 1
0 0 0 0 0 0 0
1 1 1 1 1 1 1
0 0 0 0 0 0 0
Press any key to continue . . .
*/