#include <iostream>
#include <string>

class Solution {
public:
    bool isvalid(std::string s) {
        if (s.length() % 2 != 0) { return false; }
        std::string openingBrackets;
        for (char b : s) {
            switch (b)
            {
            case '(':
            case '{':
            case '[':
                openingBrackets.push_back(b);
                break;
            case ')':
                if (!openingBrackets.empty() && openingBrackets[openingBrackets.length() - 1] == '(') {
                    openingBrackets.pop_back();
                }
                else { return false; }
                break;
            case '}':
                if (!openingBrackets.empty() && openingBrackets[openingBrackets.length() - 1] == '{') {
                    openingBrackets.pop_back();
                }
                else { return false; }
                break;
            case ']':
                if (!openingBrackets.empty() && openingBrackets[openingBrackets.length() - 1] == '[') {
                    openingBrackets.pop_back();
                }
                else { return false; }
                break;
            default:
                break;
            }
        }
        return !(openingBrackets.length());
    }
};


int main() {
    Solution s;
    std::cout << (s.isvalid("]") == true ? "true" : "false") << std::endl;
}