#include <iostream>
#include <cstdlib>
#define reset "\033[0m"
#define red "\033[31m"
#define blue "\033[34m"
#define green "\033[32m"

using namespace std;

class TicTacToe
{
public:
    TicTacToe();     // Constructor
    void playgame(); // Starts game
private:
    int board[3][3];     // Tictactoe array
    int playerturn;      // Variable to switch players
    void displayBoard(); // Prints out board
    void clearBoard();   // Clears board
    int checkwin();      // Checks if someone won
    void putMark();      // Puts value on matrix
    bool checkdraw();    // Checks for draw
    bool getWinner();    // Displays winners
};

TicTacToe::TicTacToe() // Creates a clear board full of 0s
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            board[i][j] = 0;
    }
    playerturn = 1; // Sets first player to 1 or X
}

void TicTacToe::clearBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            board[i][j] = 0; // Sets board to 0
    }
}

void TicTacToe::playgame() // Method to play game
{
    while (1)
    {
        system("cls");   // Clears system output to look better
        displayBoard();  // Calls to displayBoard, which prints boards
        putMark();       // Calls to putMark, allows player to put mark
        if (getWinner()) // Calls to getWinner, stops loop if someone won
            break;
    }
    cout << endl;
}

void TicTacToe::displayBoard() // Method to display board
{
    if (playerturn == 1)
    {
        cout << red << "Player X's turn" << endl
             << endl
             << reset;
    }
    else
    {
        cout << blue << "Player O's turn" << endl
             << endl
             << reset;
    }
    cout << "     1   2   3" << endl;
    cout << "   +---+---+---+" << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << " " << i + 1 << " ";
        cout << "|";
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == 1) // If matrix index equals 1 or X displays X
            {
                cout << red << " X ";
                if (j == 2)
                    continue;
                cout << reset << "|";
            }
            else if (board[i][j] == 2) // If matrix index equals 2 or O displays O
            {
                cout << blue << " O ";
                if (j == 2)
                    continue;
                cout << reset << "|";
            }
            else
            {
                cout << " "; // If matrix isn't 1 or 2 displays nothing
                if (j == 2)
                    continue;
                cout << reset << "  |";
            }
        }
        if (board[i][2] != 0)
        {
            cout << reset << "|" << endl;
        }
        else
        {
            cout << reset << "  |" << endl;
        }
        cout << "   +---+---+---+" << endl;
    }
    cout << endl;
}

void TicTacToe::putMark() // Method to put mark
{
    int row, col;
    bool correctmove = false;
    cout << endl
         << endl
         << reset << "Make your Move" << endl;
    while (correctmove == false)
    {
        cout << reset << "Enter Row (1-3): ";
        cin >> row;
        row -= 1;
        cout << "Enter Col (1-3): ";
        cin >> col; // Takes in row and col values
        col -= 1;
        if ((row < 3 && row >= 0) && (col >= 0 && col < 3))
        {
            if (board[row][col] == 0)
            {
                board[row][col] = playerturn;
                correctmove = true;
                playerturn++;
            }
            else if (board[row][col] != 0)
            {
                correctmove = false;
            }
            if (playerturn > 2)
                playerturn = 1;
        }
        if (!correctmove)
            cout << green << "Wrong Input, please enter again" << endl;
    }
}

bool TicTacToe::getWinner() // Method to get winner
{
    int check = checkwin(); // Simply calls checks win and displays based on cases
    switch (check)
    {
    case 1:
        system("cls");
        displayBoard();
        cout << endl
             << endl
             << red << "Player X Won";
        return true;
    case 2:
        system("cls");
        displayBoard();
        cout << endl
             << endl
             << blue << "Player O Won";
        return true;
    case -1:
        if (checkdraw())
        {
            system("cls");
            displayBoard();
            cout << endl
                 << endl
                 << green << "Match Draw";
            return true;
        }
        break;
    }
    return false;
}

int TicTacToe::checkwin() // Method to check win
{
    for (int player = 1; player < 3; player++)
    {
        for (int i = 0; i < 3; i++)
        {
            if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
                return player;
            if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
                return player; // Tests verticals, and horizontals
        }
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
            return player;
        if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
            return player; // Tests diagonals
    }
    return -1;
}

bool TicTacToe::checkdraw() // Method to check draw
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == 0)
                return false;
        }
    }
    return true;
}

int main()
{
    TicTacToe game;  // Creates an object game
    game.playgame(); // Uses game to play game
    system("pause");
    return 0;
}
