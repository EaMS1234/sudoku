// Functions containing the logic for the game

#include <stdlib.h>
#include <time.h>

void fill_table(int table[9][9], int difficulty);
int solve(int table[9][9], int x, int y);
int valid(int table[9][9], int x, int y);

// Generates a valid sudoku board. Not optimal, but it works well enough
void fill_table(int table[9][9], int difficulty)
{
    int x, y, n;

    srand(time(NULL));

    // First step: generate an empty board
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            table[i][j] = 0;
        }
    }

    // Second step: generate random numbers
    for (int i = 0; i < 9; i++)
    {
        table[rand() % 3][rand() % 3] = i + 1;
        table[rand() % 3 + 3][rand() % 3 + 3] = i + 1;
        table[rand() % 3 + 6][rand() % 3 + 6] = i + 1;
    }

    // Third step: generate a valid final state
    solve(table, 0, 0);

    // Fourth step: generate a random pattern of empty numbers
    n = 0;
    while (n < difficulty)
    {
        x = rand() % 9;
        y = rand() % 9;

        if (table[x][y] != 0)
        {
            n++;
            table[x][y] = 0;
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

    if (table[x][y] == 0)
    {
        for (int i = 1; i <= 9; i++)
        {
            table[x][y] = i;
            
            // Either the last number is valid, or the next iterations are all valid
            if ((x == 8 && y == 8 && valid(table, x, y)) || (valid(table, x, y) && solve(table, x_next, y_next)))
            {
                return 1;
            }
        }

        table[x][y] = 0;  // Nullifies the current number in case no option is valid
        return 0;         // Returns false
    }
    else
    {
        // Assumes every number that is already present in the table to be valid

        if (x == 8 && y == 8 || solve(table, x_next, y_next))
        {
            return 1;
        }
    }

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
