/*This program takes in a string and outputs the longest length of strings that
occur without repetition. 
*/


#include <iostream>
#include <string>
#include <vector>

using namespace std;

int gapCompare(vector<int>);

int lengthOfLongestSubstring(string s){
    int LenOfSubstr, tempIndex;
    
    vector <int> gaps;
    char char1, charItr;

    for(int i = 0; i <= s.length(); i++){
        tempIndex = i;       
        char1 = s[tempIndex];
        for(int j = i + 1; j <= s.length(); j++){
            charItr = s[j];
            if(char1 == charItr){       //For same alphabets
                LenOfSubstr = j - tempIndex;    //Determining the length of repitition
                gaps.push_back(LenOfSubstr);   /* Storing the lenghts at which the alphabets repeat */
                tempIndex = j;       /*Storing the index of the alphabet that is currently being compared*/
            }
        }
    }
    LenOfSubstr = gapCompare(gaps);
    return LenOfSubstr;
}

int gapCompare(vector<int> gaps){
    int lrgstLenOfSubstr = gaps.at(0);

    for(int i = 0; i < gaps.size(); i++){
        if(lrgstLenOfSubstr<gaps.at(i)){
            lrgstLenOfSubstr=gaps.at(i);
        }
    }
    return lrgstLenOfSubstr;
}

int main(){

    string s;
    system("cls");

    cout << "Enter a string:" << endl;
    cin >> s;

    int length = lengthOfLongestSubstring(s);
    cout << "Longest unrepeated Substring is " << length;

    return 0;
}