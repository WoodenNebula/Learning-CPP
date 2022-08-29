//SECOND FILE OF LEARNING CLASSES

#include <iostream>
#include <string>

using namespace std;


class User{
private:
    bool m_isAlive;
    string m_name;
    int m_age, m_sal;
    
public:   
    User(){     //THIS IS A CONSTRUCTOR THAT WILL INITIALIZE DEFAULT VALUES WHEN THE CLASS IS INSTANTIATED
        m_isAlive = false;
        m_name = "[NAME]";
        m_age = 0;
        m_sal = 0;
        cout << "Created User" << endl;
    }
    
    ~User(){        //THIS IS A DESTRUCTOR THAT WILL DESTROY(uninitialize) THE INSTANCE OF THE CLASS
    
    }

    User(bool isAlive , const char* name, int age, int sal){ // THIS IS ALSO A CONSTRUCTOR :dead:
        m_isAlive = isAlive;
        m_name = name;
        m_age = age;
        m_sal = sal;
    }

    void showDetails (){
        if(m_isAlive){
            cout << "Hello my name is " << m_name << "." << endl;
            cout << "I am " << m_age << " years old." << endl;
            cout << "I earn " << m_sal << " amount per month" << endl;
        }else cout << "Dead Person" << endl;
    }
};


int main(){    

    User userOne(true, "Somin", 17, 2500);
    userOne.showDetails();
    cout<< "<===================================>" << endl;

    User userTwo;
    userTwo.showDetails();
    cout<< "<===================================>" << endl;

    User userThree(true, "Surab", 17, 1000);
    userThree.showDetails();
    cout<< "<===================================>" << endl;

    return 0;
}