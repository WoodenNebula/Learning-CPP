//Leetcode Problem 29

/*
Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.
*/

#include <iostream>

using namespace std;

class Divider{
// private:
public:
    int  dividend, divisor, divCount = 0;
    
public:
    // Divider(){
    //      dividend = 4;
    //      divisor = 2;
    // }
    
    Divider(int& dividend, int& divisor)
        : dividend(dividend),  divisor(divisor)
        {
    }
    
    int divide(){
        int sign = 1;

        if (dividend < 0){
                dividend = abs( dividend);
                sign *= -1;
            }
            
        if (divisor < 0){
                divisor = abs( divisor);
                sign *= -1;
            }

        while(dividend > 0){
                dividend -=  divisor;
                if(!( dividend < 0))
                     divCount++;
            }

        divCount *= sign;

        if( divCount > (2^31 -1))
            return 2^31 -1;
        else if( divCount < -(2^31))
            return -2^31;
        else
            return divCount;
    }
    
};

int main()
{
    int x, y;
    cout << "Enter 2 numbers:" << endl;
    cin >> x >> y;
    Divider d1(x, y);
    int quotient = d1.divide();
    cout << quotient;
    return 0;
}