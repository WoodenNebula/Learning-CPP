// ✔✔ Problem 01 of Leetcode

/* Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order. */

#include <iostream>
#include <vector>

#define ASSERT(x) if (!(x)) __debugbreak()

using vector = std::vector<int>;

class Solution {
public:
    Solution(vector num, int target)
    {
        vector indices = twoSum(num, target);
        indices[0] != indices[1]? std::cout << "Indices are : " << indices[0] << ", " << indices[1] << std::endl : std::cout << "No Solution exist!" << std::endl;
    }

    vector twoSum(vector& nums, int target) {
        ASSERT(nums.size() >= 2);

        for(int x = 0 ; x < nums.size() ; x++)
        {
            for(int y = x + 1; y < nums.size();  y++)
            {
                if(nums[x] + nums[y] == target)
                {
                    return {x ,y};
                } 
                    
            }            
        }
        return {0 ,0};
    }
};

int main()
{
    Solution s({2,5,5} , 10);

    return 0;
}