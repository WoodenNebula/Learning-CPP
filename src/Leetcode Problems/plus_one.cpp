//Problem 66 of Leetcode


/*A large integer is given represented as an integer array digits, 
where each digits[i] is the ith digit of the integer.
 The digits are ordered from most significant to least significant in left-to-right order.
 The large integer does not contain any leading 0's.
Increment the large integer by one and return the resulting array of digits.*/

#include <iostream>
#include <array>

using namespace std;



int main(){
    
    array<int, 5> digits;
    
    for(int i = 0; i < size(digits) ; i++)
        cin >> digits[i];

    for(int i = 0; i < size(digits) ; i++)
        cout << digits[i];

    cout << "\n";

    
    digits[5-1]++;

    if(digits[5 - 1] > 9){
        for(int i = 5 - 1; i >=  0 ; i--){
            if(digits[i] > 9){
                digits[i] = 0;
                digits[i - 1]++;
                if(i == 0){
                    digits[i] = 10;
                }   
            }
        }
    }

    for(int i = 0; i < size(digits) ; i++)
        cout << digits[i];
}