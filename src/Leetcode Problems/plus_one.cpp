//✔✔ Problem 66 of Leetcode

/*A large integer is given represented as an integer array digits, 
where each digits[i] is the ith digit of the integer.
 The digits are ordered from most significant to least significant in left-to-right order.
 The large integer does not contain any leading 0's.
Increment the large integer by one and return the resulting array of digits.*/

#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> _digits;

public:
    Solution(const std::vector<int>& digits)
        :_digits(digits)
    {
        _digits = PlusOne(_digits);
        std::cout << "Digits after +1";
        PrintDigits();
    }


    std::vector<int> PlusOne(std::vector<int> digits) 
    {
        //pointer to the last element
        std::vector<int>::iterator itr = (digits.end() - 1);
        
        (*itr)++;

        while(*itr > 9)
        {
            //sets current digit to 0 (10) carry 1
            (*itr) = 0;
            //check if the carry is on first element
            if(itr == digits.begin())
            {   
                //add 1 to the first element
                digits.insert(digits.begin(), 1);
                continue;
            }
            //set the pointer to 1 digit left
            itr = itr - 1;
            //increase the value
            (*itr)++;
        }

        return digits;
    }

    void PrintDigits() const
    {
        std::cout << '\n';
        for(const auto& x: _digits)
        {
            std::cout << x;
        }
        std::cout << "\n";
    }
};

int main()
{
    Solution s({9});
    Solution s1({9,8,9});
    Solution s2({9,9,9,9,9,9,9,9,9,9});

    return 0;
}