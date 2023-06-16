#include <iostream>
#include <string>

class Human{
protected:  //For accessing through child class
    std::string m_Name;
    uint32_t m_Age;
    bool m_isAlive;
    float m_Height;

public:
    Human()
    {
    }

    Human(std::string name, uint32_t age, bool isAlive, float height)   //Konstructor
        :m_Name(name), m_Age(age), m_isAlive(isAlive), m_Height(height)
    {
    }

    void GetName()
    {
        std::cout << "This name is " << m_Name << std::endl;
    }

    void GetAge()
    {
        std::cout << "The age is "  << m_Age << std::endl;
    }

    // void operator<<(std::stdout& os, )

// private:    //Yes private can be declared twice or more, 
    void SuperSecretFunc(std::string& usrPassword){       //PRIVATE FUNC
        try
        {
            const std::string PASSWORD = "ASA";
            if(usrPassword !=  PASSWORD)
                throw "bad Password";
            std::cout <<  "Chad" << std::endl;      //notice that i am returning const char[], NOT std::string
        }
        catch(...)
        {
            std::cout << "Bad Password:" << std::endl;
            std::cerr << "yo mama fat" << std::endl;
        }
    }
};


class Person : public Human
{
private:
    uint32_t m_Grade;
public:
    // Person() = delete;
    Person(const char *name, uint32_t age, uint32_t grade)     //Konstructor
    {
        m_Name = name;
        m_Age = age;
        m_Grade = grade;
        // std::cout << "Created an instance of \"Person\" object" << std::endl;
    }

    void GetGrade()
    {
        std::cout << "The grade is " << m_Grade << std::endl;
    }
};


int main (void)
{
    Person birmai("Subham Birami", 18, 12);
    // birmai.GetName();
    // birmai.GetAge();
    // birmai.GetGrade();
    // std::cout << birmai.getPassword();
    std::string password = "ASA";
    birmai.SuperSecretFunc(password);
    std::cout << "----------" << std::endl;
    password = "asa";
    birmai.SuperSecretFunc(password);   //Inaccessible 

}