/*
	MIMI KIM
	CMSY141
	11/9/12
	LAB 8
*/

#include <iostream>
#include <string>
using namespace std;

struct BookInfo
{
	string Title;
	double Price;
};

struct Author
{
	string Name;
	BookInfo binfo[3][3];
};

void showInfo(Author a[][2], int SIZE);

void getInfo(Author a[][2], int SIZE);

int main()
{
	const int SIZE = 3;
	Author myauthor[SIZE][2] = {
		{{"NONE", {{ {"NONE", 0}, {"NONE", 0}, {"NONE", 0} }} }},	
		{{"NONE", {{ {"NONE", 0}, {"NONE", 0}, {"NONE", 0} }} }},
		{{"NONE", {{ {"NONE", 0}, {"NONE", 0}, {"NONE", 0} }} }},
	};

	cout << "Here is the data after initialization\n";
	
	// FUNCTION CALL TO SHOWINFO
	showInfo(myauthor, SIZE);

	cout << "\nGet user input\n";

	//INPUT VALUES INTO MYAUTHOR ARRAY
	getInfo(myauthor, SIZE);
	
	cout << endl;

	// FUNCTION CALL TO SHOWINFO TO SHOW NEW DATA
	showInfo(myauthor, SIZE);

	system("pause");
}

// FUNCTION TO SHOW INFO
void showInfo(Author myauthor[][2], int SIZE)
{
	int x,
		y;

	for(x = 0; x < SIZE; x++)		// FOR EACH ITERATION, DISPLAY AUTHOR NAME
	{
		cout << "The author: " << myauthor[x][0].Name << endl;

		// LOOP TO DISPLAY TITLES AND PRICES
		for(y = 0; y < SIZE; y++)	// AND FINISH THIS ENTIRE LOOP FOR THAT AUTHOR
		{
			cout << "\tThe title: " << myauthor[x][0].binfo[0][y].Title;
			cout << ", the price: $" << myauthor[x][0].binfo[0][y].Price << endl;
		}
	}
}

// GETINFO FUNCTION
void getInfo(Author myauthor[][2], int SIZE)
{
	int x,
		y;

	for(x = 0; x < SIZE; x++)		// FOR EACH ITERATION, ENTER AUTHOR NAME
	{
		cout << "Enter the author's name: ";
		getline(cin, myauthor[x][0].Name);

		// LOOP TO GET TITLES AND PRICES
		for(y = 0; y < SIZE; y++)	// AND FINISH THIS ENTIRE LOOP FOR THAT AUTHOR
		{
			cout << "Enter title " << (y + 1) << ": ";
			getline(cin, myauthor[x][0].binfo[0][y].Title);

			// BUT, IF TITLE = NONE, BREAK LOOP
			if(myauthor[x][0].binfo[0][y].Title == "NONE")
				break;

			cout << "Enter price " << (y + 1) << ": $";
			cin >> myauthor[x][0].binfo[0][y].Price;
			cin.ignore();
		}

		cout << endl;
	}
}


/*
		OUTPUT EXAMPLE!

Here is the data after initialization
The author: NONE
        The title: NONE, the price: $0
        The title: NONE, the price: $0
        The title: NONE, the price: $0
The author: NONE
        The title: NONE, the price: $0
        The title: NONE, the price: $0
        The title: NONE, the price: $0
The author: NONE
        The title: NONE, the price: $0
        The title: NONE, the price: $0
        The title: NONE, the price: $0

Get user input
Enter the author's name: Ms. ABC
Enter title 1: Intro to C++
Enter price 1: $29.99
Enter title 2: Intro to Java
Enter price 2: $39.99
Enter title 3: NONE

Enter the author's name: Ms. DEF
Enter title 1: Intro to VB
Enter price 1: $35.99
Enter title 2: Intro to C#
Enter price 2: $50
Enter title 3: Intro to C
Enter price 3: $40

Enter the author's name: Ms. GHI
Enter title 1: Intro to CS
Enter price 1: $80.99
Enter title 2: NONE


The author: Ms. ABC
        The title: Intro to C++, the price: $29.99
        The title: Intro to Java, the price: $39.99
        The title: NONE, the price: $0
The author: Ms. DEF
        The title: Intro to VB, the price: $35.99
        The title: Intro to C#, the price: $50
        The title: Intro to C, the price: $40
The author: Ms. GHI
        The title: Intro to CS, the price: $80.99
        The title: NONE, the price: $0
        The title: NONE, the price: $0
Press any key to continue . . .

*/