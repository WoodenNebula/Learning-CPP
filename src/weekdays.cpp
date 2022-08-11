/*Program to calculate the number of weeks and days you travelled by taking total days as input*/

#include <iostream>
#include <stdlib.h>
using namespace std;

const int DAYS_IN_WEEK = 7;

int main(){
    int trvlDays; 
    system("cls");

    cout<< "Enter the number of Days you have travelled."<< endl;

    cin >> trvlDays;
    system("cls");

    cout <<"You have travelled " << trvlDays/DAYS_IN_WEEK <<" weeks and " << trvlDays%DAYS_IN_WEEK << " days." << endl;  

    return 0;
}