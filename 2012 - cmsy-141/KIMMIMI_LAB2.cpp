/*
    Mimi Kim
    9/25/12
    CMSY 141
    LAB 2
*/

#include <iostream> // Required for cout and cin commands
#include <iomanip>  // Required for setw and setprecision commands
#include <string>   // Required for string input
using namespace std;

int main()
{
    int NumberofNotebooks,  // Number o' notebooks
        NumberofPencils,    // Number o' pencils
        NumberofPens,       // Number o' pens
        ChoiceCase;         // So that I can use a switch statement!

    double  SubtotalNotebooks = 0,  // Subtotal of Notebooks,
                                    // values set to 0 so it doesn't mess up when adding GrandTotal
            SubtotalPencils = 0,    // Subtotal of Pencils
            SubtotalPens = 0,       // Subtotal of Pens
            GrandTotal;             // The Grand Total!

    string Choice,  // Menu Input
        CouponCode; // Yes or No Coupon input for PENS

    const double    NOTEBOOKPRICE = 1.5,    // CONSTANT Notebook Price
                    PENCILPRICE1 = .2,      // CONSTANT Pencil Price for 1-4 pencils
                    PENCILPRICE2 = .15,     // CONSTANT Pencil Price for 5-9 pencils
                    PENCILPRICE3 = .1,      // CONSTANT Pencil Price for 10+ pencils
                    PENPRICE1 = .3,         // CONSTANT Pen Price
                    PENPRICE2 = .25;        // CONSTANT Pen Price WITH COUPON APPLIED

    do
    {
        cout << "This store sells notebooks, pencils, and pens." << endl;
        cout << "Type NOTEBOOK, PENCIL, PEN or EXIT: ";

        getline (cin, Choice);
        
        // Formatting stuff
        cout << setprecision(2) << showpoint << fixed;
        cout << endl;

        // Here we convert the Choice STRING INPUT into integers 
        // So that I may use a switch statement
        if (Choice == "NOTEBOOK" || Choice == "Notebook" || Choice == "notebook")
            ChoiceCase = 1;
        else if (Choice == "PENCIL" || Choice == "Pencil" || Choice == "pencil")
            ChoiceCase = 2;
        else if (Choice == "PEN" || Choice == "Pen" || Choice == "pen")
            ChoiceCase = 3;    
        else if (Choice == "EXIT" || Choice == "Exit" || Choice == "exit")
            ChoiceCase = 4;
        else
            ChoiceCase = 5;

        // Switch Statement for each Choice Option!
        switch(ChoiceCase)
        {
        case 1:
            {
                cout << "\tHow many notebooks would you like to purchase? ";
                cin >> NumberofNotebooks;

                // While Loop to keep the number a POSITIVE INTEGER!!
                while (NumberofNotebooks < 0)
                {
                    cout << "\tHow many notebooks would you like to purchase? ";
                    cin >> NumberofNotebooks;
                }
            
                // Calculate Subtotal
                SubtotalNotebooks = NumberofNotebooks * NOTEBOOKPRICE;
    
                cout << "\tYour subtotal is $ " << SubtotalNotebooks << endl << endl;
    
                cin.ignore();   // I had to google extensively to figure this one out!!!!
                                // The problem was that the computer was saving an extra input
                                // So when I put a number and hit ENTER, it was saving ENTER as an input
                                // And using that as the new input for Choice
                                // So that was why the loop was looping twice!!
                                // Then I realized, we "learned" this in chapter one... haha...
                break;
            }

        case 2:
            {
                cout << "\tHow many pencils would you like to purchase? ";
                cin >> NumberofPencils;

                // While Loop to keep the number a POSITIVE INTEGER!!
                while (NumberofPencils < 0)
                {
                    cout << "\tHow many pencils would you like to purchase? ";
                    cin >> NumberofPencils;
                }
            
                // If statements because the price of pencils vary depending on quantity
                if (NumberofPencils >= 1 && NumberofPencils <= 4)
                    SubtotalPencils = NumberofPencils * PENCILPRICE1;
                else if (NumberofPencils >= 5 && NumberofPencils <= 9)
                    SubtotalPencils = NumberofPencils * PENCILPRICE2;
                else
                    SubtotalPencils = NumberofPencils * PENCILPRICE3;

                cout << "\tYour subtotal is $ " << SubtotalPencils << endl << endl;

                cin.ignore();
                break;
            }

        case 3:
            {
                cout << "\tHow many pens would you like to purchase? ";
                cin >> NumberofPens;

                // While Loop to keep the number a POSITIVE INTEGER!!
                while (NumberofPens < 0)
                {
                    cout << "\tHow many pens would you like to purchase? ";
                    cin >> NumberofPens;
                }
            
                cin.ignore();

                //PENS uses coupons
                cout << "\n\tPlease type in a coupon code or NONE: ";

                //String input for coupons
                getline (cin, CouponCode);
            
                if (CouponCode == "pen123")
                {
                    cout << "\tValid Code Entered.\n";
                    SubtotalPens = NumberofPens * PENPRICE2;
                    cout << "\tYour subtotal is $ " << SubtotalPens << endl << endl;
                }
                else
                {
                    SubtotalPens = NumberofPens * PENPRICE1;
                    cout << "\tYour subtotal is $ " << SubtotalPens << endl << endl;
                }

                break;
            }

        case 4:
            {
                // Calculate GrandTotal
                GrandTotal = SubtotalNotebooks + SubtotalPencils + SubtotalPens;

                cout << "\tYour Total Purchase is: $" << GrandTotal << endl << endl;
                break;
            }

        case 5:
            {
                cout << "\tPlease enter a valid choice, you silly user!!" << endl << endl;
                break;
            }
        }

    } while(Choice != "EXIT" && Choice != "Exit" && Choice != "exit");

    system("pause");
    return 0;
}

