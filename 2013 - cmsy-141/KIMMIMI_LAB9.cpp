/*
	MIMI KIM
	LAB 9
	11/14/12
	CMSY141
*/

#include <iostream>
#include <string>
using namespace std;

// CLASS DELCLARATIONS
class Student{
  private:
           string name;
           int id;
           int *test;
           int num;
           void makeArray();
  public:
           Student();
           Student(int n);
           Student(string nm, int i, int n);
           void setName(string nm)
			   {
				   name = nm;
			   }
           void setID(int i);
           void setScore(int i, int s);
           string getName() const 
			   {
				   return name; 
			   };
           int getID() const 
			   {
				   return id; 
			   };
		   void showScore();
           void display();
           ~Student();
};

//MEMBER FUNCTIONS
Student::Student() {
	string none = "None";
  setName(none);
  setID(10);
  num = 3;
  makeArray();
}

Student::Student(int n) {
	setName("None");
	setID(10);
	if(n > 0)
		num = n;
	else
		num = 3;
	makeArray();
}

Student::Student(string nm, int i, int n) {
	setName(nm);
	setID(i);
	if(n > 0)
		num = n;
	else
		num = 3;
	makeArray();
}

void Student::makeArray() {
	test = new int[num];

	for(int x = 0; x < num; x++)
		test[x] = 0;
}

void Student::setID(int i) {
 if(i >= 10 && i <= 99)
	 id = i;
 else
 {
	 id = 10;
	 cout << "Invalid.  Can not set id to " << i << " for " << getName();
	 cout << endl;
 }
}

void Student::setScore(int i, int s) {
	if(i < num && (s >= 0 && s <= 100) )
	{
		test[i] = s;
	}
	else
	{
		cout << "Invalid.  Can not set test " << i << " to " << s << " for " << getName();
		cout << endl;
	}

}

void Student::showScore() {
	for(int x = 0; x < num; x++)
	{
		cout << "Test " << x << " had a score of ";
		cout << test[x] << endl;
	}
}

void Student::display() {
	cout << "The Name: " << getName();
	cout << "\nThe ID: " << getID() << endl;
	showScore();
	cout << endl;
}

Student::~Student() {
	delete [] test;
	test = NULL;
}

int main()
{
	Student studenta;
	cout << "Calling the set functions\n";

	// ENTER TOM DATA
	studenta.setName("Tom");
	studenta.setID(200);
	studenta.setID(20);
	studenta.setScore(0, 75);
	studenta.setScore(1, 85);
	studenta.setScore(2, 95);

	// ENTER JOHN DATA
	Student studentb(4);
	studentb.setName("John");
	studentb.setID(30);
	studentb.setScore(0, 70);
	studentb.setScore(1, 85);
	studentb.setScore(2, 95);
	studentb.setScore(3, 100);

	// ENTER JOE DATA
	Student studentc("Joe", 40, 5);
	studentc.setScore(5, 95);
	studentc.setScore(4, 105);
	studentc.setScore(-5, -105);
	studentc.setScore(0, 90);
	studentc.setScore(1, 91);
	studentc.setScore(2, 92);
	studentc.setScore(3, 93);
	studentc.setScore(4, 94);

	cout << "\n\nCalling the display function\n";

	// CALLING TOM
	studenta.display();

	//CALLING JOHN
	studentb.display();

	//CALLING JOE
	studentc.display();

	system("pause");
	return 0;
}

/*
Calling the set functions
Invalid.  Can not set id to 200 for Tom
Invalid.  Can not set test 5 to 95 for John
Invalid.  Can not set test 4 to 105 for Joe
Invalid.  Can not set test -5 to -105 for Joe


Calling the display function
The Name: Tom
The ID: 20
Test 0 had a score of 75
Test 1 had a score of 85
Test 2 had a score of 95

The Name: John
The ID: 30
Test 0 had a score of 70
Test 1 had a score of 85
Test 2 had a score of 95
Test 3 had a score of 100

The Name: Joe
The ID: 40
Test 0 had a score of 90
Test 1 had a score of 91
Test 2 had a score of 92
Test 3 had a score of 93
Test 4 had a score of 94

Press any key to continue . . .
*/