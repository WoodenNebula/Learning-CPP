//Spin word if word length is greater than 4
// Keep other words as it is

#include <iostream>
#include <string>

using namespace std;

const int condition = 4;

bool spinCondition(int startInd, int endIndex){
    if(condition < (endIndex - 1 - startInd) ){
        return true;
    }
    return false;
}

void wordSpinner(const string& spinWord, int i, int j){
    for(j-- ; j >= i; j--){
        cout << spinWord[j];
    } cout << " ";
    
}

void spinFunc(const string& target){
    char itrChar;
    for(int i = 0; i<target.length(); i++){
        for(int j = i+1; j<target.length(); j++){
            itrChar = target[j];
            if(itrChar == ' '){
                if(spinCondition(i, j)){
                    // if(j == target.length() - 1)
                    wordSpinner(target, i, j);
                }else{
                    for( ; i<j ; i++){
                        cout << target[i];
                    }
                    cout << " ";
                }
                i = j + 1;
            }
        }
    }
    
}

int main()
{   
    string usrInput;
    cout << "Enter your sentence to be spinned" << endl;

    getline(cin, usrInput);     // Taking input with whitespaces
    usrInput += " ";
    spinFunc(usrInput);
    return 0;
}