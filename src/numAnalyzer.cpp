/* A simple program to find the number 
of digits in the given num as well as
 its individual digits' sum */

#include <iostream>

int numDigits = 0;
int FindSum(int n)
{
    if(n < 10)
    {
        numDigits++;
        return n;
    }
    else
    {
        numDigits++;
        return (n%10 + FindSum(n/10));
    }
}
void numAnalyzer(int& n)
{
    if(n < 0)
        n *= -1;
    std::cout << "Sum is " << FindSum(n) << " and No. of Digits is " << numDigits;
}

int main()
{
    int x;
    std::cout << "Enter a number: \n";
    std::cin >> x;
    numAnalyzer(x);
    std::cin.get();
}