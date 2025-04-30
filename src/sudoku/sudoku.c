#include <stdio.h>

// Functions containing the logic for the game

void fill_table(int table[9][9]);
int solve(int table[9][9], int x, int y);
int valid(int table[9][9], int x, int y);

// TODO: generate a valid sudoku board
void fill_table(int table[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            table[i][j] = 0;
        }
    }
}

// Backtracking algorithm for solving the board
int solve(int table[9][9], int x, int y)
{
    int x_next = x + 1;
    int y_next = y;

    if (x_next == 9)
    {
        y_next++;
        x_next = 0;
    }

    for (int i = 1; i <= 9; i++)
    {
        table[x][y] = i;
        
        // Either the last number is valid, or the next iterations are all valid
        if ((x == 8 && y == 8 && valid(table, x, y)) || (valid(table, x, y) && solve(table, x_next, y_next)))
        {
            return 1;
        }
    }

    table[x][y] = 0;
    return 0;
}

// Checks if a number in a given position is valid
int valid(int table[9][9], int x, int y)
{
    if (table[x][y] == 0)
    {
        return 0;
    }

    int square[9] = {
        table[(x / 3) * 3][(y / 3) * 3],
        table[(x / 3) * 3][(y / 3) * 3 + 1],
        table[(x / 3) * 3][(y / 3) * 3 + 2],
        table[(x / 3) * 3 + 1][(y / 3) * 3],
        table[(x / 3) * 3 + 1][(y / 3) * 3 + 1],
        table[(x / 3) * 3 + 1][(y / 3) * 3 + 2],
        table[(x / 3) * 3 + 2][(y / 3) * 3],
        table[(x / 3) * 3 + 2][(y / 3) * 3 + 1],
        table[(x / 3) * 3 + 2][(y / 3) * 3 + 2]
    };

    int occurences = 0;

    for (int i = 0; i < 9; i++)
    {
        // Same number repeats at least once on the same line
        if (i != x && table[i][y] == table[x][y])
        {
            return 0;
        }

        // Same number repeats at least once on the same row
        if (i != y && table[x][i] == table[x][y])
        {
            return 0;
        }

        if (square[i] == table[x][y])
        {
            if (occurences != 0)
            {
                return 0;
            }

            occurences++;
        }
    }
    
    // The number is valid
    return 1;
}
