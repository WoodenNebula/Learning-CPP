#include <iostream>

using namespace std;

int main(){
    float userTime, convTime;

    cout << "24hr Time : " << endl;
    cin >> userTime;

    convTime = userTime;

    if((int)userTime == 0){
        convTime += 12;
        cout << convTime << "am" << endl;
    }
    else if((int)userTime > 12 && (int)userTime <= 24){
        convTime -= 12;
        cout << convTime << "pm" << endl;
    }else if (userTime > 24 || userTime <  0){
        cout << "Invalid Time"<< endl;
    }else{
        cout << convTime << "am" << endl;
    }
    return 0;
}