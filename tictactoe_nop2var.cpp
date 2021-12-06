#include <iostream>
#include <vector>
std::vector<std::vector<int>> board =
{
    {0, 0, 0}, 
    {0, 0, 0}, 
    {0, 0, 0}
};
void boardDefault() //the default setting of the board, used at start/restart
{
        board = 
    {
        {17, 18, 19}, 
        {14, 15, 16}, 
        {11, 12, 13}
    };
}
int playerChoice(int pchoice, int player) //input is number on board selected by player, and player 1 or 2
{
    if(pchoice == 1 && board[2][0] != 1 && board[2][0] != 2)
    {
        board[2][0] = player;
        return 0;
    }
    else if(pchoice == 2 && board[2][1] != 1 && board[2][1] != 2)
    {
        board[2][1] = player;
        return 0;
    }
    else if(pchoice == 3 && board[2][2] != 1 && board[2][2] != 2)
    {
        board[2][2] = player;
        return 0;
    }
    else if(pchoice == 4 && board[1][0] != 1 && board[1][0] != 2)
    {
        board[1][0] = player;
        return 0;
    }
    else if(pchoice == 5 && board[1][1] != 1 && board[1][1] != 2)
    {
        board[1][1] = player;
        return 0;
    }
    else if(pchoice == 6 && board[1][2] != 1 && board[1][2] != 2)
    {
        board[1][2] = player;
        return 0;
    }
    else if(pchoice == 7 && board[0][0] != 1 && board[0][0] != 2)
    {
        board[0][0] = player;
        return 0;
    }    
    else if(pchoice == 8 && board[0][1] != 1 && board[0][1] != 2)
    {
        board[0][1] = player;
        return 0;
    }
    else if(pchoice == 9 && board[0][2] != 1 && board[0][2] != 2)
    {
        board[0][2] = player;
        return 0;
    }
    return 1;
}

void xo_or_none(int boardInput = 0) //takes input from boardRead function to print correct player selected or default value
{
    if(boardInput == 1)
        std::cout << "  X  ";
    else if(boardInput == 2)
        std::cout << "  O  ";
    else if(boardInput == 11)
        std::cout << "  1  ";
    else if(boardInput == 12)
        std::cout << "  2  ";
    else if(boardInput == 13)
        std::cout << "  3  ";
    else if(boardInput == 14)
        std::cout << "  4  ";
    else if(boardInput == 15)
        std::cout << "  5  ";
    else if(boardInput == 16)
        std::cout << "  6  ";
    else if(boardInput == 17)
        std::cout << "  7  ";
    else if(boardInput == 18)
        std::cout << "  8  ";
    else if(boardInput == 19)
        std::cout << "  9  ";
    else
        std::cout << "     ";
}

void boardRead() //reads values from board 2d matrix and prints them out using xo_or_none function
{
    for(int i = 0; i < board.size() - 1; i++)
    {
        std::cout << "     " << "|" << "     " << "|" << "     " << std::endl;
        for(int j = 0; j < board[0].size() - 1; j++)
        {
            xo_or_none(board[i][j]);
            std::cout << "|";
        }
        xo_or_none(board[i].back());
        std::cout << std::endl;
        std::cout << "_____" << "|" << "_____" << "|" << "_____" << std::endl;
    }
    std::cout << "     " << "|" << "     " << "|" << "     " << std::endl;
    for(int i = 0; i < board[0].size() - 1; i++)
    {
        xo_or_none(board[2][i]);
        std::cout << "|";
    }
    xo_or_none(board[2].back());
    std::cout << std::endl;
    std::cout << "     " << "|" << "     " << "|" << "     " << std::endl;
}

int winCon() //check if either player won
{
    int winner = 0;
    for(int i = 0; i < board.size(); i++) //check columns
    {
        double mean = 0.0;
        for(int j = 0; j < board[0].size(); j++)
            mean += board[i][j];
        if(mean / board.size() == 1.0)
            winner = 1;
        else if(mean / board.size() == 2.0)
            winner = 2;
        else
            mean = 0.0;
    }
    for(int i = 0; i < board.size(); i++) //check rows
    {
        double mean = 0.0;
        for(int j = 0; j < board[0].size(); j++)
            mean += board[j][i];
        if(mean / board.size() == 1.0)
            winner = 1;
        else if(mean / board.size() == 2.0)
            winner = 2;
        else
            mean = 0.0;
    }
    double mean1 = 0.0;
    double mean2 = 0.0;
    int j = 2;
    for(int i = 0; i < board.size(); i++) //check diagonals
    {
        mean1 += board[i][i];
        mean2 += board[i][j];
        j--;
    }
    if(mean1 / board.size() == 1.0 || mean2 / board.size() == 1.0)
        winner = 1;
    else if(mean1 / board.size() == 2.0 || mean2 / board.size() == 2.0)
        winner = 2;
    else
    {
        mean1 = 0.0;
        mean2 = 0.0;
    }
    if(winner == 1)
        return 1;
    else if(winner == 2)
        return 2;
    return 0;
}

int main()
{
    int pmove;
    int player = 2;
    char pSymbol = 'O';
    bool gameStart = false;
    int winner = 0;
    int legalMove = 0; //0 is true (it should be backwards or a bool i know)
    int iterations = 1;
    
    do
    {
        std::cout << "Player 1 (X) select a number to begin" << std::endl;
        boardDefault();
        boardRead();
        do
        {
            std::cin >> pmove;
            if(pmove > 0 && pmove < 10)
            {
                playerChoice(pmove, 1);
                boardRead();
                gameStart = true;
            }
            else
                    std::cout << "Invalid selection, try again: ";
        } while(gameStart == false);

        while(gameStart == true)
        {
            std::cout << "Player " << player << " (" << pSymbol << "), your turn: ";
            std::cin >> pmove;
            legalMove = playerChoice(pmove, player);
            if(legalMove == 0)
            {
                boardRead();
                winner = winCon();
                iterations++;
                if(player == 2)
                {
                    player = 1;
                    pSymbol = 'X';
                }
                else if(player == 1)
                {
                    player = 2;
                    pSymbol = 'O';
                }
            }
            else
                std::cout << "Invalid selection, try again: ";
            if(winner != 0)
            {
                std::cout << "Player " << winner << " wins" << std::endl;
                break;
            }
            else if(iterations == 9)
            {
                std::cout << "Tie game, no winner" << std::endl;
                break;
            }

        }
        char again;
        std::cout << "Press + to play again, press any other key to exit: ";
        std::cin >> again;
        if(again == '+')
            gameStart = false;
        else
            std::cout << "Goodbye";
            break;
    } while(gameStart == false);
}
//std::cout << "TEST VALUE " << << std::endl;