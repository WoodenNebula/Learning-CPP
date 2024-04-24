#include <iostream>

class Solution {
public:
    int fib(int n) {
        int num = 1;
        int prev2 = 1;
        int prev1 = 1;

        if(n < 2){ return n;}
        else {
            while(n > 2) {
                num = prev2 + prev1;
                prev1 = prev2;
                prev2 = num;
                n--;
            }
        }
        return num;
    }
};


int main(int argc, char* argv[]) {
    int n = 0;

    if(argc > 1) {
        n = (int)(argv[1][0] - '0');
    } else n = 4;

    Solution s;
    std::cout << "Fibonacci of " << n << " = " << s.fib(n);

    return 0;
}