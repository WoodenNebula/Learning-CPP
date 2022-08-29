#include <iostream>
#include <string>

using namespace std;
// CLASS IS BASICALLY AN OBJECT 
// IT IS ALSO SAME AS STRUCT DIFFERING ONLY IN VISIBILITY 
// i.e. CLASS IS PRIVATE BY DEFAULT 
// WHEREAS STRUCT IS PUBLIC BY DEFAULT

class User{
public:
    string name;
    int age, sal;
    bool isAlive;
    
    void sayHello(bool isAlive, string name){
        if(isAlive)
            cout << "Hello my name is " << name << endl;
        else cout << "Dead Person" << endl;
    }
            
    
    void showDetails (int age, int sal){
        cout << "I am " << age << " years old." << endl;
        cout << "I earn " << sal << " amount per month" << endl;
    }
};
int main(){
    User userOne, userTwo;
    
    userOne.sayHello(true, "Somin");
    userOne.showDetails(17, 2500);

    cout<< "<===================================>" << endl;

    userTwo.sayHello(false, "Surab");

    return 0;
}