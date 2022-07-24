//some uses of cin >> 

#include <iostream>
using namespace std;

int main(){
    system("cls");
    int dummy;
    long unsigned int x;
    char r;
    x = 3000000000;
    cout << "The speed of light is " << x;
    cout << "\nPress a number to proceed ";
    cin >> dummy;
    cout << "You entered " << dummy;

/*      for character input     */

    cout << "\nState an alphabet :\n";
    cin >> r;
    cout << "Thou wished for " << r;
    return 0;
}