/* Exploring CMath library*/
#include<iostream>
#include<cmath>

#define M_PI 3.14;

using namespace std;

int main(){
    int x = (double)M_PI; 
    system("cls");

    cout << x << endl << (float)x << endl << (int)x << endl; 
    /*Casting doesnot work since x is defined to have integer value */

    double y = M_PI;

    cout <<endl << y << endl << (float)y << endl << (int)y << endl; 
    /* Casting works since x is defined to have double value that can be converted into other datatype equivalent */
    
    return 0;
}
