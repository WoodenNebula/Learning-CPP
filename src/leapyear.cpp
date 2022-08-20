/*Find out if a certain year is leap year or not*/
/*The logic for this is https://en.wikipedia.org/wiki/File:Leap_Year_Algorithm.png */
#include <iostream>

using namespace std;

int main(){
    int year;

    cout << "Enter the year" << endl;
    cin >> year;
    if(year%4 == 0){
        if(year % 100 == 0 && year % 400 == 0)
            cout << year << " is Leap Year";
        else if(year % 100 != 0)
            cout << year << " is Leap Year";
        else
            cout << year << " is NOT Leap Year";
    }else
        cout << year << " is NOT Leap Year";
    return 0;
}