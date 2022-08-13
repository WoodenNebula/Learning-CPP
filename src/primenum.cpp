#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

int main(){
    system("cls");
    for(int i = 1; i <=1000000; i++){
        if(i == 2){     // Printing Out 2
            cout << i << " ";
        }
        if(i%2 != 0){ // Filtering out Even no. since they are all composite
        for (int j = 3; j <=i ; j+=2){
                if(i != j && i%j == 0){     //This Checks for Composite No.
                    break;
                }
/*If the above check for Composite No. fails each time till the last number then it is Prime no.*/
                else if(j== i){         
                    cout<< i << " ";
                }
            }
        }
    }
    system("pause");
    return 0;
}