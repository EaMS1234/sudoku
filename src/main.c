#include "raylib.h"
#include "board/board.h"
#include "sudoku/sudoku.h"

int main()
{
    InitWindow(490, 490, "Sudoku");
    SetTargetFPS(60);

    int sudoku_table[9][9];  // represents the number in each position of the board
    int initial_state[9][9];

    int solvable = 1;  // Assumes every initial state is solvable

    // Initializes the table
    fill_table(sudoku_table, 45);

    // Copies the initial state to its own array
    for (int i = 0 ; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            initial_state[i][j] = 0 + sudoku_table[i][j];
        }
    }

    // Origin of the table
    Vector2 origin = {.x = 42, .y = 42};

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        draw_board(sudoku_table, initial_state, origin);

        // TODO: remove the testing options ===================================
        if (!solvable)
        {
            DrawText("Could not find a valid solution for the current state!", 10, 450, 16, RED);
        }

        DrawText("(F1) Solve", 10, 10, 16, DARKGRAY);
        DrawText("(F2) Clear", 10, 26, 16, DARKGRAY);
        DrawText("(F3) New game", 10, 42, 16, DARKGRAY);

        if (IsKeyPressed(KEY_F1))
        {
            solvable = solve(sudoku_table, 0, 0);
        }

        if (IsKeyPressed(KEY_F2))
        {
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    sudoku_table[i][j] = 0 + initial_state[i][j];
                }
            }
        }

        if (IsKeyPressed(KEY_F3))
        {
            fill_table(sudoku_table, 45);
            for (int i = 0 ; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    initial_state[i][j] = 0 + sudoku_table[i][j];
                }
            }
        }
        // ====================================================================

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
