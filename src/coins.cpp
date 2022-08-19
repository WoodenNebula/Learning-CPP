//REFER to moneycounter.cpp

#include<iostream>

using namespace std;

const int QUARTER_VALUE = 25, NICKEL_VALUE = 5, DIME_VALUE = 10, DOLLAR_VALUE = 100; //Values interms of cents

int main(){
    int penn, nickNo, dimeNo, quartNo, dollar, cents;    //Type of money
    cents = 0;      //Avoiding Garbage value
    
    cout << "Give me all your DOLLARS <GUN HERE>" << endl;
    cin >> dollar;

    cout << "I meant CENTS as well <GUN HERE>" << endl;
    cin >> cents;

    cents = dollar * DOLLAR_VALUE + cents;
    quartNo = cents / QUARTER_VALUE;
    cents = cents % QUARTER_VALUE;      //Remaining Cents after changed to quarter (I Understand)
    dimeNo =  cents / DIME_VALUE;
    cents = cents % DIME_VALUE;     //Remainging Cents after changed to Dimes (Could be ...)
    nickNo = cents / NICKEL_VALUE;
    penn = cents % NICKEL_VALUE;        // ???

    cout << "You have " << quartNo << " Quarters " << dimeNo << " Dimes " << nickNo << " Nickels " << penn << " Pennies"; // IT WORKS

    return 0;
}