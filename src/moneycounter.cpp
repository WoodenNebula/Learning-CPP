//Get your Quarters, Dimes, Nickels or Pennies(If you have any) and I will convert them into Dollars
//"25second me paisa double"

//Refer to coins.cpp for inversion of your money

#include<iostream>

using namespace std;

const int QUARTER_VALUE = 25, NICKEL_VALUE = 5, DIME_VALUE = 10;


int main(){
    int penn, nickNo, dimeNo, quartNo, dollar, cents;    //Types of money
/*A penny is worth 1 cent
A nickel is worth 5 cents
A dime is worth 10 cents
A quarter is worth 25 cents 
A Dollar is worth 100 cents*/
    cout << "No of Coins of Quarters:" <<endl;
    cin >> quartNo;

    cout << "No of Coins of Dimes:" <<endl;
    cin >> dimeNo;

    cout << "No of Coins of Nickels:" <<endl;
    cin>> nickNo;

    cout << "No of Coins of Pennies:" <<endl;
    cin>> penn;

    cents = (QUARTER_VALUE * quartNo) + (NICKEL_VALUE * nickNo) + (DIME_VALUE * dimeNo) + penn;

    dollar = cents / 100;
    cents = cents % 100;
    
    cout << "You got " << dollar << " $ and " << cents << " cents" << endl;
    
    return 0;
}