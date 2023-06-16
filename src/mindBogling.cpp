#include <iostream>
#include <string>
#include <ratio>


class strings{
public:
    std::string message;

public:
    strings(){}

    strings(std::string str)
        :message(str)
    {}

//OPERATOR OVERLOADING BABY
    strings operator-(strings& otherArray) const{
        if(message != otherArray.message)
        {
            strings temp(otherArray.message + " - " + message);
            return temp;
        }
        else 
        {
            return (std::string)"NULL";
        }
    }
    strings operator+(strings& otherArray) const{ 
        strings temp(message + " " + otherArray.message);
        return temp;
    }

    strings operator*(strings& otherArray) const{ 
        strings temp;
        int i=0;
        while(i != message.size() || i<otherArray.message.size())
        {
            if(!(i<message.size()))
            {
                while(i<otherArray.message.size())
                {
                    temp.message.push_back(otherArray.message.at(i));
                    i++;
                }
            }
            temp.message.push_back(message[i]);
            temp.message.push_back(otherArray.message[i]);
            i++;
        }
        return temp;
    }

    void operator=(std::string msg)
    {
        this->message = msg;
    }

};


std::ostream& operator<<(std::ostream& stream, const strings& otherObj)
{
    stream << otherObj.message;
    return stream;
}



int main(void)
{
    strings a, b, c;

    a = "Hello";
    b = "World!";

    std::cout << a * b << std::endl;

}