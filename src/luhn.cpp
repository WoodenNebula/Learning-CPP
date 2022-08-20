#include <iostream>
#include <cmath>

using namespace std;

unsigned long long digitDoubler(unsigned long long);
int lengthOfCard(unsigned long long);
int sumChecker(unsigned long long); 

int main(){
    unsigned long long creditCardNum, workingCardNum; //Card number

    system("cls");

    cout << "Credit Card Number:" << endl;
    cin >> creditCardNum;

    workingCardNum = creditCardNum;
    cout << lengthOfCard(workingCardNum) + 1 << " is the number of Digits" << endl;

    system("pause");
    system("cls");

    workingCardNum = digitDoubler(workingCardNum);

    cout << creditCardNum << "    -> Original Card" << endl;
    cout << workingCardNum << "    -> Doubled Card" << endl;

    // system("pause");
    // system("cls");

    // cout << workingCardNum << "    -> Doubled Card" << endl;
    // cout << "The Sum is " << sumChecker(workingCardNum) << endl;
    // if(sumChecker(workingCardNum))
    //     cout << "The Card Is VALID" << endl; 
    // else 
    //     cout << " INVALID" << endl;
    return 0;
}

int lengthOfCard(unsigned long long workingCardNum){    //No. of Digits in Card
    int size = (int)log10(workingCardNum);
    return size;
}

unsigned long long digitDoubler(unsigned long long workingCardNum){
    unsigned long long curRemainders;   //Current Digits
    int size = lengthOfCard(workingCardNum), curDigit;

    if(size % 2 == 0){      //For Odd Cards
        size --; 
    }

    unsigned long long i = pow(10, size);

    // cout << i << " Divider" << endl;

    for(i ; i >= 10 ; i /= 100){
            
        curRemainders = workingCardNum / i;     //could be one or more digited 

        if(curRemainders > 10){        //getting the exact single working digit
            curRemainders = curRemainders % 10LL;
        }

        curDigit == curRemainders;

        cout << curDigit << " is current DIGIT" << endl;

        switch(curDigit){   //FOR  2 digited Douubled number case
            case 5:
                workingCardNum -= 4*i;
                break;
            case 6:
                workingCardNum -= 3*i;
                break;
            case 7:
                workingCardNum -= 2*i;
                break;
            case 8:
                workingCardNum -= 1*i;
                break;
            case 9:
                break;
            default:
                // cout << "Defauld Case Invoked \n" << endl;
                workingCardNum += (long long)curDigit * i;
                break;
        }
    // cout << workingCardNum << " => func" << endl; 
    }
    return workingCardNum;
}

int sumChecker(unsigned long long workingCardNum){

    int sum = 0, size = lengthOfCard(workingCardNum), curDigit;

    unsigned long long divFactor = pow(10, size);

    for(divFactor ; divFactor >= 1 ; divFactor /= 10){
        curDigit = (int)workingCardNum / divFactor;
        if(curDigit > 10){
            curDigit = (int)curDigit % 10;
        }
        sum += curDigit;
        cout << curDigit << " Current Sum" << endl; 
    }
    // if(sum % 10 == 0){
    //     return true;
    // }
    // return false;
    return sum;
}
