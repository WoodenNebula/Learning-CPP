#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>


struct Snake;
struct Ladder;
struct Board;

int CalcMaxPathLen(int maxMoves, const std::vector<int>& diceRolls);
void CalculateShortestDistance(int maxPath, const Board& board);

Board InputObjectData(const std::string& filePath);
void OutputBoardData(const Board& board);


int main()
{
    Board board = InputObjectData("D:\\Programming\\C++\\src\\board.txt");
    
    auto& [numMoves, diceRolls, snakes, ladders] = board;

    int maxPathLength = CalcMaxPathLen(numMoves, diceRolls);
    
    std::cout << "Maximum possible path length = " << maxPathLength << std::endl;
        
    OutputBoardData(board);

    // CalculateShortestDistance(maxPathLength, numLadder ,ladders, numSnake, snakes);

}


struct Snake
{
    Snake(int Index, int Head, int Tail) :index(Index), head(Head), tail(Tail) {}
    uint32_t index;

    int head;
    int tail;
};


struct Ladder
{
    Ladder(int Index, int Top, int Bottom) :index(Index), top(Top), bottom(Bottom) {}

    uint32_t index;

    int top;
    int bottom;
};


struct Board
{
    int numMoves;
    std::vector<int> diceRolls{ -1, -1, -1, -1, -1, -1};
    std::vector<Snake> snakes;
    std::vector<Ladder> ladders;

    Board()
        :numMoves(-1), diceRolls{-1, -1, -1, -1, -1, -1}
    {

    }
};


void CalculateShortestDistance(int maxPath, const Board& board)
{
    
}


int CalcMaxPathLen(int maxMoves, const std::vector<int>& diceRolls)
{
    int diceValue = 6;
    int moveCount = 0;
    int maxPathLen = 0;

    do
    {
        if((moveCount + diceRolls[diceValue - 1]) > maxMoves) 
        {
            maxPathLen += (maxMoves - moveCount) * diceValue;

            break;
        }
        else
        {
            moveCount += diceRolls[diceValue - 1];
            maxPathLen += diceValue * diceRolls[diceValue - 1];
            diceValue--;
        }

    } while (diceValue >= 1 || moveCount == maxMoves);

    return maxPathLen;
}


Board InputObjectData(const std::string& filePath)
{
    std::fstream boardData(filePath.c_str());


    if(!boardData.is_open())
    {
        std::cout << "File didn't open!" << std::endl;
        abort();
    }
    else
    {
        enum BoardInfo
        {
            Moves = 0, DiceRolls, Snakes, Ladders
        };

        Board board;

        std::string line;

        BoardInfo infoType;

        int i = 0;

        while(std::getline(boardData, line))
        {
            if (line == "#Moves")
                infoType = BoardInfo::Moves;
            else if(line == "#DiceRolls")
                infoType = BoardInfo::DiceRolls;
            else if(line == "#Snakes")
            {
                infoType = BoardInfo::Snakes;
                i = 0;
            }
            else if(line == "#Ladders")
            {
                infoType = BoardInfo::Ladders;
                i = 0;
            }
            else
            {
                std::stringstream ss;
                ss << line;

                switch (infoType)
                {
                    case BoardInfo::Moves:
                    {
                        ss >> board.numMoves;
                        break;
                    }

                    case BoardInfo::DiceRolls:
                    {
                        for(auto& x : board.diceRolls)
                            ss >> x;

                        break;
                    }

                    case BoardInfo::Snakes:
                    {
                        int head, tail;

                        ss >> head >> tail;

                        board.snakes.emplace_back(i, head, tail);
                        i++;

                        break;
                    }

                    case BoardInfo::Ladders:
                    {
                        int top, bottom;

                        ss >> top >> bottom;

                        board.ladders.emplace_back(i, top, bottom);
                        i++;

                        break;
                    }
                    
                    default:
                        std::cout << "ERROR!!!" << std::endl;
                        break;
                }
            }

        }

        return board;
    }    
}


void OutputBoardData(const Board& board)
{
    auto& [numMove, diceRolls, snakeArr, ladderArr] = board;

    std::cout << "Number of snakes: " << snakeArr.size() << std::endl;

    std::cout << "Number of ladders: " << ladderArr.size() << std::endl;

    std::cout << "Number of moves: " << numMove << std::endl;

    std::cout << "Number of die rolls [1, 2, 3, 4, 5, 6]: " << std::endl;
    for(int i = 0; i<6; i++)
    {
        std::cout << diceRolls[i] << '\t';
    }

    std::cout << "\nEach Snake's head and tail: " << std::endl;
    for(int i = 0; i < snakeArr.size(); i++)
    {
        std::cout << "[" << snakeArr[i].index << "] Head = " << snakeArr[i].head << " Tail = " << snakeArr[i].tail << std::endl;
    }

    std::cout << "-------------------" << std::endl;


    std::cout << "Each Ladder's bottom and top: " << std::endl;
    for(int i = 0; i < ladderArr.size(); i++)
    {
        std::cout << "[" << ladderArr[i].index << "] Top = " << ladderArr[i].top << " Bottom = " << ladderArr[i].bottom << std::endl;
    }
}