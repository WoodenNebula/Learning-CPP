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
#include <stdlib.h>

using namespace std;

/* 1 pound is  0.453592  kilograms and 1 inch is 0.0254  meters */
const double M_WEIGHT = 0.453592;   //conversion factor of Weight. # -> KG
const double M_HEIGHT = 0.0254;     //conversion factor of Height. " -> m

float bmiCalc(float , float);


int main(){
    char x;
    double height, weight;
    float bmi;

    cout << "Press 'm' for Metric System (KG, Meters) OR 'i' for Imperial System (Pound, Inch)" << endl;
    cin >> x;
    system("cls");

    cout << "Please enter WEIGHT: ";
    cin >> weight;
    cout << "\nPlease enter HEIGHT: ";
    cin >> height; 

    if(x == 'I' || x == 'i'){       //Conversion of Imperial to Metric System
        weight *= M_WEIGHT;
        height *= M_HEIGHT;
    }
        
    bmi = bmiCalc(weight , height); 

    cout.precision(4);      //Changes Precision of the values in cout below this to 4th digit
    cout << "BMI = " << bmi <<endl;
    return 0;
}

float bmiCalc(float weight, float height){
    float bmi = (float) weight/ pow(height, 2) ;
    return bmi;
}