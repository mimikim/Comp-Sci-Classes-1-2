/* 
    MIMI KIM
    CMSY 141
    LAB 7
    10/22/12
*/

#include <iostream>
#include <iomanip>
using namespace std;

// FUNCTION PROTOTYPE
double average (double *, int);
int howManyA(double *, int);

int main()
{
    int score,          // TEST SCORE INPUTS
        numScores,      // NUMBER OF INDIVIDUAL TEST SCORES
        Ascores;        // NUMBER OF TOTAL A-GRADE SCORES
    double avgScore;    // AVERAGE TOTAL OF SCORES INPUTTED
    double *ptrArray;   // POINTER VARIABLE IN WHICH WE CREATE AN ARRAY

    // FORMATTING STUFF
    cout << setprecision(2) << fixed;

    do
    {
        cout << "How many individual test scores are there? ";
        cin >> numScores;
    } while (numScores < 0);
        
    // CREATE DYNAMIC ARRAY
    ptrArray = new double[numScores];

    for(int count = 0; count < numScores; count++)
    {
        cout << "Please input score: ";
        cin >> score;

        while (score < 0 || score > 100)
        {
            cout << "Please input a valid test score.\n";
            cout << "Please input score: ";
            cin >> score;
        }

        *(ptrArray + count) = score;
    }

    // FUNCTION CALL TO AVERAGE
    avgScore = average(ptrArray, numScores);

    cout << "The average score of " << numScores << " total scores is: " << avgScore << endl;


    // FUNCTION CALL TO ASCORES
    Ascores = howManyA(ptrArray, numScores);

    cout << "There are " << Ascores << " A-grade scores inputted." << endl;

    // REMEMBER TO DELETE DYNAMIC ARRAY
    delete []ptrArray;

    system("pause");
}

// AVERAGE FUNCTION
double average(double* score, int numScores)
{
    double subtotal = 0,
        grandtotal;

    for(int count = 0; count < numScores; count++)
        subtotal += *(score + count);

    grandtotal = subtotal / numScores;
    return grandtotal;
}

// HOW MANY A'S
int howManyA(double* score, int numScores)
{
    int counter = 0;

    for(int count = 0; count < numScores; count++)
    {
        if(score[count] >= 90)
            counter++;
    }

    return counter;
}


/* 

How many individual test scores are there? 5
Please input score: 20
Please input score: 44
Please input score: 65
Please input score: 100
Please input score: 100
The average score of 5 total scores is: 65.80
There are 2 A-grade scores inputted.
Press any key to continue . . .

*/