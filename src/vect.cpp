#include <iostream>
#include <vector>

using namespace std;

class revVector{
public:
    void plusOne(vector<int>& digits){
        vector<int> rev;
        for(int itr = digits.size(); itr != 0; --itr){
            rev.push_back(itr);
        }
        
        for(auto& itr : rev)
            cout << itr;
        
    }

};

int main(){

    vector<int> digits;
    
    digits.push_back(1);
    digits.push_back(2);
    digits.push_back(3);
    digits.push_back(4);

    for(auto& itr : digits)
        cout << itr;

    cout << "\n" << "<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>" << endl;
    
    revVector s;
    s.plusOne(digits);
    
    
}