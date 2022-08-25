//Problem 9 of Leetcode (Solved)

/*Given an integer x, return true if x is palindrome integer.
An integer is a palindrome when it reads the same backward as forward.
For example, 121 is a palindrome while 123 is not.*/

#include <iostream>
#include <string>
#include <bits/stdc++.h> //For reverse function


using namespace std;

int main(){
    int x;
    string userInput, revString;

    cout << "Enter an integer" << endl;
    cin >> x;

    userInput = to_string(x);
    revString = userInput;

    reverse(revString.begin(), revString.end());

    if(userInput == revString){
        cout << "Is Palindrome";
    }
    else{
        cout << "Not Palindrome";
    }

    return 0;
}