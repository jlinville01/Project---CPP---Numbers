#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Number {
public:
    Number();
    Number(int val);

    // Get the number's value
    virtual int getValue() const;
    // Print the number to the screen
    virtual void print() const;
    // Add the given number to this number
    virtual void add(int val);
    // Subtract the given number from this number
    virtual void sub(int val);
    // Reverse this number. E.g 42 -> 24
    virtual void reverse();
protected:
    string value;
};



Number::Number() {
    value = "0";
}

Number::Number(int val) {
    value = to_string(val);
}

int Number::getValue() const {
    int integer;
    integer = stoi(this->value);
    return integer;
}

void Number::print() const {
    cout << getValue() << endl;
}

void Number::add(int val) {
    int integer, sum;
    integer = stoi(value);
    sum = integer + val;
    value = to_string(sum);
}

void Number::sub(int val) {
    int integer, minus;
    integer = stoi(this->value);
    minus = integer - val;
    value = to_string(minus);
}

void Number::reverse() {
    value = string(value.rbegin(), value.rend());
}

// FunnyNumber inherits from Number and overrides the add and sub behaviors
class FunnyNumber: public Number {
public:
    // Make a funny number with value 0
    FunnyNumber();
    // Make a funny number with value val
    FunnyNumber(int val);
    /*
     * Funny add the other number to this number.  e.g.: 2 + 2 -> 22; 12 + 34 = 1234
     * Overrides the Number add function.
     */
    virtual void add(int val);
    /*
     * Funny subtract the other number from this number.
     * e.g.:    12345 - 13 = 245
     *          112234 - 10 = 2234
     *          123 - 456 = 123
     *  Overrides the Number sub function.
     */
    virtual void sub(int val);
};

FunnyNumber::FunnyNumber() : Number() {
      // do nothing in the body
}

FunnyNumber::FunnyNumber(int val) : Number() {
    value = to_string(val);
}

void FunnyNumber::add(int val){
    string integer, sum;
    integer = to_string(val);
    sum = (this->value) + integer;
    value = sum;
}

void FunnyNumber::sub(int val) {
    int j = 0;
    string x = to_string(val);
    string str;
    do {
        for (unsigned i=0; i<value.length(); i++) {
            if (value.at(i) == x.at(j)) {
                value.erase(i,1);
                i = i-1;
            }
        }
        j++;
    } while (j < x.length());
}

int main() {
        // Number examples
    cout << "Numbers do normal addition and subtraction." << endl;
    Number n1, n2(42), n3(123);
    cout<<"Initial values:"<<endl;
    n1.print();
    n2.print();
    n3.print();
    cout<<"Reversed:"<<endl;
    n1.reverse();
    n2.reverse();
    n3.reverse();
    n1.print();
    n2.print();
    n3.print();
    cout<<"Addition:"<<endl;
    Number n4(123);
    n4.add(45);
    n4.print();
    cout << "Subtraction:" << endl;
    Number n6(1234);
    n6.sub(13);
    n6.print();
    cout<<endl;
    
    // FunnyNumber examples
    cout << "Funny numbers do everything Numbers do but do weird addition and subtraction." << endl;
    FunnyNumber fn1, fn2(42), fn3(123);
    cout << "Initial values:" << endl;
    fn1.print();
    fn2.print();
    fn3.print();
    cout << "Reversed:" << endl;
    fn1.reverse();
    fn2.reverse();
    fn3.reverse();
    fn1.print();
    fn2.print();
    fn3.print();
    cout << "Funny Addition:" << endl;
    FunnyNumber fn4(123);
    fn4.add(45);
    fn4.print();
    cout << "Funny Subtraction:" << endl;
    FunnyNumber fn6(123321);
    fn6.sub(13);
    fn6.print();
    cout<<endl;

    return 0;
}