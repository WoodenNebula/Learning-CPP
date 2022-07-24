#include <iostream>

using namespace std;

int calc(int, int, int);

int main(){

    int num1, num2, num3;

    cout << "enter the numbers: ";
    cin >> num1 >> num2 >> num3;
 
    cout << calc(num1, num2, num3);

    return 0;
}

int calc(int a, int b, int c){

    return a+b+c;
}
