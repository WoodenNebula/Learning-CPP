#include <iostream>
#include <string>

using namespace std;

int main(){
    string strOne, strTwo;
    cin >> strOne;
    cout << "Breaking Line to avoid two strings being taken at once." << endl;
    cin >> strTwo;

    /* String Concatenations*/
    cout << strOne + " " + strTwo << endl;      //Slower than .append
    cout << strOne.append(" ").append(strTwo);  // Faster than '+'
    //cout << strcat(strOne, strTwo);  This stupid finction is not avaialble Thank God

    /* This gives the character at index 2 of stiringOne although its a string and not character array*/ 
    cout << "\n" << strOne[2] << endl;

    /* Feels Like Js at this point */
    cout << strOne.length() << endl;
    return 0; 
}