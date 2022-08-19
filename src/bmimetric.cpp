/*Body mass index (BMI) is a number calculated from  a person’s weight and height.
According to the Centers for Disease Control and Prevention, the BMI is a fairly
reliable indicator of body fatness for most people. BMI does not measure body fat
directly, but research has shown that  BMI correlates to direct  measures  of  body  fat,  
such  as  underwater  weighing  and dual-energy X-ray absorptiometry. The formula 
for BMI is
    Weight/Height^2

Where weight is in kilograms and height is in meters.*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double height, weight;
    cout << "Please enter weight in kilograms: ";
    cin >> weight;
    cout << "\nPlease enter height in meters: ";
    cin >> height; 

    float bmi;
    bmi = (float) weight/ pow(height, 2) ;

    cout.precision(4);      //Changes Precision of the values in cout below this to 4th digit
    cout << "BMI = " << bmi <<endl;
    return 0;
}