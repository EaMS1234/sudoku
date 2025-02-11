#include "raylib.h"
#include "board/board.c"

int main()
{
    InitWindow(490, 490, "Sudoku");
    SetTargetFPS(60);

    int sudoku_table[9][9];  // represents the number in each position of the board

    // Initializes the table with zeroes
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            sudoku_table[i][j] = 0;
        }
    }

    // Origin of the table
    Vector2 origin = {.x = 42, .y = 42};

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        draw_board(sudoku_table, origin);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
