#include <iostream>
using namespace std;

int main(){
    int trvlDays; 
    cout<< "Enter the number of Days you have travelled."<< endl;
    cin >> trvlDays;
    cout <<"You have travelled " << trvlDays/7 <<" weeks and " << trvlDays%7 << " days." << endl;  

    return 0;
}