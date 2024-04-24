#include <iostream>

class Solution {
public:
    int climbStairs(int n) {
        int ways = 1, secondLastWays = 1, lastWays = 2;

        if(n<3) {return n; }

        while(n > 2) {
            ways = lastWays + secondLastWays;
            secondLastWays = lastWays;
            lastWays = ways;
            n--;
        }

        return ways;
    }
};


int main(int argc, char* argv[]) {
    int n = 0;

    if(argc > 1) {
        n = atoi(argv[1]);
    } else n = 4;

    Solution s;
    std::cout << "Can climb "<< n << " stairs in " << s.climbStairs(n) << " ways";

    return 0;
}