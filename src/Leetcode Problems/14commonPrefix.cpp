//Problem 14 of Leetcode (Semi-Solved)

/* a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "". */
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        std::string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            int j = 0;
            while (prefix[j] == strs[i][j] &&
                j < prefix.size() &&
                j < strs[i].size()) {
                j++;
            }
            if (j == 0) {
                prefix = "";
                return prefix;
            }
            else { prefix = strs[i].substr(0, j); }
        }
        return prefix;
    }
};


int main() {
    std::vector<std::string> strs;
    strs = { "flower","flow","fliown", "home" };

    Solution s1;
    std::cout << "Common Prefix is " << s1.longestCommonPrefix(strs) << std::endl;

    return 0;
}