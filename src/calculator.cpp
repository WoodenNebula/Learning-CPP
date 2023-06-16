#include <iostream>
#include <fstream>

int main(void)
{
    std::fstream testFile;
    testFile.open("temp.txt");
    testFile << "Hello World!";
    testFile.close();

    
}