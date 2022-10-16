// Leetcode Problem 6 (Solved- Doesnot work on Leetcode's run but runs in onlinegdb and repl)

/* The string "PAYPALISHIRING" is written in a convert pattern on a given number of rows like this:
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

*/

#include <iostream>
#include <string>

class ZigzagString{
private:
    bool m_direction = false;/*Direction for iteration Down is true and Up is false*/
    int m_numColumn, m_numRows;
    int* m_strArray;
private:
    void rowItrDirection(int& itrRow, int& itrColumn, int m_numRows)
    {
        if(itrRow == (m_numRows-1) || itrRow == 0){
            m_direction = !m_direction;
        }

        if(m_direction)
        {
            itrRow++;
        }
        else
        {
            itrColumn++;
            itrRow--;
        }
    }
public:
    std::string convert(std::string s, int m_numRows)
    {
        m_numColumn = (int)(s.length() / 2);
        char strArr[m_numRows][m_numColumn];
        int num[2];

        //Giving Dummy Values to all the members 
        for(int i = 0; i < m_numRows; i++)
        {
            for (int j = 0; j < m_numColumn; j++)
            {
                strArr[i][j] = '\\';
            }
        }

        std::string convertedStr = s;//Actual String to be returned, assigning the same value for easier access later

        int itrRow = 0, itrColumn = 0, strIndex = 0;    //Initialization of iterating variables

        /* ZIGZAG pattern */
        for(itrRow; strIndex < s.length(); rowItrDirection(itrRow, itrColumn, m_numRows))
        {
            strArr[itrRow][itrColumn] = s[strIndex];
            strIndex++;
        }

        //Displaying the matrix/array in console 
        //Comment out if not necessary to std::cout
        for(int i = 0; i < m_numRows; i++)
        {
            for (int j = 0; j < m_numColumn; j++)
            {
                std::cout << strArr[i][j] << '\t';
            }
            std::cout << '\n';
        }
        std::cout << '\n';

        /* assigning the characters to a string variable */
        int k = 0;//Index For convertedStr
        for(int i = 0; i < m_numRows; i++)
        {
            for (int j = 0; j < m_numColumn; j++)
            {
                if(strArr[i][j] != '\\')
                {
                    convertedStr[k] = strArr[i][j];
                    k++;
                }
            }
        }
        return convertedStr;
    }
};

int main()
{
    ZigzagString s, s1, s2;
    s.convert("PAYPALISHIRING", 4);
    // s.convert("PLEASEDONOTDOTHIS", 3);  //This does not work, make a different instance for this. 
    s1.convert("PAYPAL", 2);
    s2.convert("PAYPALISHIRINGSHIT", 3);
}