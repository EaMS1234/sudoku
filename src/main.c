#include "raylib.h"
#include "board/board.h"
#include "sudoku/sudoku.h"

int main()
{
    InitWindow(490, 490, "Sudoku");
    SetTargetFPS(60);

    int sudoku_table[9][9];  // represents the number in each position of the board

    // Initializes the table
    fill_table(sudoku_table);

    // Origin of the table
    Vector2 origin = {.x = 42, .y = 42};

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        draw_board(sudoku_table, origin);

        DrawText("(F1) Solve from current state", 10, 10, 16, DARKGRAY);

        if (IsKeyPressed(KEY_F1))
        {
            solve(sudoku_table);
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
