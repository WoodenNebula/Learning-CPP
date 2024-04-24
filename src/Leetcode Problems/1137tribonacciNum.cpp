#include <iostream>

class Solution {
public:
    int tribonacci(int n) {
        int num = 1;
        int prev3 = 1;
        int prev2 = 1;
        int prev1 = 0;

        if(n < 2){ return n;}
        else {
            while(n > 2) {
                num = prev3 + prev2 + prev1;
                prev1 = prev2;
                prev2 = prev3;
                prev3 = num;
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
    std::cout << "Tribonacci of " << n << " = " << s.tribonacci(n);

    return 0;
}