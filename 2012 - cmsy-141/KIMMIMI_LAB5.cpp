/* 
    MIMI KIM
    CMSY 141
    10/19/12
    LAB 5
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// FUNCTION PROTOTYPES
void getData(string [], double [][4], int);
void showData(string [], double [][4], int);
int findCompanyIndex(string, string [], int);

int main()
{
    const int SIZE = 5; // HOW MANY COMPANIES
    const int QTR = 4;  // HOW MANY QUARTERS
    int quarter;        // INPUT FOR QUARTER
    int index;          // INDEX LOCATION OF ARRAY ELEMENT
    string name,        // INPUT FOR COMPANY NAME
           CompanyName[SIZE];   // COMPANY NAME ARRAY
    double SalesData[SIZE][QTR];    // TWO-DIMENSIONAL "SALES DATA PER QUARTER" ARRAY

    // FUNCTION CALLS
    getData(CompanyName, SalesData, SIZE);
    showData(CompanyName, SalesData, SIZE);

    do
    {
        // CALLING FUNCTION findCompanyIndex
        cout << "\n\nEnter the name of the company: ";
        getline(cin, name);
    
        index = findCompanyIndex(name, CompanyName, SIZE);
    
        while (index == -1)
        {
            cout << "No such company found!";
            cout << "\n\nEnter the name of the company: ";
            getline(cin, name);
            index = findCompanyIndex(name, CompanyName, SIZE);
        }
    
        // THE IF-STATEMENT TO END THIS LOOP GIVEN PROPER INPUT
            if (index == 99)
            {
                cout << "\nEnd of Program.\n";
                break;
            }

        // ENTERING THE QUARTER
        do
        {
            cout << "Enter the quarter: ";
            cin >> quarter;
        }
        while(quarter <1 || quarter > 4);

        // TO PREVENT UNINTENTIONAL INPUT
        cin.ignore();
    
        cout << "The sales for the company " << CompanyName[index];
        cout << " was $" << SalesData[index][(quarter - 1)];
    
    }
    while(name != "Stop");

    system("pause");
    return 0;
}

/* FUNCTION getData */
void getData(string CompanyName[], double SalesData[][4], int size)
{
    ifstream readData;  // TO READ DATA FROM EXTERNAL "Data.txt" FILE

    // HERE WE MUST FILL OUR ARRAYS WITH DATA
    readData.open("Data.txt");

    for (int rows = 0; rows < size; rows++) // FOR EACH ROW OF CompanyName input...
    {
        readData >> CompanyName[rows];

        for (int pos = 0; pos < 4; pos++)   // WRITE TWO DIMENSIONAL INPUT FOR SalesData!!!
        {
            readData >> SalesData[rows][pos];
        }
    }

    // AND WE CLOSE THE FILE AS WE ARE DONE
    readData.close();
}

/* FUNCTION showData */
void showData(string CompanyName[], double SalesData[][4], int size)
{
    // HERE WE OUTPUT THE DATA IN THE ARRAY
    cout << "Here is the Data from the File:" << endl;

    // BY RECYCLING THE SAME CODE WE USED TO INPUT!!
    for (int rows = 0; rows < size; rows++)
    {
        cout << "The name: " << CompanyName[rows] << "\t";

        for (int pos = 0; pos < 4; pos++)
        {
            cout << "Qtr " << (pos + 1) << ": $" << SalesData[rows][pos] << "  ";
        }

        cout << endl;
    }
}

/* FUNCTION findCompanyIndex */
int findCompanyIndex(string name, string CompanyName[], int size)
{
    // IS INPUT A SENTINEL????
    if (name == "Stop")
        return (99);

    // OTHERWISE DO THIS
    else
    {
        int x = 0;
    
        while(x < size)
        {
            if (CompanyName[x] != name)
                x++;
            else
                break;
        }
            
        // IF INPUT IS NOT FOUND 
        if (x == 5)
            return (-1);

        // IF INPUT IS FOUND
        else
            return x;
    }
}


/*
Here is the Data from the File:
The name: ABC   Qtr 1: $40000  Qtr 2: $50000  Qtr 3: $60000  Qtr 4: $70000
The name: DEF   Qtr 1: $35000  Qtr 2: $45000  Qtr 3: $55000  Qtr 4: $65000
The name: GHI   Qtr 1: $25000  Qtr 2: $26000  Qtr 3: $27000  Qtr 4: $28000
The name: JKL   Qtr 1: $31000  Qtr 2: $32000  Qtr 3: $33000  Qtr 4: $34000
The name: MNO   Qtr 1: $42000  Qtr 2: $43000  Qtr 3: $44000  Qtr 4: $45000


Enter the name of the company: ABC
Enter the quarter: 3
The sales for the company ABC was $60000

Enter the name of the company: MNO
Enter the quarter: 2
The sales for the company MNO was $43000

Enter the name of the company: PQR
No such company found!

Enter the name of the company: DEF
Enter the quarter: 5
Enter the quarter: -5
Enter the quarter: 6
Enter the quarter: 4
The sales for the company DEF was $65000

Enter the name of the company: JKL
Enter the quarter: 1
The sales for the company JKL was $31000

Enter the name of the company: Stop

End of Program.
Press any key to continue . . .
*/