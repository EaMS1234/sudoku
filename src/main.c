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

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        if (IsCursorHidden())
        {
            // TODO: use arrow keys to navigate the game

            // Goes back to "mouse mode"
            if (GetMouseDelta().x != 0 && GetMouseDelta().y != 0)
            {
                ShowCursor();
            }
        }
        else
        {
            // TODO: if a key is used, it should disable the mouse input
            if(IsKeyDown(KEY_SPACE))
            {
                HideCursor();
            }
        }

        draw_board(sudoku_table);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
