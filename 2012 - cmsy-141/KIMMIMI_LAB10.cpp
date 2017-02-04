/*
    MIMI KIM
    LAB 10
    CMSY141
    11/24/12
*/

#include <iostream>
using namespace std;

// CLASS DECLARATIONS
class Number{
private:
    int num;
    int twiceNum;

public:
    Number();
    Number(int n);
    Number(const Number &n);
    void setNum(int n);
    void setTwiceNum(int tn);
    int getNum() const;
    int getTwiceNum() const;
    Number operator + (const Number &r);
    Number operator ++ ();
    Number operator ++ (int);
    // FRIEND FUNCTION
    friend void Reset(Number &t);
};

// MEMBER FUNCTIONS
Number::Number() {
    int n = 0;
    setNum(n);
}

Number::Number(int n) {
    setNum(n);
}

Number::Number(const Number &n) {
    setNum(n.getNum());
}

void Number::setNum(int n) {
    num = n;
    twiceNum = (2 * n);
}

void Number::setTwiceNum(int tn) {
    if (tn % 2 == 0)
        twiceNum = tn;
    else
        twiceNum = 0;
    num = (twiceNum / 2);
}

int Number::getNum() const {
    return num;
}

int Number::getTwiceNum() const {
    return twiceNum;
}

Number Number::operator + (const Number &r) {
    Number sum;
    sum.setNum(num + r.num);
    return sum;
}

Number Number::operator ++ () {
    ++num;
    setNum(num);
    return *this;
}

Number Number::operator ++ (int) {
    num++;
    setNum(num);
    return *this;
}

 void Reset (Number &t) {
     t.num = 0;
     t.twiceNum = 0;
 }


int main()
{
    Number a, b(5), c(10);
    Number d = c;
    Number e;

    cout << "a: " << a.getNum() << ", 2 X a: " << a.getTwiceNum() << endl;
    cout << "b: " << b.getNum() << ", 2 X b: " << b.getTwiceNum() << endl;
    cout << "c: " << c.getNum() << ", 2 X c: " << c.getTwiceNum() << endl;
    cout << "d: " << d.getNum() << ", 2 X d: " << d.getTwiceNum() << endl;
    cout << endl;

    Reset(b);
    cout << "After reset of b" << endl;
    cout << "b: " << b.getNum() << ", 2 X b: " << b.getTwiceNum() << endl;
    cout << endl;

    b.setNum(7);
    cout << "After b.setNum(7)" << endl;
    cout << "b: " << b.getNum() << ", 2 X b: " << b.getTwiceNum() << endl;
    cout << endl;

    b.setTwiceNum(21);
    cout << "After b.setNum(7)" << endl;
    cout << "b: " << b.getNum() << ", 2 X b: " << b.getTwiceNum() << endl;
    cout << endl;

    b.setTwiceNum(30);
    cout << "After b.setTwiceNum(30)" << endl;
    cout << "b: " << b.getNum() << ", 2 X b: " << b.getTwiceNum() << endl;
    cout << endl;

    a = b + c;
    cout << "After a = b + c" << endl;
    cout << "a: " << a.getNum() << ", 2 X a: " << a.getTwiceNum() << endl;
    cout << "b: " << b.getNum() << ", 2 X b: " << b.getTwiceNum() << endl;
    cout << "c: " << c.getNum() << ", 2 X c: " << c.getTwiceNum() << endl;
    cout << endl;

    e = ++a;
    cout << "After e = ++a" << endl;
    cout << "a: " << a.getNum() << ", 2 X a: " << a.getTwiceNum() << endl;
    cout << "e: " << e.getNum() << ", 2 X e: " << e.getTwiceNum() << endl;
    cout << endl;

    e = ++a;
    cout << "After e = a++" << endl;
    cout << "a: " << a.getNum() << ", 2 X a: " << a.getTwiceNum() << endl;
    cout << "e: " << e.getNum() << ", 2 X e: " << e.getTwiceNum() << endl;
    cout << endl;

    system("pause");
    return 0;
}

/*

a: 0, 2 X a: 0
b: 5, 2 X b: 10
c: 10, 2 X c: 20
d: 10, 2 X d: 20

After reset of b
b: 0, 2 X b: 0

After b.setNum(7)
b: 7, 2 X b: 14

After b.setNum(7)
b: 0, 2 X b: 0

After b.setTwiceNum(30)
b: 15, 2 X b: 30

After a = b + c
a: 25, 2 X a: 50
b: 15, 2 X b: 30
c: 10, 2 X c: 20

After e = ++a
a: 26, 2 X a: 52
e: 26, 2 X e: 52

After e = a++
a: 27, 2 X a: 54
e: 27, 2 X e: 54

Press any key to continue . . .

*/