#include <iostream>

bool targetChecker(int, int, int);

using namespace std;

int main (){
    int nums[] = {2,7,11,15};
    int target = 9;

    for(int i = 0; i< 4; i++){
        int elementOne = nums[i];
        for(int j = i+1; j < 4; j++){
            int elementTwo = nums[j];
            if(targetChecker(elementOne, elementTwo, target)){
                cout << i << " " << j << endl;
            }
        }
    }
    return 0;
}

bool targetChecker(int i, int j, int target){
    if(i + j == target){
        return true;
    }
    return false;
}