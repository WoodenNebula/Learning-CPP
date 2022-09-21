/* In How Many ways... */

#include <iostream>

class Binomial
{
private:
    unsigned int m_Choices, m_Selection, m_Combination, m_Permutation;
    const unsigned int m_Fact = 1;
    unsigned int nFact = m_Fact;

public:
    Binomial()
    :m_Combination(0), m_Permutation(0)
    {

    }

    Binomial(unsigned int usrChoices, unsigned int usrSelection)
    {   
        if (usrChoices < usrSelection)
        {
            throw std::runtime_error("Selection cannot be greater than Total Choices");    
        }
        else{
            m_Choices = usrChoices, m_Selection = usrSelection;
        }
        /* AVOIDING CASES OF 0 */
        if(usrSelection == 0)   
        { 
            m_Selection = 1;
        }
        if(usrChoices == 0)   
        { 
            m_Choices = 1;
        }
    }

    unsigned int factorial()    //Returns the Factorial of this.m_selection
    {
        nFact = m_Fact;
        for(int i = 1; i <=m_Choices ; i++)
        {
            nFact *= i;
        }
        return nFact;
    }

    unsigned int factorial(int m_Choices)   //Returns the Factorial of number from user
    {
        nFact = m_Fact;
        for(int i = 1; i <=m_Choices ; i++)
        {
            nFact *= i;
        }
        return nFact;
    }

    unsigned int combination()  //Returns the possible number of Combinations
    {
        m_Combination = factorial()/(factorial(m_Choices-m_Selection) * factorial(m_Selection));
        return m_Combination;
    }

    unsigned int permutation()  //Returns the possible number of Permutations
    {
        m_Permutation = factorial(m_Choices)/(factorial(m_Choices-m_Selection));
        return m_Permutation;
    }
};


int main()
{
    Binomial b1(9,3);
    std::cout << "Factorial is "<< b1.factorial() << '\n';
    std::cout << "Combination is " << b1.combination() << '\n';
    std::cout << "Permutation is " << b1.permutation() << '\n' << '\n';
    
    Binomial b2(0, 0);
    std::cout << "Factorial is "<< b2.factorial() << '\n';
    std::cout << "Combination is " << b2.combination() << '\n';
    std::cout << "Permutation is " << b2.permutation() << '\n' << '\n';

    Binomial b3(1, 2);      //Exception is thrown an program terminates
    std::cout << "Factorial is "<< b2.factorial() << '\n';          //Not Executed
    std::cout << "Combination is " << b2.combination() << '\n';     //Not Executed
    std::cout << "Permutation is " << b2.permutation() << '\n' << '\n';     //Not Executed

    std::cout << "This wont be executed" << '\n';                   //Not Executed
}