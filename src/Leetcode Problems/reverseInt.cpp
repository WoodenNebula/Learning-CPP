//PROBLEM 7 OF LEETCODE (SOLVED)


/* Given a signed 32-bit integer x,
 return x with its digits reversed.
 If reversing x causes the value to go outside
 the signed 32-bit integer range [-231, 231 - 1]
 , then return 0. 
 
 Example:
    Input: x = 120
    Output: 21 */

#include <iostream>

int NumDigits(int _x)
{
    int num = 0;
    while(_x >= 1)
    {
        _x /= 10;
        num++;
    }
    return num;
}

//Custom absolute value converter
bool IsNegative(long long int& _x)
{
    if(_x < 0)
    {
        _x *= (-1);
        return true;
    }
    else
        return false;
}

int reverse(int& usrInput)
{
    long long int workInput = usrInput;
    bool isNegative = IsNegative(workInput); 
    int digits = NumDigits(workInput);
    long long int reversedNum = 0;
    int divider = 10;
    int i = 1;
    int lastDigit;

    while (i < digits)
    {
        lastDigit = (int)workInput % divider;
        reversedNum += lastDigit;
        workInput /= divider;
        i++;
        reversedNum *= divider;
    }
    reversedNum += workInput;

    if (isNegative)
    {
        reversedNum *= -1;
        if(reversedNum <= -2147483648)
            return 0;
        else 
            return (int)reversedNum;
    }
    else
    {
        if(reversedNum >= 2147483647)
            return 0;
        else
            return (int)reversedNum;
    }        
}

int main(void)
{
    int x;
    std::cout << "Enter a no. to be reversed: \n";
    std::cin >> x;

    system("cls");

    int reversed_X = reverse(x);
    std::cout << "Original Number: " << x << std::endl;
    std::cout << "Reversed Number: " << reversed_X << std::endl;

    return 0;
}