#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <stdlib.h>

class Daddy{
private:
    int daddyLevel = 0;
    std::string size = " tiny af";
    std::string lastsFor =  " less than half-life time of 12C";
    std::string stimulation = " you wont even feel it";
    std::string speciality= ": Sucks at everything";
public:
    int daddyTimes = 0;
private:
    void SizeofD(){
        std::cout << __func__ << size << std::endl;
    }
    void LastsFor(){
        std::cout << __func__ << lastsFor << std::endl;
    }
    void StimulatesLike(){
        std::cout << __func__ << stimulation << std::endl;
    }
    void Speciality(){
        std::cout << __func__ << speciality << std::endl;
    }
public:
    Daddy() = delete;
    Daddy(const std::string& instanceName, int randomNum)
        :daddyLevel(randomNum)
    {
        std::cout << __func__ << instanceName << " : " << std::endl;
        if(daddyLevel == 1)
        {
            size = " very big";
            lastsFor = " longer than a fully charged iphone";
            stimulation = " better than your vibrating diamond phone";
            speciality= ": Make you yell louder than 'class maa hasne birami'";
            daddyTimes++;
        }
        SizeofD();
        LastsFor();
        StimulatesLike();
        Speciality();
    }
};

int main(){
    srand(time(0));
    
    int ot = 0, subham = 0, somin = 0;

    int num; 

    for(int i = 0; i<100; i++)
    {


        num = rand() %2;
        Daddy OT("OT", num);
        ot += OT.daddyTimes;

        num = rand() %2;
        Daddy Somin("Somin", num);
        somin += Somin.daddyTimes;

        num = rand() %2;
        Daddy Subham("Subham", num);
        subham += Subham.daddyTimes;

        system("clear");
    }
    std::cout << "DaddyTime:\n OT = "<< ot
                << "\n Subham = " << subham
                << "\n Somin = " << somin 
                << std::endl;

    system("pause");

}
