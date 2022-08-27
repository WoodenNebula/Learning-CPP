//Problem 14 of Leetcode (Semi-Solved)

/* a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "". */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main (){
    vector<string> strs;
    strs = {"flower","flow","flown"};
    int i = 0;
    if(strs.at(0).at(0) == strs.at(1).at(0) && strs.at(1).at(0) == strs.at(2).at(0)){
        do{
            cout << strs.at(0).at(i);
            if(i >= strs.size()){
                break;}
            i++;
        }while(strs.at(0).at(i) == strs.at(1).at(i) && strs.at(1).at(i) == strs.at(2).at(i));
    }else cout << "";
    return 0;
}