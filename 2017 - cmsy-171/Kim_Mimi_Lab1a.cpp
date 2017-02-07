/*********************************
Name:	Mimi Kim
Date:	2/2/2017
Lab:	Lab 1a

Using Arrays
**********************************/

#include <iostream>
#include <string>
using namespace std;

string animalName[5];
int animalAge[5];

// Assembles information
void collectAnimals() {
	int arrayIndex = 0,
		ageInput;
	string nameInput;

	do {
		cout << "Animal #" << arrayIndex + 1 << ": ";
		cout << "\n\tEnter Name: ";
		cin >> nameInput;

		// Break loop if nameInput is a variation of "stop"
		if (nameInput != "STOP" && nameInput != "Stop" && nameInput != "stop") {
			animalName[arrayIndex] = nameInput;
		}
		else {
			break;
		}

		cout << "\tEnter Age: ";
		cin >> ageInput;

		// Ensure age inputted is within a valid range
		while (ageInput <= 0)
		{
			cout << "Please enter a valid age.\n";
			cout << "Enter Age: ";
			cin >> ageInput;
		}

		animalAge[arrayIndex] = ageInput;
		cout << "\n";

		arrayIndex++;
	} while (arrayIndex < 5);
}

// Outputs information
void outputAnimals() {
	int arraySize = sizeof(animalAge) / sizeof(int);

	cout << "\nAuthor: Mimi Kim\nMajor: Computer Science\n";

	for (int x = 0; x < arraySize; x++) {
		// if animal age == 0, break
		if (animalAge[x] == 0) {
			break;
		}

		cout << "\nAnimal #" << x + 1 << "'s Information: ";
		cout << "\n\tName: " << animalName[x];
		cout << "\n\tAge: " << animalAge[x] << endl;
	}
}

int main() {
	collectAnimals();
	outputAnimals();

	system("pause");
	return 0;
}