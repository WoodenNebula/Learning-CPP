#include <iostream>
#include <vector>

using namespace std;

vector <int> integerToArray(long long x){
    vector <int> resultArray;
    while (true){
        resultArray.insert(resultArray.begin(), x%10);
        x /= 10;
        if(x == 0)
            return resultArray;
    }
}

int main(){
    long long userCard;

    cout << "Card -> ";
    cin >> userCard;

    vector <int> actualCard = integerToArray(userCard);
    
    for(int i = 0; i < actualCard.size() ; i+= 2){
        actualCard[i] *= 2;
        if(actualCard[i] > 9){
            actualCard[i] = actualCard[i]%10 + actualCard[i]/10;
        }
    }

    int sum = 0;
    for(int i : actualCard){
        sum += i;
    }
    if(sum % 10 == 0){
        cout <<"\nVALID CARD";
    }else
        cout<< "\nINVALID CARD";
    return 0;
    
}