/* EXAMPLE NUMERO UNO

This store sells notebooks, pencils, and pens.
Type NOTEBOOK, PENCIL, PEN or EXIT: notebook

    How many notebooks would you like to purchase? 2
    Your subtotal is $ 3.00

This store sells notebooks, pencils, and pens.
Type NOTEBOOK, PENCIL, PEN or EXIT: pencil

    How many pencils would you like to purchase? 7
    Your subtotal is $ 1.05

This store sells notebooks, pencils, and pens.
Type NOTEBOOK, PENCIL, PEN or EXIT: EXIT

    Your Total Purchase is: $4.05

Press any key to continue . . .
*/

/* EXAMPLE NUMBER 2

This store sells notebooks, pencils, and pens.
Type NOTEBOOK, PENCIL, PEN or EXIT: PEN

    How many pens would you like to purchase? 4

    Please type in a coupon code or NONE: NONE
    Your subtotal is $ 1.20

This store sells notebooks, pencils, and pens.
Type NOTEBOOK, PENCIL, PEN or EXIT: paper

    Please enter a valid choice, you silly user!!

This store sells notebooks, pencils, and pens.
Type NOTEBOOK, PENCIL, PEN or EXIT: PENCIL

    How many pencils would you like to purchase? -2
    How many pencils would you like to purchase? -5
    How many pencils would you like to purchase? 2
    Your subtotal is $ 0.40

This store sells notebooks, pencils, and pens.
Type NOTEBOOK, PENCIL, PEN or EXIT: EXIT

    Your Total Purchase is: $1.60

Press any key to continue . . .
*/

/* EXAMPLE NUMBER THREE!!

This store sells notebooks, pencils, and pens.
Type NOTEBOOK, PENCIL, PEN or EXIT: notebook

    How many notebooks would you like to purchase? 4
    Your subtotal is $ 6.00

This store sells notebooks, pencils, and pens.
Type NOTEBOOK, PENCIL, PEN or EXIT: PEN

    How many pens would you like to purchase? 5

    Please type in a coupon code or NONE: pen123
    Valid Code Entered.
    Your subtotal is $ 1.25

This store sells notebooks, pencils, and pens.
Type NOTEBOOK, PENCIL, PEN or EXIT: NOTEBOOK

    How many notebooks would you like to purchase? 3
    Your subtotal is $ 4.50

This store sells notebooks, pencils, and pens.
Type NOTEBOOK, PENCIL, PEN or EXIT: EXIT

    Your Total Purchase is: $5.75

Press any key to continue . . .
*/