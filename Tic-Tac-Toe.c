#include <stdio.h>
#include <stdlib.h>
#define RSIZE 3
#define _CRT_SECURE_NO_WARNINGS

void DisplayBoard(int board[RSIZE][RSIZE])
{
    printf("     1   2   3\n");
    printf("   +---+---+---+\n");

    for (int row = 0; row < RSIZE; ++row)
    {
        printf(" %d ", row + 1);
        for (int col = 0; col < RSIZE; ++col)
        {
            if (board[row][col] == 1) // Player O
            {
                printf("|");
                printf("\033[34m O \033[37m");
            }
            else if (board[row][col] == 2) // Player X
            {
                printf("|");
                printf("\033[31m X \033[37m");
            }
            else
            {
                printf("|   ");
            }
        }
        printf("|\n");
        printf("   +---+---+---+\n");
    }
}

void ClearBoard(int board[RSIZE][RSIZE])
{
    for (int row = 0; row < RSIZE; row++)
    {
        for (int col = 0; col < RSIZE; col++)
        {
            board[row][col] = 0;
        }
    }
}

int GetWinner(int board[RSIZE][RSIZE])
{
    for (int player = 1; player <= 2; ++player)
    {
        for (int i = 0; i < RSIZE; ++i)
        {
            // Check rows and columns
            if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
                (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            {
                return player;
            }
        }
        // Check diagonals
        if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
            (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        {
            return player;
        }
    }
    return 0;
}

void PutMark(int board[RSIZE][RSIZE], int *turn, int i, int j)
{
    if (board[i - 1][j - 1] == 0)
    {
        board[i - 1][j - 1] = (*turn % 2 == 0) ? 1 : 2;
        (*turn)++;
    }
    else
    {
        printf("\033[32mWrong Input, please enter again.\033[37m\n");
    }
}

int main()
{
    int board[RSIZE][RSIZE] = {0};
    int turn = 0;
    int i, j, winner = 0;

    ClearBoard(board); // Initialize board

    while (winner == 0 && turn < 9)
    {
        DisplayBoard(board);
        printf("Player %c, enter row (1-3): ", (turn % 2 == 0) ? 'O' : 'X');
        scanf_s("%d", &i);

        while (i < 1 || i > 3)
        {
            printf("\033[32mInvalid row, please enter again: \033[37m");
            scanf_s("%d", &i);
        }

        printf("Enter column (1-3): ");
        scanf_s("%d", &j);

        while (j < 1 || j > 3)
        {
            printf("\033[32mInvalid column, please enter again: \033[37m");
            scanf_s("%d", &j);
        }

        PutMark(board, &turn, i, j);
        winner = GetWinner(board);
    }

    DisplayBoard(board);

    if (winner == 1)
    {
        printf("\033[34mPlayer O Wins!\033[37m\n");
    }
    else if (winner == 2)
    {
        printf("\033[31mPlayer X Wins!\033[37m\n");
    }
    else
    {
        printf("\033[32mIt's a draw!\033[37m\n");
    }

    return 0;
}
