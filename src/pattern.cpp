/* Simple Program to display two different increasing or decreasing pattern */

#include <iostream>

void patternTypeOne(int&, int&, char&);
void patternTypeTwo(int&, int&, char&);

int main()
{
    int targetRows;
    char usrPatternChar = '*';
    std::cout << "Enter the number of Rows: \n";
    std::cin >> targetRows;

    std::cout << "Enter a character of whose pattern is to be generated:\n";
    std::cin >> usrPatternChar;
    
    

    int buffer = 1;
    if(targetRows%2 == 0)
    {
        buffer = 0;
    }
    
    int patternType = 0;
    std::cout << "Choose a type of Pattern: 1, 2 or any number for both \n";
    std::cin >> patternType;

    switch (patternType)
    {
    case 1:
        patternTypeOne(targetRows, buffer, usrPatternChar);
        break;
    
    case 2: 
        patternTypeTwo(targetRows, buffer, usrPatternChar);
        break;
    default:
        std::cout << "Displaying both Types: \n \n";
        patternTypeOne(targetRows, buffer, usrPatternChar);
        patternTypeTwo(targetRows, buffer, usrPatternChar);
        std::cin.get();
        break;
    }
    return 0;
}

void patternTypeOne(int& targetRows, int& buffer, char& usrPatternChar)
{
    int i = 1;
    std::cout << "patternTypeOne\n";
    
    //Increment till Half the number of Rows
    while (i <= targetRows/2 + buffer)
    {
        for (int j = 1; j <= i; j++)
        {
            std::cout << usrPatternChar;
        }
        std::cout << '\n';
        i++;
    }

    //Decrement from Half the number of Rows
    while(i<= targetRows)
    {
        for (int j = 0; j <= targetRows - i; j++)
        {
            std::cout << usrPatternChar;
        }
        std::cout << '\n';
        i++;
    }
}

void patternTypeTwo(int& targetRows, int& buffer, char& usrPatternChar)
{
    int i = 1;
    std::cout << "patternTypeTwo\n";

    //Decrement Half
    while(i<= targetRows/2 + buffer)
    {
        for (int j = targetRows/2 + buffer; j >= i; j--)
        {
            std::cout << usrPatternChar;
        }
        std::cout << '\n';
        i++;
    }

    //Increment for the rest half of rows
    while(i <= targetRows)
    {
        for (int j = !buffer; j <=i - (targetRows/2 + buffer); j++)
        {
            std::cout << usrPatternChar;
        }
        std::cout << '\n';
        i++;
    }
}