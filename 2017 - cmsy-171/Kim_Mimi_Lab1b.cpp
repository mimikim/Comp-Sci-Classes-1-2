/*********************************
Name:	Mimi Kim
Date:	2/2/2017
Lab:	Lab 1b

Using Vectors
**********************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> animalName;
vector<int> animalAge;

// assemble info
void collectAnimals() {
	int maxInput = 5,
		ageInput;
	string nameInput;

	for (int x = 0; x < maxInput; x++) {
		cout << "Animal #" << x + 1 << ": ";
		cout << "\n\tEnter Name: ";
		cin >> nameInput;

		// Break loop is nameInput is a variation of "stop"
		if (nameInput != "STOP" && nameInput != "Stop" && nameInput != "stop") {
			animalName.push_back(nameInput);
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

		animalAge.push_back(ageInput);
		cout << "\n";
	}
}

// output info
void outputAnimals() {
	int arraySize = animalAge.size();

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