// Functions containing the logic for the game

void fill_table(int table[9][9]);
void solve(int table[9][9]);

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

// TODO: backtracking algorithm for solving the board
void solve(int table[9][9])
{

}
